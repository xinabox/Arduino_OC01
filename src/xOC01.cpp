/*
	This is a library for the OC01 
	BURN WIRE

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	
	* 	PCA9536
	
	Data Sheets:
	PCA9536 - http://www.ti.com/lit/ds/symlink/pca9536.pdf
*/

#include <xOC01.h>

/********************************************************
 	Constructor
*********************************************************/
xOC01::xOC01(){
	pin_state = 0;
}

/********************************************************
 	Configure OC01
*********************************************************/
bool xOC01::begin(void){
	xCore.write8(PCA9536_I2C_ADDRESS, PCA9536_REG_CONFIG, PCA9536_CONF_OUTPUT);
}

/********************************************************
 	Write to PIN
*********************************************************/
void xOC01::write(byte pin, bool state){
	if(pin == 0){
		pin = PCA9536_PIN0;
	}else if(pin == 1){
		pin = PCA9536_PIN1;
	}else if(pin == 2){
		pin = PCA9536_PIN2;
	}else if(pin == 3){
		pin = PCA9536_PIN3;
	}else{
		Serial.println("Invalid Pin Selection");
		return;
	}
	
	pin_state = xCore.read8(PCA9536_I2C_ADDRESS, PCA9536_REG_OUTPUT_PORT);
	if(state == 1){
		pin_state |= (pin_state | (uint8_t)pin);
		xCore.write8(PCA9536_I2C_ADDRESS, PCA9536_REG_OUTPUT_PORT, pin_state);
		Serial.println(pin_state,DEC);
	}else if(state == 0){
		pin_state &= ~(1 << pin_state|pin);
		Serial.println(pin_state,DEC);
		xCore.write8(PCA9536_I2C_ADDRESS, PCA9536_REG_OUTPUT_PORT, pin_state);
	}
}

xOC01 OC01 = xOC01();



