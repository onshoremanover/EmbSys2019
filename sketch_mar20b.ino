#include <Servo.h>
#include <RTCZero.h>


#define pinPWM  13
#define pinCW 12
#define pinCCW  11

#define pinServo 6
#define pinButton 5
#define pinLED  4

#define pinPot A1
#define pinI A2

int pmwOutput = 0;
int power = 0;
int anglePot = 0;
int servopower = 0;
int state = 0;
int motI = 0;
const long interval = 100;
const long interval2 = 500;
unsigned long previousMillis = 0;
int einfach[10] ;
int i = 0, sum = 0, average = 0;

Servo servo;

void press();

void setup() {
  Serial.begin(9600);
  servo.attach(pinServo, 1000, 2000);
  pinMode(pinButton, INPUT);
  pinMode(pinPot, INPUT);
  pinMode(pinCCW, OUTPUT);
  pinMode(pinCW, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinI, INPUT);
  analogReference(AR_EXTERNAL);



  attachInterrupt(digitalPinToInterrupt(pinButton), press, RISING);

}



void loop() {

  if (!state) {
    anglePot = analogRead(pinPot);

    int pwmOutput = map(anglePot, 0, 1023, 0 , 255);

//@@@@@@@@@@@@@@@@@@@@@ MOTOR @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if (anglePot <= 512) {
      digitalWrite(pinCCW, HIGH);
      digitalWrite(pinCW, LOW);
      power = (128 - pwmOutput) * 2;
      analogWrite(pinPWM, power );


    }
    if (anglePot > 512) {
      digitalWrite(pinCCW, LOW);
      digitalWrite(pinCW, HIGH);
      power = (pwmOutput - 128) * 2; //keine Ahnung wieso das so ist
      analogWrite(pinPWM, power);



//@@@@@@@@@@@@@@@@@@@@@@ Ende MOTOR @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@ SERVO @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    }
    einfach[i] = analogRead(pinI);

    float servoI = motI / 3;

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;



      for (i = 0; i < 10; ++i)
      {
        sum += einfach[i];
      }
      if(i==10){
        i=0;
        einfach[i] = analogRead(pinI);
        sum=0;
      }
      average = sum / 10;
      
      servo.write(average);

      Serial.print(motI);
      Serial.println();

    }

//@@@@@@@@@@@@@@@@@@@@@ Ende SERVO @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  }
  analogWrite(pinPWM, 0);
  servo.write(90);
}




void press() {

  Serial.print("Working");
  Serial.println();
  Serial.print(anglePot);
  Serial.println();
  
  state = !state;

  digitalWrite(pinLED, state);


}
