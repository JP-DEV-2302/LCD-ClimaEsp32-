LCD Climate ESP32
Project developed using ESP32 and a 20x4 I2C LCD display to show real-time weather and time information through online APIs.

Features


Real-time weather monitoring


Current temperature


Feels-like temperature


Air humidity


Cloud coverage


Wind speed


Translated wind direction


Atmospheric pressure


UV index


Real-time clock


Screen navigation using a button


Automatic data updates



Technologies Used


ESP32


C++


Arduino Framework


PlatformIO


REST APIs


I2C 20x4 LCD


Wi-Fi


JSON



Libraries Used
#include <WiFi.h>#include <WiFiClientSecure.h>#include <HTTPClient.h>#include <ArduinoJson.h>#include <Wire.h>#include <LiquidCrystal_I2C.h>

Project Structure
LCD-ClimaEsp32/│├── src/│   └── main.cpp│├── include/│├── lib/│├── platformio.ini│└── README.md

Hardware Used
ESP32
Responsible for Wi-Fi connectivity and data processing.
LCD I2C 20x4
Responsible for displaying weather information.
I2C Address:
0x27
Button
Used GPIO:
GPIO 0
Function:


switch display screens.



APIs Used
Weather
https://www.weatherapi.com/
Time
https://timeapi.io/

How to Download the Project
Option 1 — Using GitHub
Open the terminal and run:
git clone https://github.com/JP-DEV-2302/LCD-ClimaEsp32-.git
Then:
cd LCD-ClimaEsp32-

Option 2 — Download ZIP


Open the GitHub repository


Click:


Code


Then:


Download ZIP


Extract the folder.



How to Open in VSCode
1. Install VSCode
https://code.visualstudio.com/

2. Install PlatformIO
https://platformio.org/
Or:


Open VSCode


Go to Extensions


Search for:


PlatformIO IDE


Install it.



3. Open the Project
In VSCode:
File → Open Folder
Select:
LCD-ClimaEsp32-

Configuration
Open:
src/main.cpp
Change:
const char *WIFI_SSID = "YOUR_WIFI";const char *WIFI_PASSWORD = "YOUR_PASSWORD";

API Configuration
Replace your API key here:
const char *URL_API = "https://api.weatherapi.com/v1/current.json?key=YOUR_API_KEY";

How to Compile
In PlatformIO:
Build
Compiles the project.
Upload
Uploads the firmware to the ESP32.
Monitor
Opens the serial monitor.

System Workflow
The ESP32:


connects to Wi-Fi;


accesses APIs;


receives JSON data;


processes information;


displays everything on the LCD.



Screen System
Screen 1


city;


state;


time;


weather condition.


Screen 2


temperature;


feels-like temperature;


humidity;


cloud coverage.


Screen 3


wind;


direction;


pressure;


UV index.



Automatic Updates
Data is automatically updated every:
30 seconds

Wind Direction Translation
The system automatically translates:
N  -> NorthNE -> NortheastSW -> SouthwestW  -> West

Future Improvements


weather forecast;


charts and graphs;


web dashboard;


mobile app;


IoT integration;


smart LEDs;


notifications;


AI integration.



Author
Project developed by João Pedro.

License
Educational and experimental project.
