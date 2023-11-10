
int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int c2 = 0 ;
int c3 = 0 ;
int ant = 0;
int pastAnt = 0;
int rotation = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), ISR2, RISING);
  attachInterrupt(digitalPinToInterrupt(3), ISR3, RISING);

}

void loop() {
  // read the value from the sensor:
  // sensorValue = analogRead(sensorPin);
  
  // Serial.print(sensorValue );

  // Serial.println(c2);
  // Serial.print("           ");
  // Serial.println(c3);
  // Serial.print("           ");
  Serial.println(ant);
  Serial.print("           ");
  Serial.println(rotation);

  // delay(20);


  if( ( ant != pastAnt) && ( (ant % 4) == 0) && (ant != 0) ){
    pastAnt = ant;
    rotation++;
  }
}

void ISR2(void){
  c2++;

  if(digitalRead(3)){
    ant++;

  }
  else{
    ant--;
  }

}


void ISR3(void){
  c3++;
}



