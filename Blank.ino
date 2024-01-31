#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#define OTETHERNET
#include <ArduinoOTA.h>

// ##include-component

#define NAME_ARDUINO ""
#define MQTT_USERNAME ""
#define MQTT_PASSWORD ""


#define VERSION "04.00.00"

#define OTA_PASSWORD ""

#define DIGITALBOUNCE 30

void (*Reboot)(void) = 0;

byte mac[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
long lastReconnectAttempt = 0;
IPAddress server(1, 1, 1, 1);
EthernetClient ethClient;
PubSubClient client(ethClient);

// ##declaration-component

void setup()
{
  // ##init

  Ethernet.begin(mac);
  delay(3000);
  client.setServer(server, 1883);
  client.setCallback(callback);

  ArduinoOTA.begin(Ethernet.localIP(), NAME_ARDUINO, OTA_PASSWORD, InternalStorage);
}

boolean reconnect()
{
  if (client.connect(NAME_ARDUINO, MQTT_USERNAME, MQTT_PASSWORD))
  {
    client.publish(VERSION, "FirstFloorG/version", true);
    // ##reconnected
  }
  return client.connected();
}

void callback(char *topic, byte *payload, unsigned int length)
{
  // ##callback
}

void loop()
{
  if (Ethernet.linkStatus() == LinkON) // ethernet connected
  {
    if (!client.connected())
    {
      long now = millis();
      if (now - lastReconnectAttempt > 5000)
      {
        lastReconnectAttempt = now;
        if (reconnect())
          lastReconnectAttempt = 0;
      }
    }
    else
      client.loop();

    ArduinoOTA.poll();
  }

  // ##input

  // ##run

  // ##output
}
