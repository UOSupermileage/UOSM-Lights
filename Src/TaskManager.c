//
// Created by louis on 2024-01-22.
// Blink logic from: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
// Due to resource constraints, we are not using FreeRTOS for this project
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "InternalCommsModule.h"
#include "LightsDriver.h"
#include "pins.h"

_Noreturn void RunTaskManager(void) {
    //Initialize MCP
    MCP2515_CS_HIGH();
    DebugPrint("Start!");
    HAL_TIM_PWM_Start();

    // Initialize CAN
    IComms_Init();

    flag_status_t blink;
    uint32_t blink_delay = BLINK_DELAY; //Blink interval in milliseconds

    uint32_t current_time = HAL_GetTick();
    uint32_t previous_time = 0;

    #ifdef FRONT_LIGHTS

    // Move outside of loop :)
    setHeadlights(getHeadlightsStatus() == Set);
    #endif
    while (1) {
        // Check for CAN messages
        IComms_PeriodicReceive();

        // TODO: Actuate Lights based off of state in LightsDriver
        current_time = HAL_GetTick();

        // Code for front lights

            setLeftTurn(getLeftTurnStatus() == Set);
            HAL_Delay(blink_delay);
            //setHazards(getHazardsStatus() == Set && blink == Set);





#ifdef BRUCE_REAR_LIGHTS
        setRunningLights(getBrakeLightsStatus() == Set);
#endif

    }
}