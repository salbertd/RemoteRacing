#ifndef RACING_TASKS_H_
#define RACING_TASKS_H_

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "MMA8452Q.h"
#include "LEDs.h"
#include "LCD.h"
#include "GPS.h"
#include "BLE.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

void RTOS_INIT();
void RTOS_INIT_TASKS();

SemaphoreHandle_t ble_receive_ready;
xTaskHandle task_send_ble_packet_handle;
xTaskHandle task_receive_ble_packet_handle;
void task_send_ble_packet();
void task_receive_ble_packet();
float gps_get_time();
float convert_time(uint8_t * time_in);

ble_data_packet_tx_t ble_tx_packet;
extern uint8_t txBuffer[GPS_TX_BUFFER_SIZE];

typedef struct racer{
	char name[19];
	char is_you;
} racer_t;

void print_race_end_all(racer_t* racers, uint8_t num_racers);
racer_t RESULTS[6];

char POSITION[3];
uint8_t DIST_FRACTION_SIZE;
char DIST_FRACTION[20];
racer_t RACERS[6];
float START_TIME;
float FINISH_TIME;

#endif
