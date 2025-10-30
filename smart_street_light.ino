/****************************************************
 * Project: Smart Street Light System using ESP32
 * Author: Ritesh Rodge
 * Description:
 * This project automatically controls a street light
 * based on the ambient light level using an LDR sensor.
 * It sends real-time LDR readings to the Blynk IoT app
 * and allows monitoring via the cloud dashboard.
 ****************************************************/

#define BLYNK_TEMPLATE_ID "TMPLXXXXXX"
#define BLYNK_TEMPLATE_NAME "Smart Street Light"
#define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_Token"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

// Pin configuration
#define LDR_SENSOR 34       // LDR connected to GPIO 34 (analog input)
#define STREET_LIGHT 2      // LED connected to GPIO 2 (output)

// Variables
int ldrValue = 0;
int threshold = 500;        // Adjust threshold as needed

BlynkTimer timer;

// Function to read sensor and control light
void smartStreetLight()
{
  ldrValue = analogRead(LDR_SENSOR);  // Read light intensity
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Control logic
  if (ldrValue < threshold)
  {
    digitalWrite(STREET_LIGHT, HIGH);   // Turn ON LED
    Blynk.virtualWrite(V1, "LIGHT ON");
  }
  else
  {
    digitalWrite(STREET_LIGHT, LOW);    // Turn OFF LED
    Blynk.virtualWrite(V1, "LIGHT OFF");
  }

  // Send LDR data to Blynk dashboard
  Blynk.virtualWrite(V0, ldrValue);
}

// Setup function
void setup()
{
  Serial.begin(115200);
  pinMode(STREET_LIGHT, OUTPUT);
  pinMode(LDR_SENSOR, INPUT);

  // Connect to Wi-Fi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connecting to Wi-Fi and Blynk...");

  // Run task every 2 seconds
  timer.setInterval(2000L, smartStreetLight);
}

// Main loop
void loop()
{
  Blynk.run();
  timer.run();
}
