//
// Created by louis on 2024-01-22.
//

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

flag_status_t getHighBeamLightsStatus() {
    // TODO: Make this it's own variable, requires updating UOSM-Core
    return lights_status.low_beams_enabled;
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

///

void GPIO_setLeftTurn(flag_status_t enabled) {
    DebugPrint("Left Turn");
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setHazards(flag_status_t enabled) {
    DebugPrint("Hazard");
    HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setRightTurn(flag_status_t enabled) {
    DebugPrint("Right Turn");
    HAL_GPIO_WritePin(RightTurn_port, RightTurn_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setHighBeams(flag_status_t enabled) {
    DebugPrint("Highbeams");
    HAL_GPIO_WritePin(HeadlightsHigh_port, HeadlightsHigh_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setLowBeams(flag_status_t enabled) {
#ifdef FRONT_LIGHTS
    DebugPrint("Set %d\n", enabled);
    HAL_GPIO_WritePin(HeadlightsLow_port, HeadlightsLow_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
#endif
}
void GPIO_setRunningLights(flag_status_t enabled){
#ifdef REAR_LIGHTS
    HAL_GPIO_WritePin(RunningLights_port, RunningLights_pin, enabled ? GPIO_PIN_RESET : GPIO_PIN_SET);
#endif
}
void GPIO_setBrakeLights(flag_status_t enabled){
#ifdef REAR_LIGHTS
    HAL_GPIO_WritePin(BrakeLights_port, BrakeLights_pin, enabled ? GPIO_PIN_SET : GPIO_PIN_RESET);
#endif
}

void GPIO_setRed(flag_status_t red) {
    HAL_GPIO_WritePin(R_port, R_pin, red ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setGreen(flag_status_t green) {
    HAL_GPIO_WritePin(G_port, G_pin, green ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void GPIO_setBlue(flag_status_t blue) {
    HAL_GPIO_WritePin(B_port, B_pin, blue ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
