#include <xOC01.h>
#include <xCore.h>

xOC01 OC01;

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    OC01.begin();
}

void loop()
{
    Serial.println(OC01.digitalRead());
    delay(300);
}