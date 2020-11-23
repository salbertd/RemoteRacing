#include "racing_tasks.h"

void RTOS_INIT() {
	ble_receive_ready = xSemaphoreCreateBinary();
	vTaskStartScheduler();
}

void RTOS_INIT_TASKS() {
	xTaskCreate(task_send_ble_packet, "send_ble_packet", 256, NULL, 0, task_send_ble_packet_handle);
	xTaskCreate(task_receive_ble_packet, "receive_ble_packet", 256, NULL, 1, task_receive_ble_packet_handle);
}

void task_send_ble_packet() {
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 50;
	xLastWakeTime = xTaskGetTickCount();
	for(;;) {
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
		uint8_t ** gps_read_data = gps_get_data();
        if (gps_read_data[0] != NULL && gps_read_data[1] != NULL) {
        	if ( gps_read_data[1] >  gps_read_data[0]) {
        		unsigned int size = gps_read_data[1] - gps_read_data[0];
        		memcpy(ble_tx_packet.gps_data, gps_read_data[0], size);
        		memset(ble_tx_packet.gps_data + size, 0, GPS_MAX_COMMAND_LENGTH - size);
        	} else {
        		unsigned int size = (txBuffer + GPS_TX_BUFFER_SIZE) - gps_read_data[0];
        		memcpy(ble_tx_packet.gps_data, gps_read_data[0], size);
        		memcpy(ble_tx_packet.gps_data + size, txBuffer, gps_read_data[1] - txBuffer);
        		size += (gps_read_data[1] - txBuffer);
        		memset(ble_tx_packet.gps_data + size, 0, GPS_MAX_COMMAND_LENGTH - size);
        	}
        	ble_tx_packet.imu_data[0] = getX();
        	ble_tx_packet.imu_data[0] = getY();
        	ble_tx_packet.imu_data[0] = getZ();
        	ble_tx_packet.ending[0] = '-';
        	ble_tx_packet.ending[1] = '-';
        	ble_tx_packet.ending[2] = '-';
        	ble_tx_packet.ending[3] = '\r';
        	ble_tx_packet.ending[4] = '\n';

        	ble_send(&huart1, &ble_tx_packet);
        }
	}
}
void task_receive_ble_packet() {
	for(;;) {
		if( xSemaphoreTake(ble_receive_ready, portMAX_DELAY) == pdTRUE ) {
		//xSemaphoreTake(ble_receive_ready, portMAX_DELAY);
		switch((uint8_t)RX_BUFFER.command - 64) {
		case GPS_RIP_2020NOV:
			// display messsage that the GPS has moved onto the next life
			 fillScreen(ILI9341_LIGHTGREY);
			break;
		case IDLE:
			// "use the app to start a race"
			 fillScreen(ILI9341_BLACK);
			break;
		case RACE_START:
			// "put phone down, race starting soon"
			// LED countdown
			// "plz dont die"
			break;
		case POS_UPDATE:
			// current driver position on screen
			// x miles/ total amnt of miles
			break;
		case RACE_END:
			// "Finish!"
			// driver time
			break;
		case RACE_END_ALL:
			// Positions of each racer
			break;
		default:
			break;
		}
	}
	}
}
