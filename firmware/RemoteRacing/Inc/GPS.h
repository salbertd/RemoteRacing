#ifndef GPS_H_
#define GPS_H_

#include <string.h>
#include "stm32f0xx_hal.h"

#define GPS_RX_BUFFER_SIZE 64
#define GPS_RX_BUFFER_HALF_SIZE GPS_RX_BUFFER_SIZE/2
#define GPS_TX_BUFFER_SIZE GPS_RX_BUFFER_SIZE * 16
#define GPS_TX_BUFFER_LAST_POS GPS_RX_BUFFER_SIZE * 15

#define MAX_PACKET_LENGTH 255
#define GPS_GPRMC_ONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
#define GPS_GPRMC_ONLY_SIZE 51
#define GPS_PQTXT "$PQTXT,W,0,0*22\r\n"
#define GPS_PQTXT_SIZE 17
#define GPS_10HZ "$PMTK220,100*2F\r\n"
#define GPS_10HZ_SIZE 17
#define GPS_BAUD_57600 "$PMTK251,57600*2C\r\n"
#define GPS_BAUD_57600_SIZE 19
#define GPS_UART_TIMEOUT 2000 //milliseconds

uint8_t rxBuffer[GPS_RX_BUFFER_SIZE]; // incoming data buffer to be filled by DMA
uint8_t txBuffer[GPS_TX_BUFFER_SIZE]; // incoming data buffer to be filled by DMA
uint8_t * txBufferInsertIndex;
uint8_t * txBufferReadIndex;
uint8_t * read_params[2];

uint8_t gps_init(UART_HandleTypeDef *GPS_UART);
void gps_recieve_full();
void gps_recieve_half();
uint8_t ** gps_get_data();

#endif
