#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DATA_PIN 34

const char* ssid = "wifirotolo";
const char* password = "00440289324";
const char* topic = "lucasrotolo/temperatura";
float temperatura = 0.0;
uint64_t last = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.println("Conectando al WiFi...");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado!");
  client.setServer("test.mosquitto.org", 1883);
  if (client.connect("esp32-lucasrotolo-248792")) {
    Serial.println("Conectado al broker MQTT!");
  } else {
      Serial.print("Fallo MQTT, error: ");
      Serial.println(client.state());
  }
}

void loop() {
  if (!client.connected()){
    client.connect("esp32-lucasrotolo-248792");
  }
  client.loop();
  if ((millis() - last) >= 5000) {
    float voltaje_mv = (analogRead(DATA_PIN) * 3300.0) / 4095.0;
    temperatura = voltaje_mv / 10;
    last = millis();
    char payload[10];
    dtostrf(temperatura, 4, 2, payload);
    if (client.publish(topic, payload)) {
      Serial.println("Mensaje publicado!");
    } else {
    Serial.println("Error al publicar");
    }
  }
}
