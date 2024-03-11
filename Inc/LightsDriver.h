//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"

// TODO: Create getters and setters to access data
flag_status_t getLeftTurnStatus();
void setLeftTurnStatus(flag_status_t status);
void setLightsStatus(uint32_t lights);


#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
