#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#define OTETHERNET
#include <ArduinoOTA.h>

#include "BoardReboot.h"

$ { include - component }

#define NAME_ARDUINO "${board-name}"
#define MQTT_USERNAME "${mqtt-user}"
#define MQTT_PASSWORD "${mqtt-password}"

#define VERSION "${version}"

#define OTA_PASSWORD "${ota-password}"

#define DIGITALBOUNCE \
  $ { digital - bounce }

void (*Reboot)(void) = 0;

byte mac[] = {${mac - address}};
long lastReconnectAttempt = 0;
IPAddress server(${mqtt - server});
EthernetClient ethClient;
PubSubClient client(ethClient);
BoardReboot boardReboot;

$ { declaration - component }

void setup()
{
  ${init}

  boardReboot = BoardReboot(&client, NOME_ARDUINO);
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
    client.publish(VERSION, "${board-name}/version", true);
    boardReboot.reconnected();
    $ { reconnected }
  }
  return client.connected();
}

void callback(char *topic, byte *payload, unsigned int length)
{
  boardReboot.mqttCallback(topic, payload, length);
  $ { callback }
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

  ${input}

  ${run}

  $
  {
    output
  }
}
