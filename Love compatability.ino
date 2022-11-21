
/* Using potentiometer to check the compatibility of two people. 
The people should be blind folded and asked to turn the knob of the potentiometer. Based on the readings it will be a wild determination of compatabaility.
*/

int yLed=2; //yellow led pin
int oLed=6; //orange led pin
int bLed=4; //blue led pin
int sPin1=A1; //analog input pin for the potentiometer 1
int sPin2=A2; //analog input pin for potentiometer 2
int pin1val=0; //initial value of the potentiometer 1
int pin2val=0; //initial value of potentiometer 2
void setup() {
  // put your setup code here, to run once:
 pinMode(yLed, OUTPUT); //yellow led output
 pinMode(oLed, OUTPUT); // orange led output
 pinMode(bLed, OUTPUT); //blue led output
 Serial.begin(9600);
}
void loop() {
  // read the value of the pin and store it
  // this will be in a range of 0-1023
  pin1val  = analogRead(sPin1); // potentiometer reading of first person
  // print the value to the monitor
  Serial.print("Reading 1: ");
  Serial.println(pin1val);

   pin2val = analogRead(sPin2); // potentiometer reading of second person
  // print the value to the monitor
  Serial.print("Reading 2: ");
  Serial.println(pin2val);


  // tried using map value but it got unnecessarily complicated so discarded
  // map the value to the range of analogOut
  // // store that in a new variable
  // int yledVal = map(per1Val, 0, 1023, 0, 100);
  // int bledVal = map(per2Val, 0, 1023, 0, 100);
  // // print the value to the monitor
  // Serial.print("mapped value: ");
  // Serial.println(yledVal, bledVal);  

  // // write the value to the LED
  // analogWrite(yLed, yledVal);
  // analogWrite(bLed, bledVal);
 
 
//  if(pin1val >500 && pin2val > 500){
//    Serial.println("Compatible");
//    digitalWrite(oLed, HIGH);
//    digitalWrite(yLed, LOW);
//    digitalWrite(bLed, LOW);
//  }
   
if ((pin1val > 700) && (pin1val < 800) && (pin2val > 700) && (pin2val < 800)){
   Serial.println("Compatible");
   digitalWrite(oLed, HIGH); // if falls in the specific range Compatible is printed out and the orange led glows
   digitalWrite(bLed, LOW);
   digitalWrite(yLed, LOW);
 }
 else if((pin1val < 500 || pin2val < 500) && (pin1val > 200 || pin2val > 200)){
   Serial.println("Infatuation");
   digitalWrite(oLed, LOW);
   digitalWrite(yLed, HIGH); // if falls in the specific range Infatuation is printed out and the yellow led glow
   digitalWrite(bLed, LOW);

}
else if (pin1val < 200 || pin2val < 200){
   Serial.println(" Incompatible ");
   digitalWrite(oLed, LOW);
   digitalWrite(bLed, HIGH); // if falls in the specific range Uncompatible is printed out and the blue led glow
   digitalWrite(yLed, LOW);
 }

   delay(700);
}

