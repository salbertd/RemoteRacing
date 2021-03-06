#ifndef LEDS_H_
#define LEDS_H_

#include <main.h>

typedef enum{
	RED,
	YELLOW,
	GREEN
} LED_Color;


typedef enum{
	ON = 1,
	OFF = 0
} LED_State;

void toggleLED(LED_Color LED);
void setLED(LED_Color LED, LED_State state);

#endif // LEDS_H_
