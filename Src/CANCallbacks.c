#include "ApplicationTypes.h"

#include "CANMessageLookUpModule.h"
//#include "DataAggregation.h"
#include "InternalCommsModule.h"
#include "CANDriver.h"
#include "LightsDriver.h"

void ErrorDataCallback(iCommsMessage_t *msg) {
    //DebugPrint("ErrorDataCallback! %d", msg->standardMessageID);
}

void EventDataCallback(iCommsMessage_t *msg) {
    //DebugPrint("EventDataCallback! %d", msg->standardMessageID);
    if (msg->dataLength == CANMessageLookUpTable[EVENT_DATA_ID].numberOfBytes) {
        EventCode code = msg->data[1];
        flag_status_t status = msg->data[0];

        DebugPrint("EventDataCallback, received code %d with status %d", msg->data[1], status);
        if(code == BRAKES_ENABLED) {

            if (status == 0) {
                DebugPrint("CAN Brakes Off");
            } else if (status == 1) {
                DebugPrint("CAN Brakes On");
            } else {
                DebugPrint("CAN Brakes Unknown");
            }

            setBrakesStatus(status);

            DebugPrint("Setting brakes: %d", status);
        }
    } else {
        DebugPrint("msg.dataLength does not match lookup table. %d != %d", msg->dataLength, CANMessageLookUpTable[ERROR_DATA_ID].numberOfBytes);
    }
}

void MotorRPMDataCallback(iCommsMessage_t* msg) {
    int32_t rpm = readMsg(msg);
    //DebugPrint("CAN rpm received: %d", rpm);
}

void CurrentVoltageDataCallback(iCommsMessage_t* msg) {

    uint16_pair_t pair = readMsgPairUInt16Bit(msg);

    //DebugPrint("CAN current received: %d", pair.a);
    //DebugPrint("CAN voltage received: %d", pair.b);
}

void SpeedDataCallback(iCommsMessage_t *msg) {
    uint32_t speed = readMsg(msg);
    //DebugPrint("CAN speed received: %d", speed);
}

void ThrottleDataCallback(iCommsMessage_t *msg) { /*DebugPrint("ThrottleDataCallback not implemented! %d", msg->standardMessageID);*/ }
void PressureTemperatureDataCallback(iCommsMessage_t *msg) { /*DebugPrint("PressureTemperatureDataCallback not implemented! %d", msg->standardMessageID);*/ }
void EfficiencyDataCallback(iCommsMessage_t *msg) { /*DebugPrint("EfficiencyDataCallback not implemented! %d", msg->standardMessageID);*/ }
void LightsDataCallback(iCommsMessage_t *msg){
    uint32_t message = readMsg(msg);
    setLightsStatus(message);
    SerialPrintln("Received lights message!");
}