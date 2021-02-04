#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define LED 25
//#define LED2 2

char Command;

int idBoxArray[3] = {};
int noBoxArray[3] = {};
String PasswordArray[3] = {};
bool doorArray[3] = {};
int doorArraySerial[3] = {};
bool isRentArray[3] = {};
bool TimeOutArray[3] = {};

int PintuArray[3] = {32,19};
int SwitchArray[3] = {34,35};

int buttonState[3] = {};
bool doorSendToDB[3] = {};

const char* ssid = "UknownUser";
const char* passw = "SuT0mO:)";

const String baseUrl = "https://ranuapi.pythonanywhere.com/api/lb";

HTTPClient http;
 
void setup() {
  pinMode(LED, OUTPUT);
  
  for(int a = 0; a<2;a++){
     pinMode(PintuArray[a], OUTPUT);
     pinMode(SwitchArray[a], INPUT);
  }
 
  Serial.begin(115200);
//  delay(4000);
  WiFi.begin(ssid, passw);
//  Serial.print("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
//    Serial.print(".");
  }
 
//  Serial.println("\nConnected to the WiFi network");
 
}
 
void loop() {
  
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    getJsonResponse();
    digitalWrite(LED, HIGH);
    serialData();
  }
  else{
    digitalWrite(LED, LOW);
  }
 
  delay(80);
 
}
