//
// Created by louis on 2024-01-22.
//

#ifndef UOSM_LIGHTS_LIGHTSDRIVER_H
#define UOSM_LIGHTS_LIGHTSDRIVER_H

#include "ApplicationTypes.h"

// TODO: Create getters and setters to access data

typedef union {
    uint16_t all;
    struct {
        uint16_t hazards_enabled:1;
        uint16_t left_turn_enabled:1;
        uint16_t right_turn_enabled:1;
        uint16_t headlights_enabled:1;
        uint16_t low_beams_enabled:1;
    };
} lights_status_t;

#endif //UOSM_LIGHTS_LIGHTSDRIVER_H
