#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "WR3005N3-757E"
#define WLAN_PASS       "70029949"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Tamtap"
#define AIO_KEY         "aio_MsHi36MozTph1o79dOA2hSsaZ4Y5"

const int relay=23;

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe Light = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/light");
void setup() {
  digitalWrite(relay, LOW); 
  Serial.begin(9600);
  delay(10);
  pinMode(relay, OUTPUT);
  Serial.println(); 
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  mqtt.subscribe(&Light);
 
}
void loop() {

  
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
  //digitalWrite(relay, LOW);
  while ((subscription = mqtt.readSubscription(5000))) {




    





   

}

void MQTT_connect() {













  
    
  }
  Serial.println("MQTT Connected!");
}
