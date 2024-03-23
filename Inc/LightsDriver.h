//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"

// TODO: Create getters and setters to access data
flag_status_t getLeftTurnStatus();
flag_status_t getRightTurnStatus();
flag_status_t getHazardsStatus();
flag_status_t getHeadlightsStatus();
//void setLeftTurnStatus(flag_status_t status);
void setLightsStatus(uint32_t lights);
void LeftTurnEnabled();
void LeftTurnDisabled();
void RightTurnEnabled();
void RightTurnDisabled();
void HazardsEnabled();
void HeadlightsEnabled();
void HeadlightsDisabled();
void HazardsDisabled();

#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
