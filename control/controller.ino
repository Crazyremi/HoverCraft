// this program is for controller
#include "RF24.h"
#include <SPI.h>
#include "JoyStickBoard.h"

JoyStickBoard controller(2, 4, 5, 3, A0, A1, 8, 6);
RF24 rfTrns(9, 10); //mosi(11),miso(12),sck(13)
//TODO : monitor SDA(A4) SCL(A5);
const byte addr[] = "1Node";
int controllerData[8] = {0};

void setup() {
  Serial.begin(115200);

  rfTrns.begin();
  rfTrns.setChannel(83);       // 設定頻道編號
  rfTrns.openWritingPipe(addr); // 設定通道位址
  rfTrns.setPALevel(RF24_PA_MAX);   // 設定廣播功率
  rfTrns.setDataRate(RF24_2MBPS); // 設定傳輸速率
  rfTrns.stopListening();
}

void loop() {
  controller.getData(controllerData);
  rfTrns.write(&controllerData, sizeof(controllerData));
}
