#include <MMA8452Q.h>


// Initializes accelerometer
// returns 1 if successful else 0
uint8_t initMMA8452Q(uint8_t addr, MMA8452Q_Scale scale, MMA8452Q_Data_Rate rate){

	// verify device identity
	if (readRegister(WHO_AM_I) != 0x2A){
		return 0;
	}

	// switch to standby to change registers
	standby();

	// set the scale and data rate
	setScale(scale);
	setDataRate(rate);

	// set the device to active state and return successfully
	active();
	return 1;
}

// sets the full-scale range of the accelerometers
// possible values for scale are SCALE_2G, SCALE_4G, SCALE_8G
void setScale(MMA8452Q_Scale scale){
	// set the global scale variable (used to calculate measured data)
	SCALE = scale;

	// Must be in standby mode to make changes; change to standby if active
	if (isActive() == 1){
		standby();
	}

	// read config, change scale bits, then re-write register
	uint8_t config = readRegister(XYZ_DATA_CFG);	// read current config
	config &= 0xFC;									// mask out the scale bits
	config |= (scale >> 2);							// 00 = 2G, 01 = 4G, 10 = 8G
	writeRegister(XYZ_DATA_CFG, config);			// write config with new scale

	// return to active state once complete
	active();
}

// sets the data rate
void setDataRate(MMA8452Q_Data_Rate data_rate){
	// Must be in standby mode to make changes; change to standby if active
	if (isActive() == 1){
		standby();
	}

	// read control, change rate bits, then re-write register
	uint8_t control = readRegister(CTRL_REG1);		// read current settings
	control &= 0xC7;								// mask out the data rate bits
	control |= (data_rate << 3);					// shift data rate bits
	writeRegister(CTRL_REG1, control);				// write settings with new data rate

	// return to active state once complete
	active();
}

// sets the MMA8452 to standby mode
void standby(void){
	// clear the active bit of the control register
	uint8_t control = readRegister(CTRL_REG1);
	writeRegister(CTRL_REG1, (control & ~(0x01)));
}

// sets the MMA8452 to active mode
void active(void){
	// set the active bit of the control register
	uint8_t control = readRegister(CTRL_REG1);
	writeRegister(CTRL_REG1, (control | 0x01));
}

// returns 1 if in Active state, otherwise returns 0
uint8_t isActive(void){
	uint8_t currentState = readRegister(SYSMOD);
	currentState &= 0x03;

	// Wake and Sleep are both active SYSMOD states
	if (currentState == SYSMOD_STANDBY)
		return 0;
	return 1;
}

// checks the status of the MMA8452Q to see if new data is available.
// returns 1 if new data is present otherwise 0
uint8_t available(void){
	return (readRegister(STATUS_MMA8452Q) & 0x08) >> 3;
}

// reads calculated acceleration data into global variables: X, Y, Z
void read(void){
	uint8_t rawData[6];
	readRegisters(OUT_X_MSB, rawData, 6);
	short x = ((short)(rawData[0] << 8 | rawData[1])) >> 4;
	short y = ((short)(rawData[2] << 8 | rawData[3])) >> 4;
	short z = ((short)(rawData[4] << 8 | rawData[5])) >> 4;
	X = (float)x / (float)(1 << 11) * (float)(SCALE);
	Y = (float)y / (float)(1 << 11) * (float)(SCALE);
	Z = (float)z / (float)(1 << 11) * (float)(SCALE);
}

// write an array of "len" bytes ("buffer")
void writeRegisters(MMA8452Q_Register reg, uint8_t *buffer, uint16_t len){
	HAL_I2C_Mem_Write(&hi2c1, (MMA8452Q_Address << 1), reg, 1, buffer, len, 10);
}

// write a single byte of data to a register in the MMA8452Q
void writeRegister(MMA8452Q_Register reg, uint8_t data){
	writeRegisters(reg, &data, 1);
}

uint8_t readRegister(MMA8452Q_Register reg){
	uint8_t buffer;
	readRegisters(reg, &buffer, 1);
	return buffer;
}

void readRegisters(MMA8452Q_Register reg, uint8_t *buffer, uint16_t len){
	HAL_I2C_Mem_Read(&hi2c1, (MMA8452Q_Address << 1), reg, 1, buffer, len, 10);
}

// Returns raw X acceleration data
short getRawX(void){
	uint8_t rawData[2];
	readRegisters(OUT_X_MSB, rawData, 2);
	return ((short)(rawData[0] << 8 | rawData[1])) >> 4;
}

// Returns raw Y acceleration data
short getRawY(void){
	uint8_t rawData[2];
	readRegisters(OUT_Y_MSB, rawData, 2);
	return ((short)(rawData[0] << 8 | rawData[1])) >> 4;
}

// Returns raw Z acceleration data
short getRawZ(void){
	uint8_t rawData[2];
	readRegisters(OUT_Z_MSB, rawData, 2);
	return ((short)(rawData[0] << 8 | rawData[1])) >> 4;
}

// Returns calculated X acceleration data
float getX(void){
	short x = getRawX();
	return (float)x / (float)(1 << 11) * (float)(SCALE);
}

// Returns calculated X acceleration data
float getY(void){
	short Y = getRawY();
	return (float)Y / (float)(1 << 11) * (float)(SCALE);
}

// Returns calculated X acceleration data
float getZ(void){
	short z = getRawZ();
	return (float)z / (float)(1 << 11) * (float)(SCALE);
}
