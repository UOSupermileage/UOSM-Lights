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
//Global setter
void setLightsStatus(uint32_t lights){
    lights_status.all = lights;
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
    
}
//Abstract functions over HAL
void LeftTurnEnabled(){
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_SET);
}
void LeftTurnDisabled(){
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_RESET);
}
void HazardsEnabled(){
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, GPIO_PIN_SET);
}
void HazardsDisabled(){
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, GPIO_PIN_RESET);
}
void RightTurnEnabled(){
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, GPIO_PIN_SET);
}
void RightTurnDisabled(){
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, GPIO_PIN_RESET);
}
#ifdef BRUCE_FRONT_LIGHTS
void HeadlightsEnabled(){
    HAL_GPIO_WritePin(Headlights1_port, Headlights1_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Headlights2_port, Headlights2_pin, GPIO_PIN_SET);
}
void HeadlightsDisabled(){
    HAL_GPIO_WritePin(Headlights1_port, Headlights1_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Headlights2_port, Headlights2_pin, GPIO_PIN_RESET);
}
#endif
#ifdef BRUCE_REAR_LIGHTS
void RunningLightsEnabled(){
    HAL_GPIO_WritePin(RunningLights_port, RunningLights_pin, GPIO_PIN_SET);
}
void BrakeLightsEnabled(){
    HAL_GPIO_WritePin(BrakeLights_port, BrakeLights_pin, GPIO_PIN_SET);
}
void BrakeLightsDisabled(){
    HAL_GPIO_WritePin(BrakeLights_port, BrakeLights_pin, GPIO_PIN_RESET);
}
#endif
