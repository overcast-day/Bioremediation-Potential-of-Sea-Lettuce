/* Photometer Sketch for Lydia and Diana's Science One T2 Project 2021 */
#define photocellPin 0    // the cell are connected to a0
float photocellReading;     // the analog reading from the sensor divider
float darkcellReading;        
#define LEDpin 11       // connect LED to pin 11 (PWM pin)
//measurement controls;
int dt = 1000;  //1000=a second between each measurement
int k = 0;
int iter = 20; //number of loops
 
void setup(void) {  //setup runs only once
 // We'll send debugging information via the Serial monitor
Serial.begin(9600);
darkcellReading = analogRead(photocellPin); //takes light reading w/o light
analogWrite(LEDpin,255); //turns on LED to full brightness
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(dt);//delays about 1 sec between measurements
  photocellReading = analogRead(photocellPin); // returns integer value from 0-1023 
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(photocellReading)) {
    Serial.println(F("Failed to read from photosensor...womp womp"));
    return;
  }
  //print values
  Serial.print(k+1);
  Serial.print(",");
  Serial.print(darkcellReading);
  Serial.print(",");
  Serial.println(photocellReading);
  //exit loop
  if (k==iter) { 
    analogWrite(LEDpin,0); //turns on LED off
    exit(0);
  }  
  k = k + 1;
}
