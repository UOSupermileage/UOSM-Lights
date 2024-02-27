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
//        uint8_t message = MCP2515_ReadByte(0x2D); //Ox0C is BFPCTRL register, 0x2D is EFLG
//        DebugPrint("Message : %d",message);
//        uint8_t message2 = MCP2515_ReadByte(0x2D);
//        DebugPrint("Message 2 : %d", message2);
//        uint8_t message = MCP2515_ReadByte(0x00); //Ox0C is BFPCTRL register, 0x2D is EFLG
//        DebugPrint("Message : %d",message);
//        uint8_t message2 = MCP2515_ReadByte(0x01);
//        DebugPrint("Message 2 : %d", message2);
//        uint8_t message3 = MCP2515_ReadByte(0x02);
//        DebugPrint("Message 3 : %d", message3);
//        uint8_t message4 = MCP2515_ReadByte(0x03);
//        DebugPrint("Message 4 : %d", message4);
//        uint8_t message5 = MCP2515_ReadByte(0x04);
//        DebugPrint("Message 5 : %d", message5);
//        uint8_t message7 = MCP2515_ReadByte(0x07);
//        DebugPrint("Message 7 : %d", message7);
//        //CNF 1 : A2
//        uint8_t messageCNF = MCP2515_ReadByte(0xA2);
//        DebugPrint("Message CNF : %d", messageCNF);
        // TODO: Actuate Lights based off of state in LightsDriver
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
        HAL_Delay(10);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    }

}