// Demo OLED Print - 2017-08-04
// Software : Arduino IDE 1.8.3
// Hardware : ESP8266 Wemos D1 mini with OLED shield

#include <ESP8266WiFi.h>
#include <Wire.h>  // Include Wire if you're using I2C
#include <SFE_MicroOLED.h>

#define PIN_RESET 255  // Disable reset
#define DC_JUMPER   0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

MicroOLED oled (PIN_RESET, DC_JUMPER);  // Example I2C declaration

void setup () {
  WiFi.forceSleepBegin ();  // Wifi modem OFF
  // Initialize the OLED and print the splash screen. 
  oled.begin ();  // Init all of the pins and configure the OLED.
  oled.clear (ALL);  // will clear out the OLED's graphic memory (gets rid of artifacts)
  oled.display ();  // Draw on the display
  delay (2000);
  oled.contrast (0);  // brightness = 0..255 (defaut=143)
  delay (2000);
}

void loop () {
  oled.clear (PAGE);      // will clear the Arduino's display buffer.
  oled.setCursor (0, 0);  // Set cursor to top-left
  oled.println ("Test OLED");
  oled.println ("0123456789");
  oled.println ("ABCDEFGHIJ");
  oled.println ("22.5" "\xF8" "C 60%");  // "\xF8" = degree symbol (cp437) = ((char)248)
  oled.print   ("Bat:3.295V\nSec:");
  oled.print   (millis () / 1000);
  oled.display ();
  delay (1000);
}
