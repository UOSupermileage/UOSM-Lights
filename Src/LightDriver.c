//
// Created by louis on 2024-01-22.
//

//TODO: Hardware functions aliasing

#include "LightsDriver.h"
#include "pins.h"
static volatile brightness_t running_lights_red;
static volatile brightness_t running_lights_green;
static volatile brightness_t running_lights_blue;

static volatile brightness_t brake_lights;
static volatile brightness_t left_turn_lights;
static volatile brightness_t right_turn_lights;
static volatile brightness_t high_beam_lights;
static volatile brightness_t low_beam_lights;

static volatile ms_t turning_lights_frequency;

//States
static lights_status_t lights_status;
static flag_status_t brakes_status;

//Global setter
void setLightsStatus(uint32_t lights){
    lights_status.all = lights;
}
void setBrakesStatus(flag_status_t status){
    brakes_status = status;
}

//Getters
flag_status_t getLeftTurnStatus(){
    return lights_status.left_turn_enabled;
}
flag_status_t getRightTurnStatus(){
    return lights_status.right_turn_enabled;
}
flag_status_t getHeadlightsStatus(){
    return lights_status.headlights_enabled;
}
flag_status_t getHazardsStatus(){
    return lights_status.hazards_enabled;
}
flag_status_t getBrakeLightsStatus(){
    return brakes_status;
}

//Abstract functions over HAL
void setLeftTurn(flag_status_t enabled) {
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setHazards(flag_status_t enabled) {
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setRightTurn(flag_status_t enabled) {
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setHeadlights(flag_status_t enabled) {
#ifdef BRUCE_FRONT_LIGHTS
    HAL_GPIO_WritePin(Headlights1_port, Headlights1_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Headlights2_port, Headlights2_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
#endif
}
void RunningLightsEnabled(flag_status_t enabled){
#ifdef BRUCE_REAR_LIGHTS
    HAL_GPIO_WritePin(RunningLights_port, RunningLights_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
#endif
}
void BrakeLightsEnabled(flag_status_t enabled){
#ifdef BRUCE_REAR_LIGHTS
    HAL_GPIO_WritePin(BrakeLights_port, BrakeLights_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
#endif
}
