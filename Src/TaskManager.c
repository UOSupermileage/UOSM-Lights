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
#include "ColorDriver.h"

_Noreturn void runTaskManager(void) {
    //Initialize MCP
    MCP2515_CS_HIGH();
    DebugPrint("Start!");

    // Initialize CAN
    IComms_Init();

    flag_status_t blink = 0;
    uint32_t blink_delay = BLINK_DELAY; //Blink interval in milliseconds
    uint32_t current_time = HAL_GetTick();
    uint32_t previous_time = 0;



    while (1) {
        current_time = HAL_GetTick();
        IComms_PeriodicReceive();

        GPIO_setLeftTurn(getLeftTurnStatus() ? blink : Clear);
        GPIO_setRightTurn(getRightTurnStatus() ? blink : Clear);
        GPIO_setHazards(getHazardsStatus() ? blink : Clear);

#ifdef FRONT_LIGHTS
        setColor(255, 127, 127);
        tickColor();
        GPIO_setLowBeams(getHeadlightsStatus());
        GPIO_setHighBeams(getHighBeamLightsStatus());
#endif

#ifdef BRUCE_REAR_LIGHTS
        GPIO_setBrakeLights(getBrakeLightsStatus());
#endif
        // Toggle blink global so that all lights blink in unison
        if (current_time - previous_time >= 800) {
            previous_time = current_time;
            if (blink == Set) {
                blink = Clear;
            } else {
                blink = Set;
            }
        }
    }
}