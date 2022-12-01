#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define PIN1 14
#define PIN2 12
#define DELAY 30

const char *WIFI_SSID = "WIFI in Here";
const char *WIFI_PASSWORD = "PW in here";

const char *MQTT_HOST = "MQTT IP";
const int MQTT_PORT = 1883;
const char *MQTT_CLIENT_ID = "ESP8266-thermostat-NodeMCU";
const char *MQTT_USER = "USER in here";
const char *MQTT_PASSWORD = "PW in here";
const char *TOPIC = "/thermostat";

WiFiClient client;
PubSubClient mqttClient(client);

void callback(char* topic, byte* payload, unsigned int length)
{
    payload[length] = '\0';
    int value = String((char*) payload).toInt();

    Serial.println(topic);
    Serial.println(value);
    Serial.println("START SEQUENCE");
    set_new_temp(value);
    Serial.println(value);
}

void setup()
{
    Serial.begin(9600);
    pinMode(PIN1, OUTPUT);
    pinMode(PIN2, OUTPUT);
    digitalWrite(PIN1, LOW);
    digitalWrite(PIN2, LOW);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected to Wifi");

    mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  
    mqttClient.setCallback(callback);

  
    while (!client.connected()) {
        if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD )) {
            Serial.println("Connected to MQTT ");
        } else {
            delay(500);
            Serial.print(".");
        }
    }

    mqttClient.subscribe(TOPIC);
}
void set_new_temp(float temp) {
  float new_temp = (temp * 2) - 10;
  pulse("-", 60, DELAY);
  pulse("+", new_temp, DELAY);
}

void pulse(char dir[], float qty_pulses, int del) {
  bool pinStatus = digitalRead(PIN1);
  for (int i = 0; i <= qty_pulses; i++) {
    if (pinStatus == LOW) {
      pinStatus = HIGH;
    } else {
      pinStatus = LOW;
    }
    if (dir == "-") {
      digitalWrite(PIN1, pinStatus);
      delay(del);
      digitalWrite(PIN2, pinStatus);
      delay(del);

    } else if (dir == "+") {
      digitalWrite(PIN2, pinStatus);
      delay(del);
      digitalWrite(PIN1, pinStatus);
      delay(del);

    }
  }
}

void loop()
{
    mqttClient.loop();
    
}
