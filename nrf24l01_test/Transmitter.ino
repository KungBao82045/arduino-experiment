#include <RF24.h>
#include <nRF24L01.h>
#include <SPI.h>

RF24 radio(7,8); // CNS, CE

const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println("Cant start!");
  } else {
    Serial.println("Its working!");
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();   
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  const int text = 1;
  radio.write(&text, text);
  delay(1000);
  const int text1 = 2;
  radio.write(&text1, text1);
  delay(1000);
}
