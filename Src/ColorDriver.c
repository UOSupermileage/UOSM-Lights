#include <stdint.h>
#include "ColorDriver.h"
#include <LightsDriver.h>
uint32_t red = 0, green = 0, blue = 0;
uint32_t Red_Freq,Green_Freq,Blue_Freq = MIN_FREQ;
u_int32_t minFreq = MIN_FREQ;
u_int16_t maxFreq = 50;

int goingUpRed = 0;
void tickColor(void) {
    if(red == Red_Freq) {
      setRed(getRed());

      red = 0;
      /*
      if (goingUpRed == 0) {

        Red_Freq++;
        if (Red_Freq >= 100) {
          DebugPrint("GOING DOWN");
          goingUpRed = 1;
        }

      }
      else {
        Red_Freq--;
        if (Red_Freq <= minFreq) {
          goingUpRed = 0;
          DebugPrint("GOING UP");
        }


      }

*/


    }
    if (green == Green_Freq) {
      DebugPrint("Green: " + green);
      setGreen(getGreen());
      green = 0;
    }

    if(blue == Blue_Freq) {
      setBlue(getBlue());
      blue = 0;
    }

    green++;
    red++;
    blue++;
}
//0 -> 255
void changeColorBrightness(uint32_t r, uint32_t g, uint32_t b) { //TODO: Fix flickering
  if (r > 255 || g > 255 || b > 255) {
    DebugPrint("nuh uh");
    return;
  }

  int redPercent = r * maxFreq / 255;
  int greenPercent = g * maxFreq / 255;
  int bluePercent = b * maxFreq / 255;

  setGreen(greenPercent);
  setRed(redPercent);
  setBlue(bluePercent);
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

