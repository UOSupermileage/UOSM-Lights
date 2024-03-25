//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"
#define BLINK_DELAY 600 //Will blink a bit less than once every half second.

// TODO: Create getters and setters to access data
flag_status_t getLeftTurnStatus();
flag_status_t getRightTurnStatus();
flag_status_t getHazardsStatus();
flag_status_t getHeadlightsStatus();
//void setLeftTurnStatus(flag_status_t status);
void setLightsStatus(uint32_t lights);
void setBrakesStatus();
//Functions for front lights
void LeftTurnEnabled();
void LeftTurnDisabled();
void RightTurnEnabled();
void RightTurnDisabled();
void HazardsEnabled();
void HeadlightsEnabled();
void HeadlightsDisabled();
void HazardsDisabled();
//Functions for brake lights
void RunningLightsEnabled();
void BrakeLightsEnabled();
void BrakeLightsDisabled();
#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
