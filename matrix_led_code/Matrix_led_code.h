#include <PxMatrix.h>

/*
      HOW TO CONNECT
         _______
        |       |
    13 -|R1   G1|- R2
    G2 -|B1  GND|- GND
    R1 -|R2   G2|- G1
    B1 -|B2  GND|- GND
         ]      |
    19 -| A    B|- 23
       -|-Empty-|-
    14 -|CLK LAT|- 22
    16 -| OE GND|- GND
        |_______|
*/

// PIN number is GPIO
#define P_LAT         22
#define P_A           19
#define P_B           23
#define P_C           18
#define P_OE          16
#define PANEL_WIDTH   32
#define PANEL_HEIGHT  16
// This defines the 'on' time of the display is us. The larger this number,
// the brighter the display. If too large the ESP will crash
#define display_draw_time 60 //30-70 is usually fine
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

PxMATRIX display(PANEL_WIDTH, PANEL_HEIGHT, P_LAT, P_OE, P_A, P_B, P_C);

void IRAM_ATTR display_updater()
{
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  display.display(display_draw_time);
  portEXIT_CRITICAL_ISR(&timerMux);
}