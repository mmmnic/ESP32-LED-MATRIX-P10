#include "Matrix_led_code.h"

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
