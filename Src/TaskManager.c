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
    while(1) {
        IComms_PeriodicReceive();
        // TODO: Actuate Lights based off of state in LightsDriver
        if(getLeftTurnStatus() == Set) {
            //Do nothing
            DebugPrint("Turning left");
            HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_SET);
        }else{
            HAL_GPIO_WritePin(LeftTurn_port, LeftTurn_pin, GPIO_PIN_RESET);
        }
    }

}