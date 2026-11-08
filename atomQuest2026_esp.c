
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Water Quality Monitoring"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ==========================================================
// WIFI CONFIGURATION
// ==========================================================

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ==========================================================
// UART2 COMMUNICATION WITH ARDUINO UNO
// ==========================================================

#define RXp2 16
#define TXp2 17

// ==========================================================
// SETUP
// ==========================================================

void setup()
{
  Serial.begin(115200);

  // UART2 communication with Arduino Uno
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  // Prevent long blocking while waiting for newline
  Serial2.setTimeout(100);

  Serial.println("Water Quality Monitoring System");
  Serial.println("ESP32 Slave Started");
  Serial.println("--------------------------------");

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Blynk Connected!");
}

// ==========================================================
// MAIN LOOP
// ==========================================================

void loop()
{
  // Maintain Blynk connection
  Blynk.run();

  // Receive data from Arduino Uno
  if (Serial2.available())
  {
    String receivedData = Serial2.readStringUntil('\n');

    int TDS;
    float TUR, pH, temp, waterLevel;

    int result = sscanf(
      receivedData.c_str(),
      "%d,%f,%f,%f,%f",
      &TDS,
      &TUR,
      &pH,
      &temp,
      &waterLevel
    );

    if (result == 5)
    {
      // ================================================
      // PRINT RECEIVED SENSOR VALUES
      // ================================================

      Serial.println();

      Serial.print("TDS         : ");
      Serial.print(TDS);
      Serial.println(" ppm");

      Serial.print("pH          : ");
      Serial.println(pH, 2);

      Serial.print("Turbidity   : ");
      Serial.print(TUR, 1);
      Serial.println(" %");

      Serial.print("Temperature : ");
      Serial.print(temp, 1);
      Serial.println(" C");

      Serial.print("Water Level : ");
      Serial.print(waterLevel, 1);
      Serial.println(" %");

      Serial.println("--------------------------------");

      // ================================================
      // SEND DATA TO BLYNK GAUGES
      // ================================================

      Blynk.virtualWrite(V0, TDS);

      Blynk.virtualWrite(V1, pH);

      Blynk.virtualWrite(V2, TUR);

      Blynk.virtualWrite(V3, temp);

      Blynk.virtualWrite(V4, waterLevel);
    }
  }
}
