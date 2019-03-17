#include <ESP8266WiFi.h>

void setup()
{
Serial.begin(115200);
Serial.println();

//disconnect any previous connections
WiFi.disconnect();
delay(1000);

//scan for number of nearby networks & print SSIDs

Serial.print("Nearby networks found  :");
Serial.println(WiFi.scanNetworks());
delay(500);

Serial.println("List of surrounding Network SSIDs…:");
int n = WiFi.scanNetworks();
for (int i = 0; i < n; i++)
{
Serial.println(WiFi.SSID(i));
}
Serial.println();

//connect to preferred SSID

WiFi.begin("ssid", "password");

Serial.println("Connecting");
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println();

// print SSID name,local IP allotted ,MAC address & signal strength

Serial.println();
Serial.print("Connected to SSID          : ");
Serial.println(WiFi.SSID());

Serial.print("IP address allotted to ESP : ");
Serial.println(WiFi.localIP());

Serial.print("MAC Address of ESP         : ");
Serial.println(WiFi.macAddress());

Serial.print("Signal strength is         : ");
Serial.println(WiFi.RSSI());

}

void loop()
{
}
