#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
#include <Servo.h>
Servo myServo;

RF24 radio(7,8); // CNS, CE
const byte address[6] = "00001";

int angle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  myServo.attach(9);
  angle = map(1023, 0, 1023, 0, 179);
  myServo.write(angle);


  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()) {
    int text;
    radio.read(&text, sizeof(text));
    Serial.print(text);
    if (text == 1) {
      angle = map(850, 0, 1023, 0, 179);
      myServo.write(angle);
      Serial.print(" Writing Pin: HIGH, angle: ");
      Serial.println(angle);
      digitalWrite(2, HIGH);
      delay(2000);
      angle = map(1023, 0, 1023, 0, 179);
      myServo.write(angle);
      digitalWrite(2, LOW);
      Serial.print(" Writing Pin: LOW, angle: ");
      Serial.println(angle);
    }
  }
}
