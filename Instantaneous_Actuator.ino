#include <SoftwareSerial.h>

//SoftwareSerial allows a definable serial for RX and TX
SoftwareSerial TinySerial(2, 1);

//Set output pin
int out = 4;
int in = 3;
char input = '0';
int power = 0;
int button = 0;
int button_mode = 1;

void setup() 
{ 
  //Start listening for Bluetooth data
  TinySerial.begin(9600);
  pinMode(out,OUTPUT);
  pinMode(in, INPUT);
} 

void loop() 
{ 
  //If Bluetooth data is received
  if(TinySerial.available() > 0){
    input = TinySerial.read(); 

    //If '1' then turn on
    if (input == '1') {
      digitalWrite(out,HIGH);
      power = 1;
    } 
    //If '0' then turn off
    else if (input == '0') {
      digitalWrite(out,LOW);
      power = 0;
    }
    //If '0' then turn off
    else if (input == 'r') {
      TinySerial.println(power);
    }

  }

  if(button == LOW) {
    button = digitalRead(in);
    if(button == HIGH) {
      if(power == 0) {
        power = 1;
        digitalWrite(out,HIGH);
      } 
      else if(power == 1) {
        power = 0;
        digitalWrite(out,LOW);
      } 
    }
  }
  else if (button == HIGH) {    
    button = digitalRead(in);
  }

}






