/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(13, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
//    char a[20] = String(results.value, HEX) ;
//    Serial.println(new);
    if(results.value == 4129172055){
      Serial.println("Power on");
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);
      
      digitalWrite(13, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

//4129172055
