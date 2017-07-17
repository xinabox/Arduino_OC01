/*************************************************************
	This is an examples for the OC01
	Burn Wire Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/OC01/
	
	This example instructs the OC01 start with with
	specified output ports active.
	
	The sensor communicates over the I2C Bus.

	------------------------TIPS--------------------------
	Change this line to ----->Wire.begin(2,14); for CW01
	
*************************************************************/

/*
	The OC01 Burn Wire Module has 4 output ports.
	These output ports are defined in software as follows to
	match the board output names:
	- OUT0
	- OUT1
	- OUT2
	- OUT3
*/

#include <xOC01.h>
#include <xCore.h>

const int DELAY_TIME = 500;

void setup() {
	// Start the I2C Communication
	Wire.begin();
	
	/* 
		Start the OC01 port expander
	   	The input OUT1 will enable the OUT1 output port
	*/
	OC01.begin(OUT1);
}

void loop() {
	// put your main code here, to run repeatedly:
}
