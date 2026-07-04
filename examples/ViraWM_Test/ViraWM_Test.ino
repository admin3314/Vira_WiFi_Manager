#include <WiFiClient.h>
#include <ViraWM.h>
#include <EEPROM.h>


#define BAUD_RATE 115200
#define Server_Port 80

ESP8266WebServer server(Server_Port);

void setup() {
  EEPROM.begin(512);
  Serial.begin(BAUD_RATE);
  Serial.println();
  delay(100);

  ViraWM wifiManager;
  wifiManager.autoConnect("Vira WiFiManager Configuration");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  

  delay(1000);
  Serial.println("IP address : " + WiFi.localIP().toString() + " ");
  Serial.println();

  server.begin();
  Serial.println("HTTP server started ");

  //wifiManager.clearWiFiProfile(true); //Clear Wifi Profile From Memory

}

void loop() {

 
}