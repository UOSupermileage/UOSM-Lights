#include "ColorDriver.h"
#include "LightsDriver.h"
uint32_t Red_Freq, Green_Freq, Blue_Freq;
uint16_t maxFreq = 10;

uint16_t pwm_count = 0;

void tickColor(void) {
    pwm_count++;

  if (pwm_count >= maxFreq) {
    pwm_count = 0;
  }

    if (Red_Freq == 0) {
        GPIO_setRed(Clear);
    } else if (pwm_count < Red_Freq) {
      GPIO_setRed(Set);
    } else {
      GPIO_setRed(Clear);
    }

    if (Blue_Freq == 0) {
        GPIO_setBlue(Clear);
    } else if (pwm_count < Blue_Freq) {
    GPIO_setBlue(Set);
  } else {
    GPIO_setBlue(Clear);
  }

if (Green_Freq == 0) {
    GPIO_setGreen(Clear);
} else if (pwm_count < Green_Freq) {
    GPIO_setGreen(Set);
  } else {
    GPIO_setGreen(Clear);
  }
}

//0 -> 255
void setColor(uint32_t r, uint32_t g, uint32_t b) {
  if (r > 255 || g > 255 || b > 255) {
    return;
  }

  int redPercent = r * maxFreq / 255;
  int greenPercent = g * maxFreq / 255;
  int bluePercent = b * maxFreq / 255;

  setBlueFrequency(bluePercent);
  setRedFrequency(redPercent);
  setGreenFrequency(greenPercent);
}


void setBlueFrequency(uint16_t freq) {
  Blue_Freq = freq;
}

void setRedFrequency(uint16_t freq) {
  Red_Freq = freq;
}

void setGreenFrequency(uint16_t freq) {
  Green_Freq = freq;
}

