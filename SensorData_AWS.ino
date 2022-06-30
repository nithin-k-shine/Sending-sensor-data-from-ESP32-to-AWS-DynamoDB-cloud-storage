#include "config.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

// The MQTT topics that this device should publish
#define AWS_IOT_PUBLISH_TOPIC   ""

WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(256);

#define BUFFER_LEN 256
long lastMsg = 0;
char msg[BUFFER_LEN];
int value = 0;
byte mac[6];
char mac_Id[18];
float resolution=3.3/1023;

void connectAWS()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  Serial.print("Connecting to AWS IOT");

  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(100);
  }

  if(!client.connected()){
    Serial.println("AWS IoT Timeout!");
    return;
  }

  Serial.println("AWS IoT Connected!");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  connectAWS();
  WiFi.macAddress(mac);
snprintf(mac_Id, sizeof(mac_Id), "%02x:%02x:%02x:%02x:%02x:%02x",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

void loop() {
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    //============================================================================
    String macIdStr = mac_Id;
    float temp = ((analogRead(A0) * resolution) * 100)+27.3-random(0, 2)-random(0, 50)/100;
    String temperature = String(temp)+"C ";
    //String temperature = String(random(0xffff), HEX);
    snprintf (msg, BUFFER_LEN, "{\"MAC_ID\" : \"%s\", \"Temperature\" : \"%s\"}", macIdStr.c_str(), temperature.c_str());
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(AWS_IOT_PUBLISH_TOPIC, msg);
    //=============================================================================
    Serial.print("Heap: "); Serial.println(ESP.getFreeHeap()); //Low heap can cause problems
  }
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(100); // wait for a second
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
  delay(100); // wait for a second
  delay(3000);
}
