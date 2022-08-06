#include <ESP8266WiFi.h>
const char* ssid = "azralPhone";
const char* password = "azral123";

void setup() {
  Serial.begin(115200);
  delay(10);

  connectWifi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED)
    connectWifi();
}

void connectWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int resetCount = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    resetCount++;
    if (resetCount > 10) {
      ESP.restart();
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}