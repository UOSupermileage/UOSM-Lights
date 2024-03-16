#include "ApplicationTypes.h"

#include "CANMessageLookUpModule.h"
//#include "DataAggregation.h"
#include "InternalCommsModule.h"
#include "CANDriver.h"
#include "LightsDriver.h"

void ErrorDataCallback(iCommsMessage_t *msg) {
    DebugPrint("ErrorDataCallback! %d", msg->standardMessageID);
}

void EventDataCallback(iCommsMessage_t *msg) {
    DebugPrint("EventDataCallback! %d", msg->standardMessageID);
}

void MotorRPMDataCallback(iCommsMessage_t* msg) {
    int32_t rpm = readMsg(msg);
    DebugPrint("CAN rpm received: %d", rpm);
}

void CurrentVoltageDataCallback(iCommsMessage_t* msg) {

    uint16_pair_t pair = readMsgPairUInt16Bit(msg);

    DebugPrint("CAN current received: %d", pair.a);
    DebugPrint("CAN voltage received: %d", pair.b);
}

void SpeedDataCallback(iCommsMessage_t *msg) {
    uint32_t speed = readMsg(msg);
    DebugPrint("CAN speed received: %d", speed);
}

void ThrottleDataCallback(iCommsMessage_t *msg) { DebugPrint("ThrottleDataCallback not implemented! %d", msg->standardMessageID); }
void PressureDataCallback(iCommsMessage_t *msg) { DebugPrint("PressureDataCallback not implemented! %d", msg->standardMessageID); }
void TemperatureDataCallback(iCommsMessage_t *msg) { DebugPrint("TemperatureDataCallback not implemented! %d", msg->standardMessageID); }
void LightsDataCallback(iCommsMessage_t *msg){
    uint32_t message = readMsg(msg);
    setLightsStatus(message);
    SerialPrintln("Received lights message!");
    SerialPrintln("Left turn status: %d",getLeftTurnStatus());
}