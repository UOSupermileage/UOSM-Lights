#include <sys/cdefs.h>
//
// Created by louis on 2024-01-22.
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "SerialDebugDriver.h"
#include "InternalCommsModule.h"

_Noreturn void RunTaskManager(void){

    SerialPrintln("RTXS");

    MCP2515_CS_HIGH();


//    IComms_Init();
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);

    SerialPrintln("RTXE");

    //Try to generate a PWM output.

    while(1) {
//        IComms_PeriodicReceive();
        // TODO: Actuate Lights based off of state in LightsDriver

    }

}