#include "Matrix_led_code.h"

void draw
void setup() {
  display.begin(4);
  display.setMuxPattern(BINARY);
  display.setScanPattern(ZAGZIG);
  display.setPanelsWidth(2);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &display_updater, true);
  timerAlarmWrite(timer, 4000, true);
  timerAlarmEnable(timer);

  delay(1000);
}

void loop()
{
  /*
  display.drawLine
  display.drawPixel
  */
}


/**************************************************************************/
/*!
   void Adafruit_GFX::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,uint16_t color)
   @brief    Draw a line
    @param    x0  Start point x coordinate
    @param    y0  Start point y coordinate
    @param    x1  End point x coordinate
    @param    y1  End point y coordinate
    @param    color 16-bit 5-6-5 Color to draw with
*/
/**************************************************************************/

/**************************************************************************/
/*!
   void GFXcanvas1::drawPixel(int16_t x, int16_t y, uint16_t color)
   @brief    Draw a pixel to the canvas framebuffer
    @param   x   x coordinate
    @param   y   y coordinate
    @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
