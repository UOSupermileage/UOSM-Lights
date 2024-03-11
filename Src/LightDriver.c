//
// Created by louis on 2024-01-22.
//

#include "LightsDriver.h"

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

flag_status_t getLeftTurnStatus(){
    return lights_status.left_turn_enabled;
}

void setLeftTurnStatus(flag_status_t state){

}