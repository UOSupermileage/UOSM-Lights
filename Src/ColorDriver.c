#include <stdint.h>
#include "ColorDriver.h"
#include <LightsDriver.h>
uint32_t red = 0, green = 0, blue = 0;
uint32_t Red_Freq, Green_Freq, Blue_Freq;
u_int16_t maxFreq = 10;

int goingUpRed = 0;

uint16_t pwm_count = 0;

void tickColor(void) {
    pwm_count++;

  if (pwm_count >= maxFreq) {
    pwm_count = 0;
  }

    if (pwm_count < Red_Freq) {
      setRed(Set);
    } else {
      setRed(Clear);
    }

  if (pwm_count < Blue_Freq) {
    setBlue(Set);
  } else {
    setBlue(Clear);
  }

  if (pwm_count < Green_Freq) {
    setGreen(Set);
  } else {
    setGreen(Clear);
  }


    // green++;
    // red++;
    // blue++;
}
//0 -> 255
void setColor(uint32_t r, uint32_t g, uint32_t b) { //TODO: Fix flickering
  if (r > 255 || g > 255 || b > 255) {
    DebugPrint("nuh uh");
    return;
  }

  int redPercent = r * maxFreq / 255;
  int greenPercent = g * maxFreq / 255;
  int bluePercent = b * maxFreq / 255;




  setBlueFrequency(bluePercent);
  setRedFrequency(redPercent);
  setGreenFrequency(greenPercent);

}


void setBlueFrequency(u_int16_t freq) {
  Blue_Freq = freq;
}

void setRedFrequency(u_int16_t freq) {
  Red_Freq = freq;
}

void setGreenFrequency(u_int16_t freq) {
  Green_Freq = freq;
}

