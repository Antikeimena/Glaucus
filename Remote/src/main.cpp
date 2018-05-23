#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define WIFI_SSID     "SSID"
#define WIFI_PASSWD   "PASSWD"

#define BUILD_VERSION "AntikeimenaRemote-01"

#define MQTT_HOST     "172.22.1.2"
#define MQTT_PORT     1883

WiFiClient        espClient;
PubSubClient      client(espClient);

char  topic[100];
char  msg[100];

void connectToWifi(void){
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = BUILD_VERSION;
    clientId += String(random(0xffff), HEX);
    Serial.println(clientId.c_str());
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup(){

    Serial.begin(9600);

    for(uint8_t t = 5; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(500);
    }

    Serial.print("My version:");
    Serial.println(BUILD_VERSION);
    connectToWifi();
    client.setServer(MQTT_HOST, MQTT_PORT);

}

uint32_t getAnalog(uint8_t port){
  
  uint32_t val = 0;
  
  for(uint8_t i = 0; i < 10; i++){
    val += analogRead(port);
  }

  return (val / 10);
}

void loop(){

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  snprintf (topic, sizeof(topic), "antikeimena/remote/battery");
  snprintf (msg, sizeof(msg), "%ld", getAnalog(A13));
  client.publish(topic, msg);

  snprintf (topic, sizeof(topic), "antikeimena/remote/x");
  snprintf (msg, sizeof(msg), "%ld", getAnalog(34));
  client.publish(topic, msg);

  snprintf (topic, sizeof(topic), "antikeimena/remote/y");
  snprintf (msg, sizeof(msg), "%ld", getAnalog(39));
  client.publish(topic, msg);

  snprintf (topic, sizeof(topic), "antikeimena/remote/button");
  snprintf (msg, sizeof(msg), "%d", getAnalog(36));
  client.publish(topic, msg);

  delay(256);

}
