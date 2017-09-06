#include <spark-restclient/rest_client.h>
#include <SparkJson/firmware/ArduinoJson.h>

StaticJsonBuffer<1000> jsonBuffer;

int buttonCurrent = 0;
int pwrCurrent = 1;

int button = D1;
int pwr = A0;

char buttonString[40];
char pwrString[40];

RestClient client = RestClient("192.168.0.100");

// lights
String light = "/api/FYSUsNNt5tGiH7l4t5nuSKqjEonVUH6uxINTuVPd/lights";
String light1 = light + "/1"; // room light 1
String light2 = light + "/2"; // room light 2
String light3 = light + "/3"; // desk lamp
String state = "/state";
String lightOn = "{\"on\":true}";
String lightOff = "{\"on\":false}";

void setup() {
    pinMode(button, INPUT_PULLDOWN);
    pinMode(pwr, OUTPUT);
    digitalWrite(pwr, HIGH);
}

// void loop() {

//     //get the state of the button
//     buttonCurrent = digitalRead(button);

//     pwrCurrent = digitalRead(pwr);

//     //if the button is not pressed
//     if(buttonCurrent == HIGH){
//         String response = "";

//         int statusCode = client.get(light1, &response);
//         Particle.publish("status code", String(statusCode));

//         Particle.publish("response", response);
//         int onIndex = response.indexOf("on");
//         char lightStatus = response.charAt(onIndex + 4);
//         if (lightStatus == 't') {
//             Particle.publish("lightStatus", "Turning the lights off");
//             client.put(light1 + state, lightOff, &response);
//             client.put(light2 + state, lightOff, &response);
//             client.put(light3 + state, lightOff, &response);
//         }
//         else if(lightStatus == 'f') {
//             Particle.publish("lightStatus", "Turning the lights on");
//             client.put(light1 + state, lightOn, &response);
//             client.put(light2 + state, lightOn, &response);
//             client.put(light3 + state, lightOn, &response);
//         }

//         JsonObject& root = jsonBuffer.parseObject(response);
//         Particle.publish("lightStatus", root["state"]["on"]);
//         if (statusCode < 400) {
//             if (!root.success()) {
//                 Particle.publish("Error", "parseObject() failed");
//                 return;
//             }
//         }
//         // Particle.publish("lightsOn","switch on the lights");

//         statusCode = client.put(light1, , &response);

//         delay(1000);
//     }
//     else{
//      //do nothing
//     }
// }