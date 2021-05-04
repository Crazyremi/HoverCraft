 //this program is for rcv (hovercraft)
#include "RF24.h"
#include <SPI.h>
#include <Servo.h>
Servo motorBack; //3
Servo motorDown; //5
Servo servoDir; //6

int statusLedPin = 4;

RF24 rfRcv(7, 8); //mosi(11),miso(12),sck(13)
const byte addr[] = "1Node";
const byte pipe = 1;  // 指定通道編號
int controllerData[8] = {0};

void motorInit(Servo servo) {
  Serial.println("start initing");
  servo.write(180);
  delay(2000);
  servo.write(5);
  delay(4000);
  Serial.println("finish initing");
}

void setup() {
  Serial.begin(115200);

  motorBack.attach(3);
  motorDown.attach(5);
  servoDir.attach(6);
  

  pinMode(statusLedPin, OUTPUT);
  digitalWrite(statusLedPin, LOW);

  rfRcv.begin();
  rfRcv.setChannel(83);  // 設定頻道編號
  rfRcv.setPALevel(RF24_PA_MAX);
  rfRcv.setDataRate(RF24_2MBPS);
  rfRcv.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rfRcv.startListening();  // 開始監聽無線廣播

  motorInit(servoDir);
}
void loop() {
  if (rfRcv.available(&pipe)) {
    rfRcv.read(&controllerData, sizeof(controllerData));
    for (int i = 0; i < sizeof(controllerData)/sizeof(int); i++)
    {
      Serial.print(controllerData[i]);
      Serial.print(" ");
    }
    Serial.println();
  }

  int angle = map(controllerData[4],0,1023,0,180);
  servoDir.write(angle);

  int speedForward = map(controllerData[0], 0, 1023, 0, 180);
  motorBack.write(speedForward);

  int floatingPower = 180;
  motorDown.write(floatingPower);

  digitalWrite(statusLedPin, controllerData[7]);
}
