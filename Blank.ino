#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

#if !defined(ARDUINO_AVR_UNO)
  #define OTETHERNET
  #include <ArduinoOTA.h>
#endif

#include "secrets.h"
#include "BoardReboot.h"

#define DEBUG 0
#if DEBUG
  #define prt(x) Serial.print(x);
  #define prtln(x) Serial.println(x);
#else 
  #define prt(x)
  #define prtln(x)
#endif

${include-component}

#define NAME_ARDUINO "${board-name}"
#define VERSION "${version}"


#define DIGITALBOUNCE ${digital-bounce}



byte mac[] = {${mac-address}};
unsigned long lastReconnectAttempt = 0;
IPAddress server(${mqtt-server});
EthernetClient ethClient;
PubSubClient client(ethClient);
BoardReboot boardReboot= BoardReboot(&client, NAME_ARDUINO);

${declaration-component}

void setup()
{
  ${init}

  Ethernet.begin(mac);
  delay(3000);
  client.setServer(server, 1883);
  client.setCallback(callback);
#if !defined(ARDUINO_AVR_UNO)
  ArduinoOTA.begin(Ethernet.localIP(), NAME_ARDUINO, OTA_PASSWORD, InternalStorage);
#endif
}

boolean reconnect()
{
  if (client.connect(NAME_ARDUINO, MQTT_USERNAME, MQTT_PASSWORD))
  {
    client.publish("${board-name}/board/current-version",VERSION, true);
    boardReboot.reconnected();
    ${reconnected}
  }
  return client.connected();
}

void callback(char *topic, byte *payload, unsigned int length)
{
  boardReboot.mqttCallback(topic, payload, length);
  ${callback}
}

void loop()
{
  if (Ethernet.linkStatus() == LinkON) // ethernet connected
  {
    if (!client.connected())
    {
      unsigned long now = millis();
      if (now - lastReconnectAttempt > 5000)
      {
        lastReconnectAttempt = now;
        if (reconnect())
          lastReconnectAttempt = 0;
      }
    }
    else
      client.loop();
#if !defined(ARDUINO_AVR_UNO)
    ArduinoOTA.poll();
#endif
  }

  ${input}

  ${run}

  ${output}
}
