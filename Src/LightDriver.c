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

    if (lights_status.left_turn_enabled) setLeftTurn(lights_status.left_turn_enabled);
    if (lights_status.right_turn_enabled) setRightTurn(lights_status.right_turn_enabled);
    if (lights_status.headlights_enabled) setHighBeams(lights_status.headlights_enabled);
    if (lights_status.low_beams_enabled) setHeadlights(lights_status.low_beams_enabled);



}
void setBrakesStatus(flag_status_t status){
    brakes_status = status;
}

//Getters
flag_status_t getLeftTurnStatus(){
    return lights_status.left_turn_enabled;
    return HAL_GPIO_ReadPin(FrontLeftTurn_port, FrontLeftTurn_pin) == GPIO_PIN_SET ? Set : Clear;
}

flag_status_t getHighBeamLightsStatus() {
    return HAL_GPIO_ReadPin(FrontHeadlightsHigh_port, FrontHeadlightsHigh_pin) == GPIO_PIN_SET ? Set : Clear;
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

flag_status_t getRed() {
    return HAL_GPIO_ReadPin(FrontRunningR_port, FrontRunningR_pin) == GPIO_PIN_SET ? Set : Clear;
}

flag_status_t getGreen() {
    return HAL_GPIO_ReadPin(FrontRunningG_port, FrontRunningG_pin) == GPIO_PIN_SET ? Set : Clear;
}
flag_status_t getBlue() {
    return HAL_GPIO_ReadPin(FrontRunningB_port, FrontRunningB_pin) == GPIO_PIN_SET ? Set : Clear;
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

void setHighBeams(flag_status_t enabled) {
    DebugPrint("Highbeams");
    HAL_GPIO_WritePin(FrontHeadlightsHigh_port, FrontHeadlightsHigh_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setHeadlights(flag_status_t enabled) {
#ifdef FRONT_LIGHTS

    DebugPrint("Set %d\n", enabled);
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



void setRed(flag_status_t red) {
    HAL_GPIO_WritePin(FrontRunningR_port, FrontRunningR_pin, red ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setGreen(flag_status_t green) {
    HAL_GPIO_WritePin(FrontRunningG_port, FrontRunningG_pin, green ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void setBlue(flag_status_t blue) {
    HAL_GPIO_WritePin(FrontRunningB_port, FrontRunningB_pin, blue ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
