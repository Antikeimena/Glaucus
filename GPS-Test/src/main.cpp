#include <NMEAGPS.h>
#include <GPSport.h>
#include <Streamers.h>

static NMEAGPS  gps;
static gps_fix  fix;

void setup(){
  Serial.begin(115200);
  Serial3.begin(9600);
}

void loop(){
  while (gps.available(Serial3)) {
    fix = gps.read();
    Serial.print(fix.satellites);
    Serial.print("--");
    Serial.print(fix.dateTime_ms());
    Serial.print("--");
    Serial.print(fix.longitudeL());
    Serial.print("\n");    
  }

}
