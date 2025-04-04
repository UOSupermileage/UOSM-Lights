//
// Created by louis on 2024-01-29.
//

#ifndef UOSM_LIGHTS_PINS_H
#define UOSM_LIGHTS_PINS_H
//#define FRONT_LIGHTS
#define BRUCE_FRONT_LIGHTS
// #define BRUCE_REAR_LIGHTS
#ifdef FRONT_LIGHTS
#define RunningLightsR_port GPIOA
#define RunningLightsR_pin GPIO_PIN_2
#define HeadlightsLow_port GPIOA
#define HeadlightsLow_pin GPIO_PIN_13
#define HeadlightsHigh_port GPIOA
#define HeadlightsHigh_pin GPIO_PIN_14
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_13
#endif
#ifdef REAR_LIGHTS
#endif
#ifdef BRUCE_FRONT_LIGHTS
#define Headlights1_port GPIOA
#define Headlights1_pin GPIO_PIN_1
#define Headlights2_port GPIOA
#define Headlights2_pin GPIO_PIN_14
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_13
#define RightTurn_port GPIOA
#define RightTurn_pin GPIO_PIN_2
#endif
#ifdef BRUCE_REAR_LIGHTS
#define BrakeLights_port GPIOA
#define BrakeLights_pin GPIO_PIN_14
#define RunningLights_port GPIOA
#define RunningLights_pin GPIO_PIN_1
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_13
#define RightTurn_port GPIOA
#define RightTurn_pin GPIO_PIN_2
#endif
#endif //UOSM_LIGHTS_  PINS_H
//RunningLightsR PA2
//RunningLightsR PA2
//HeadlightsLow PA13 - low beams
//HeadlightsHigh PA14 - high beams
//LeftTurn PA0
//TODO: Assign correct lights pins
//