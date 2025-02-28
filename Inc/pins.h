//
// Created by louis on 2024-01-29.
//

#ifndef UOSM_LIGHTS_PINS_H
#define UOSM_LIGHTS_PINS_H
#define REAR_LIGHTS
#define FRONT_LIGHTS
//#define BRUCE_FRONT_LIGHTS
//#define BRUCE_REAR_LIGHTS
#ifdef FRONT_LIGHTS
#define FrontRunningR_port GPIOA
#define FrontRunningR_pin GPIO_PIN_2
#define FrontRunningG_port GPIOA
#define FrontRunningG_pin GPIO_PIN_3
#define FrontRunningB_port GPIOB
#define FrontRunningB_pin GPIO_PIN_1
#define FrontHeadlightsLow_port GPIOA
#define FrontHeadlightsLow_pin GPIO_PIN_13
#define FrontHeadlightsHigh_port GPIOA
#define FrontHeadlightsHigh_pin GPIO_PIN_14
#define FrontLeftTurn_port GPIOA
#define FrontLeftTurn_pin GPIO_PIN_0
#define FrontRightTurn_port GPIOA
#define FrontRightTurn_pin GPIO_PIN_1



#endif
#endif
#ifdef REAR_LIGHTS
#define BrakeLights_port GPIOA
#define BrakeLights_pin GPIO_PIN_3
#define RunningLights_port GPIOA
#define RunningLights_pin GPIO_PIN_1
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_0
#define RightTurn_port GPIOA
#define RightTurn_pin GPIO_PIN_2
#endif
#ifdef BRUCE_FRONT_LIGHTS
#define Headlights1_port GPIOA
#define Headlights1_pin GPIO_PIN_1
#define Headlights2_port GPIOA
#define Headlights2_pin GPIO_PIN_14
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_13
#define RightTurn_port GPIOA
#define RightTurn_pin GPIO_PIN_1
#endif
#ifdef BRUCE_REAR_LIGHTS
#define BrakeLights_port GPIOA
#define BrakeLights_pin GPIO_PIN_3
#define RunningLights_port GPIOA
#define RunningLights_pin GPIO_PIN_1
#define LeftTurn_port GPIOA
#define LeftTurn_pin GPIO_PIN_0
#define RightTurn_port GPIOA
#define RightTurn_pin GPIO_PIN_2
#endif

//RunningLightsR PA2
//RunningLightsR PA2
//HeadlightsLow PA13 - low beams
//HeadlightsHigh PA14 - high beams
//LeftTurn PA0
//TODO: Assign correct lights pins
//