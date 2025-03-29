#include "BlinkTask.h"
#include "LightsDriver.h"


void runBlinkTask(flag_status_t blink) {
    lights_status.right_turn_enabled = Set;
    if (lights_status.left_turn_enabled == Set) {
        setLeftTurn(blink == Set ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }

    if (lights_status.right_turn_enabled == Set) {
        setRightTurn(blink == Set ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }

    if (lights_status.hazards_enabled == Set) {
        setHazards(blink == Set ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}
