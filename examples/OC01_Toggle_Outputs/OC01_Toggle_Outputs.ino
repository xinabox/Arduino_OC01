/*************************************************************
	This is an examples for the OC01
	Burn Wire Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/OC01/
	
	This example in structs the OC01 to turn its output port
	on and off
	
	Currently Supported on the following ☒CHIP:
	- CW01
	- CC01
	- CR01
	
	The sensor communicates over the I2C Bus.

	------------------------TIPS--------------------------
	Comment out this line ----->Wire.pins(2, 14); for support
	on other devices
	
*************************************************************/


/********************* Library Includes *********************/
#include <xOC01.h>
#include <xCore.h>

/********************* SYSTEM VARIABLES *********************/
const int DELAY_TIME = 500;

/*********************** Sketch Code ************************/
void setup() {
	// Start the Serial Monitor
	Serial.begin(115200);
	
	// Set the I2C Pins for the CW01
	Wire.pins(2,14);
	
	// Start the I2C Communication
	Wire.begin();
	
	// Start the OC01 port expander
	OC01.begin();

	Serial.println("OC01 Test");
}

void loop() {
	// Switch OUT0 On
	OC01.write(OUT0, HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT1 On
	OC01.write(OUT1, HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT2 On
	OC01.write(OUT2, HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT3 On
	OC01.write(OUT3, HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT0 off
	OC01.write(OUT0, LOW);
	delay(DELAY_TIME);
	
	// Switch OUT1 off
	OC01.write(OUT1, LOW);
	delay(DELAY_TIME);
	
	// Switch OUT2 off
	OC01.write(OUT2, LOW);
	delay(DELAY_TIME);
	
	// Switch OUT3 off
	OC01.write(OUT3, LOW);
	delay(DELAY_TIME);
}
