#include <sys/cdefs.h>
//
// Created by louis on 2024-01-22.
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "SerialDebugDriver.h"
#include "InternalCommsModule.h"
#include "MCP2515.h"
#include "LightsDriver.h"
#include "pins.h"

_Noreturn void RunTaskManager(void){

    SerialPrintln("Test");
    //Initialize MCP
    MCP2515_CS_HIGH();
    IComms_Init();
    flag_status_t blink;
    uint32_t blink_delay = BLINK_DELAY; //Blink interval in milliseconds
    HAL_GetTick();
    uint32_t current_time = 0;
    uint32_t previous_time = 0;
    //Blink logic from: https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
    while(1) {
        IComms_PeriodicReceive();
        // TODO: Actuate Lights based off of state in LightsDriver
        current_time = HAL_GetTick();
        //Code for front lights
        if(getLeftTurnStatus() == Set && blink == Set) {
            //Do nothing
            DebugPrint("Turning left");
            LeftTurnEnabled();
        }else if (blink == Clear){
            LeftTurnDisabled();
        }
        if(getRightTurnStatus()==Set && blink == Set){
            RightTurnEnabled();
            DebugPrint("Turning right");
        }else if(blink == Clear){
            RightTurnDisabled();
        }
        if(getHazardsStatus() == Set && blink == Set){
            DebugPrint("Hazards on!");
            HazardsEnabled();
        }else if(blink == Clear){
            HazardsDisabled();
        }
#ifdef BRUCE_FRONT_LIGHTS
        if(getHeadlightsStatus() == Set){
            DebugPrint("Headlights on!");
            HeadlightsEnabled();
        }else{
            HeadlightsDisabled();
        }
#endif
#ifdef BRUCE_REAR_LIGHTS
        RunningLightsEnabled();
        if(getBrakeLightsStatus() == Set){
            DebugPrint("Brake lights on!");
            BrakeLightsEnabled();
        }else{
            BrakeLightsDisabled();
            DebugPrint("Brake lights off!");
        }
#endif
        //Update blink flag
        if(current_time - previous_time >= blink_delay){
            previous_time = current_time;
            if(blink == Set){
                blink = Clear;
            } else{
                blink = Set;
            }
        }
    }

}