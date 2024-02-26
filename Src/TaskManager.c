#include <sys/cdefs.h>
//
// Created by louis on 2024-01-22.
//

#include "TaskManager.h"
#include "UOSMCoreConfig.h"
#include "SerialDebugDriver.h"
#include "InternalCommsModule.h"
#include "MCP2515.h"

_Noreturn void RunTaskManager(void){

    SerialPrintln("Test");

    MCP2515_CS_HIGH();

    IComms_Init();
    //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
//
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);

    SerialPrintln("RTXE");

    //TODO: Try to generate a PWM output.


    while(1) {
        IComms_PeriodicReceive();
        //HAL_SPI_Transmit();
        //Try to read something
        //MCP2515_ReadByte();
        // TODO: Actuate Lights based off of state in LightsDriver
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    }

}