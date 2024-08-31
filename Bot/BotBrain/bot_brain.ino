#include <ESP8266WiFi.h>
// Motor driver pins
const int MBackLeft1 = D2; // 
const int MBackLeft2 = D1;
const int MBackRight1 = D0;
const int MBackRight2 = D3;
const int MFrontLeft1 = D6;
const int MFrontLeft2 = D5;
const int MFrontRight1 = D8;
const int MFrontRight2 = D7;
// wifi set_up
const char WiFiPassword[] = "winners_switch";
const char AP_NameChar[] = "Switch_car" ;

WiFiServer server(80);
String request = "";
// int LED_Pin = LED_BUILTIN;

void setup() {
  // motor set up
  pinMode(MBackLeft1, OUTPUT);
  pinMode(MBackLeft2, OUTPUT);
  pinMode(MBackRight1, OUTPUT);
  pinMode(MBackRight2, OUTPUT);
  pinMode(MFrontLeft1, OUTPUT);
  pinMode(MFrontLeft2, OUTPUT);
  pinMode(MFrontRight1, OUTPUT);
  pinMode(MFrontRight2, OUTPUT);
  // wifi set up
  Serial.begin(9600);
  // pinMode(LED_Pin, OUTPUT);
  // digitalWrite(LED_Pin, HIGH);//Turn on LED
  // delay(400);
  // digitalWrite(LED_Pin, LOW);//Turn off LED
  WiFi.disconnect();
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
  server.begin();
  Serial.print(WiFi.softAPIP());
  stop();
  delay(5000);
  Serial.print("Start now!");
}
// test
// void loop() {
//   forward();
//   delay(2000);
//   stop();
//   delay(2000);
//   backward();
//   delay(2000);
//   right();
//   delay(2000);
//   left();
//   delay(2000);
// }
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)  {
    // digitalWrite(LED_Pin, LOW);
    Serial.print("NO REQUEST\n");
    return;
  }
  // Read the first line of the request
  request = client.readStringUntil('\r');

  if ( request.indexOf("FORWARD") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    forward();
    Serial.print("FORWARD");
    Serial.print("\n");
  } 
  if ( request.indexOf("BACKWARD") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    backward();
    Serial.print("BACKWARD");
    Serial.print("\n");
  } 
  if ( request.indexOf("RIGHT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    right();
    Serial.print("RIGHT");
    Serial.print("\n");
  } 
  if ( request.indexOf("LEFT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    left();
    Serial.print("LEFT");
    Serial.print("\n");
  } 
  if ( request.indexOf("FORWARDLEFT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    forwardleft();
    Serial.print("FORWARDLEFT");
    Serial.print("\n");
  } 
  if ( request.indexOf("FORWARDRIGHT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    forwardright();
    Serial.print("FORWARDRIGHT");
    Serial.print("\n");
  } 
  if ( request.indexOf("BACKWARDRIGHT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    backwardright();
    Serial.print("BACKWARDRIGHT");
    Serial.print("\n");
  } 
  if ( request.indexOf("BACKWARDLEFT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    backwardleft();
    Serial.print("BACKWARDLEFT");
    Serial.print("\n");
  } 
  if ( request.indexOf("ROTATELEFT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    rotateleft();
    Serial.print("ROTATELEFT");
    Serial.print("\n");
  } 
  if ( request.indexOf("ROTATERIGHT") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    rotateright();
    Serial.print("ROTATERIGHT");
    Serial.print("\n");
  } 
  if ( request.indexOf("STOP") > 0 ){
    // digitalWrite(LED_Pin, HIGH);//Turn on LED
    stop();
    Serial.print("STOP");
    Serial.print("\n");
  }
}
void forward() {
  // all motor forward
  digitalWrite(MBackLeft1, HIGH);
  digitalWrite(MBackLeft2, LOW);
  digitalWrite(MBackRight1, HIGH);
  digitalWrite(MBackRight2, LOW);
  digitalWrite(MFrontLeft1, HIGH);
  digitalWrite(MFrontLeft2, LOW);
  digitalWrite(MFrontRight1, HIGH);
  digitalWrite(MFrontRight2, LOW);
}
void backward() {
  // all motor backward
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, HIGH);
  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, HIGH);
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, HIGH);
  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, HIGH);
}
void right() {
  // front-left, back-right forward
  digitalWrite(MFrontLeft1, HIGH);
  digitalWrite(MFrontLeft2, LOW);

  digitalWrite(MBackRight1, HIGH);
  digitalWrite(MBackRight2, LOW);

  // back-left, front-right backword
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, HIGH);

  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, HIGH);  
}
void left() {
  // front-left, back-right backward
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, HIGH);

  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, HIGH);
  
  // back-left, front-right forward
  digitalWrite(MBackLeft1, HIGH);
  digitalWrite(MBackLeft2, LOW);

  digitalWrite(MFrontRight1, HIGH);
  digitalWrite(MFrontRight2, LOW);  
}
void stop() {
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, LOW);
  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, LOW);
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, LOW);
  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, LOW);
}
void rotateleft() {
  // frontright, backright forward
  digitalWrite(MFrontRight1, HIGH);
  digitalWrite(MFrontRight2, LOW);

  digitalWrite(MBackRight1, HIGH);
  digitalWrite(MBackRight2, LOW);
  // frontleft, backleft backward
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, HIGH);
  
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, HIGH);
}
void rotateright() {
  // frontright, backright backward
  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, HIGH);

  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, HIGH);
  // frontleft, backleft forward
  digitalWrite(MFrontLeft1, HIGH);
  digitalWrite(MFrontLeft2, LOW);

  digitalWrite(MBackLeft1, HIGH);
  digitalWrite(MBackLeft2, LOW);
}
void forwardright() {
  // frontright, backleft stop
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, LOW);

  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, LOW);
  // frontleft, backright forward
  digitalWrite(MFrontLeft1, HIGH);
  digitalWrite(MFrontLeft2, LOW);

  digitalWrite(MBackRight1, HIGH);
  digitalWrite(MBackRight2, LOW);
}
void forwardleft() {
  // frontright, backleft forward
  digitalWrite(MBackLeft1, HIGH);
  digitalWrite(MBackLeft2, LOW);

  digitalWrite(MFrontRight1, HIGH);
  digitalWrite(MFrontRight2, LOW);
  // frontleft, backright stop
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, LOW);

  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, LOW);
}
void backwardright() {
  // frontright, backleft backward
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, HIGH);

  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, HIGH);
  // frontleft, backright stop
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, LOW);

  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, LOW);
}
void backwardleft() {
  // frontright, backleft stop
  digitalWrite(MBackLeft1, LOW);
  digitalWrite(MBackLeft2, LOW);

  digitalWrite(MFrontRight1, LOW);
  digitalWrite(MFrontRight2, LOW);
  // frontleft, backright backward
  digitalWrite(MFrontLeft1, LOW);
  digitalWrite(MFrontLeft2, HIGH);

  digitalWrite(MBackRight1, LOW);
  digitalWrite(MBackRight2, HIGH);
}
