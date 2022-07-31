#include <Servo.h>
#include <Wire.h>

Servo base;

double base_angle=90;
double DELAY_I = 5;



void setup() {
  serial.begin(115200);
   base.attach(8); 
  base.write(base_angle);
  

}

void loop() {
    if(Serial.available() > 0){

}
 String computerText = Serial.readStringUntil(' ');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  
  String command = getValue(computerText, ' ',0);
 if (command == "يمين" ) {
      base.write(base_angle  = 0);
    }
    if (command == "يسار") {
     base.write(base_angle =180);
    }
  Serial.println(command);
  Serial.println("WORKING");
  delay(DELAY_I);
}





String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
