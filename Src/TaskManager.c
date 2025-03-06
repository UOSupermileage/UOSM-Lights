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

_Noreturn void RunTaskManager(void) {
    //Initialize MCP
    MCP2515_CS_HIGH();
    DebugPrint("Start!");

    // Initialize CAN
    IComms_Init();

    flag_status_t blink;
    uint32_t blink_delay = BLINK_DELAY; //Blink interval in milliseconds
    uint32_t current_time = HAL_GetTick();
    uint32_t previous_time = 0;

    #ifdef FRONT_LIGHTS

    // Move outside of loop :)

    #endif
    int blink_counter = 0;

    while (1) {
      //  tickColor();

        setGreen(getGreen());
        setBlue(getBlue());
        setRed(getRed());

            /*
        blink_counter++;

        if (blink_counter == blink_delay) {
            // Add if then conditionals for CAN MESSAGES
            setHighBeams(getHighBeamLightsStatus());
            setRightTurn(getRightTurnStatus());
            setLeftTurn(getLeftTurnStatus());

            blink_counter = 0;
        }
     //   if (
*/


        // Check for CAN maessages
        IComms_PeriodicReceive();

        // TODO: Actuate Lights based off of state in LightsDriver
        current_time = HAL_GetTick();

        // Code for front lights
        // If at this point, blink delay == current time.... Then
        //write on
        //or write off

            //setHazards(getHazardsStatus() == Set && blink == Set);







#ifdef BRUCE_REAR_LIGHTS
        setRunningLights(getBrakeLightsStatus() == Set);
#endif

    }
}