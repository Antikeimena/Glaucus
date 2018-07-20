#include <Arduino.h>

unsigned int flag_A = 0;  //Assign a value to the token bit
unsigned int flag_B = 0;  //Assign a value to the token bit


void interrupt()// Interrupt function
{ char i;
  i = digitalRead( 3);
  if (i == 1)
    flag_A += 1;
  else
    flag_B += 1;
}


void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), interrupt, RISING); //Interrupt trigger mode: RISING

  //pinMode(A5, INPUT);
}

void loop(){
    Serial.print("CCW:  ");
  Serial.println(flag_A);
  Serial.print("CW: ");
  Serial.println(flag_B);
  delay(1000);// Direction judgement

  //if (analogRead(A5) > 1000){
  // Serial.print("0");
  //}else{
  //  Serial.print("1");
  //}
}
