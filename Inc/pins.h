//
// Created by louis on 2024-01-29.
//

#ifndef UOSM_LIGHTS_PINS_H
#define UOSM_LIGHTS_PINS_H
#define FRONT_LIGHTS
#ifdef FRONT_LIGHTS
#define RunningLightsR_port GPIOA
#define RunningLightsR_pin GPIO_PIN_2
#define HeadlightsLow_port GPIOA
#define HeadlightsLow_pin GPIO_PIN_13
#define HeadlightsHigh_port GPIOA
#define HeadlightsHigh_pin GPIO_PIN_14
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_0
#endif
#ifdef REAR_LIGHTS
#define
#endif
#endif //UOSM_LIGHTS_PINS_H
//RunningLightsR PA2
//RunningLightsR PA2
//HeadlightsLow PA13 - low beams
//HeadlightsHigh PA14 - high beams
//LeftTurn PA0
//TODO: Assign correct lights pins