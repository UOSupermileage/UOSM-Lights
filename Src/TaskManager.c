#include <sys/cdefs.h>
//
// Created by louis on 2024-01-22.
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "InternalCommsModule.h"

_Noreturn void RunTaskManager(void){

    MCP2515_CS_HIGH();

//    IComms_Init();

    while(1) {
//        IComms_PeriodicReceive();

        // TODO: Actuate Lights based off of state in LightsDriver
    }

}