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
    return HAL_GPIO_ReadPin(FrontLeftTurn_port, FrontLeftTurn_pin) == GPIO_PIN_SET ? Set : Clear;
}
flag_status_t getRightTurnStatus(){
    return  HAL_GPIO_ReadPin(FrontRightTurn_port, FrontRightTurn_pin) == GPIO_PIN_SET ? Set : Clear;
}
flag_status_t getHeadlightsStatus(){
    return  HAL_GPIO_ReadPin(FrontHeadlightsLow_port, FrontHeadlightsLow_pin) == GPIO_PIN_SET ? Set : Clear;
}
flag_status_t getHazardsStatus(){
    return HAL_GPIO_ReadPin(FrontLeftTurn_port, FrontLeftTurn_pin) == HAL_GPIO_ReadPin(FrontRightTurn_port, FrontRightTurn_pin) ? Set : Clear;
}
flag_status_t getBrakeLightsStatus(){
    return HAL_GPIO_ReadPin(BrakeLights_port, BrakeLights_pin) == GPIO_PIN_SET ? Set : Clear;
}

int16_t getRed() {
    return HAL_GPIO_ReadPin(FrontRunningR_port, FrontRunningR_pin) == GPIO_PIN_SET ? Set : Clear;
}

//Abstract functions over HAL

void setLeftTurn(flag_status_t enabled) {
    DebugPrint("Left Turn");
    HAL_GPIO_WritePin(FrontLeftTurn_port,FrontLeftTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setHazards(flag_status_t enabled) {
    DebugPrint("Hazard");
    HAL_GPIO_WritePin(FrontLeftTurn_port, FrontLeftTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(FrontRightTurn_port, FrontRightTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setRightTurn(flag_status_t enabled) {
    DebugPrint("Right Turn");
    HAL_GPIO_WritePin(FrontRightTurn_port, FrontRightTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setHeadlights(flag_status_t enabled) {
#ifdef FRONT_LIGHTS

    DebugPrint("Set");
    HAL_GPIO_WritePin(FrontHeadlightsLow_port, FrontHeadlightsLow_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);

#endif
}
void RunningLightsEnabled(flag_status_t enabled){
#ifdef REAR_LIGHTS
    HAL_GPIO_WritePin(RunningLights_port, RunningLights_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
#endif
}
void BrakeLightsEnabled(flag_status_t enabled){
#ifdef REAR_LIGHTS
    HAL_GPIO_WritePin(BrakeLights_port, BrakeLights_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
#endif
}

void setRed(int16_t red) {

}
