/*
  Posture Sensor Switch 
  Turns on and off a green light emitting diode(LED) based on the posture of the person sitting on the chair
  

  The circuit:
  - Yellow LED attached from pin 5 to ground through 330 ohm resistor indicating circuit is operational. This is done to assure that
    if the green LED is not functioning on correct prosture, the circuit part of the green led needs attention but the rest of the circuit is functional
  - Green LED attached from pin 4 to ground through 330 ohm resistor to indicate when posture is correct
  - Switch attached to pin 7
 
 */


// constants won't change. They're used here to set pin numbers:
const int gledPin= 4;  // the number of the pushbutton pin
const int yledPin= 5;  // the number of the pushbutton pin
const int switchPin = 7;    // the number of the pin on which switch is connected

// variables will change:
int switchState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pins as an output:
  pinMode(gledPin, OUTPUT);
  pinMode(yledPin, OUTPUT);
  // initialize the switch  as an input:
  pinMode(switchPin, INPUT);
}

void loop() {
  // variable for reading the switch condition as on or off
  switchState = digitalRead(switchPin);

  //check if the switch is pressed (here the back resting correctly in upright position to the chair). If it is, the switchstate is HIGH:
   if (switchState == HIGH) {
   //turn green LED on:
     digitalWrite(gledPin, HIGH);
     Serial.println("Posture CORRECT"); //display message of posture being correct
 
 } 
 else {
//   turn  yellow LED on
    digitalWrite(yledPin, HIGH);
    Serial.println("Posture WRONG"); //display message of posture being wrong
 
   }
  digitalWrite(gledPin, LOW); //turn off green LED if posture incorrect
  
}

