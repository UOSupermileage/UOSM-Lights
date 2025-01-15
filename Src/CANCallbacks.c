#include "ApplicationTypes.h"

#include "CANMessageLookUpModule.h"
#include "CANDriver.h"
#include "LightsDriver.h"

void LightsDataCallback(iCommsMessage_t *msg){
    uint32_t message = readMsg(msg);
    setLightsStatus(message);
}

void EventDataCallback(iCommsMessage_t *msg) {
    if (msg->dataLength == CANMessageLookUpTable[EVENT_DATA_ID].numberOfBytes) {
        EventCode code = msg->data[1];
        flag_status_t status = msg->data[0];

        if(code == BRAKES_ENABLED) {
            setBrakesStatus(status);
        }
    }
}

// Lights doesn't need most of the callbacks
extern void ThrottleDataCallback(iCommsMessage_t *msg){}
extern void ErrorDataCallback(iCommsMessage_t *msg){}
extern void SpeedDataCallback(iCommsMessage_t *msg){}
extern void MotorRPMDataCallback(iCommsMessage_t *msg){}
extern void CurrentVoltageDataCallback(iCommsMessage_t *msg){}
extern void PressureTemperatureDataCallback(iCommsMessage_t *msg){}
extern void EfficiencyDataCallback(iCommsMessage_t *msg){}