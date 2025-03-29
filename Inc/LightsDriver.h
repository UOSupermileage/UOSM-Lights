//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"
#define BLINK_DELAY 10000; //Will blink a bit less than once every half second. (Changed)
#define MIN_FREQ 1;
// TODO: Create getters and setters to access data
//Getters
flag_status_t getLeftTurnStatus();
flag_status_t getRightTurnStatus();
flag_status_t getHazardsStatus();
flag_status_t getHeadlightsStatus();
flag_status_t getBrakeLightsStatus();
flag_status_t getHighBeamLightsStatus();
flag_status_t getRed();
flag_status_t getGreen();
flag_status_t getBlue();
static lights_status_t lights_status;

//Setters
void setLightsStatus(u_int32_t lights);
void setBrakesStatus(flag_status_t);

//Functions for front lights
void setLeftTurn(flag_status_t enabled);
void setRightTurn(flag_status_t enabled);
void setHazards(flag_status_t enabled);
void setHeadlights(flag_status_t enabled);
void setLow(flag_status_t enabled);
void setHighBeams(flag_status_t enabled); //Functions for brake lights
void setRunningLights();
void setBrakeLights();

void setRed(flag_status_t red);
void setGreen(flag_status_t green);
void setBlue(flag_status_t blue);
#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
