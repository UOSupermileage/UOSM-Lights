//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"
#define BLINK_DELAY 10000; //Will blink a bit less than once every half second.

//Getters
flag_status_t getLeftTurnStatus();
flag_status_t getRightTurnStatus();
flag_status_t getHazardsStatus();
flag_status_t getHeadlightsStatus();
flag_status_t getBrakeLightsStatus();
flag_status_t getHighBeamLightsStatus();

//Setters
void setLightsStatus(uint32_t lights);
void setBrakesStatus(flag_status_t);

//Functions for front lights
void GPIO_setLeftTurn(flag_status_t enabled);
void GPIO_setRightTurn(flag_status_t enabled);
void GPIO_setHazards(flag_status_t enabled);
void GPIO_setLowBeams(flag_status_t enabled);
void GPIO_setHighBeams(flag_status_t enabled); //Functions for brake lights
void GPIO_setRunningLights(flag_status_t enabled);
void GPIO_setBrakeLights(flag_status_t enabled);

void GPIO_setRed(flag_status_t red);
void GPIO_setGreen(flag_status_t green);
void GPIO_setBlue(flag_status_t blue);
#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
