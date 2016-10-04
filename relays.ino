// ------------
// IoT Relay Box
// ------------


/*-------------

Davide Nastri & Mirko Mastrelli
Haarlem, September 2016

-------------*/


// Write "changeRelayS" function
// The function name has to be "changeRelayS" and it has to accept a single string parameter, named "command"
// Here you can find relevant information to complete this task:
// https://docs.particle.io/reference/firmware/photon/#particle-function-
// this function automagically gets called upon a matching POST request
int commaIndex;

int changeRelayS(String command)
{
  // look for the matching argument "coffee" <-- max of 64 characters long
  
  int commaIndex = command.indexOf(','); 
  String first  = command.substring(0,commaIndex);
  Serial.read(); //next character is comma, so skip it using this
  String second = command.substring(commaIndex);
  Serial.print(first);
  Serial.println();
  Serial.print(second);
  Serial.println();
  if ( second == ("ON") ) {
      digitalWrite(first, LOW);
      
  
    } else if ( second ==("OFF") ) {
      digitalWrite(first, HIGH);
    } else if ( second ==("ON/OFF") ) {
      digitalWrite(first, LOW);
      delay(1000);
      digitalWrite(first, HIGH);
    }
  return 1;
  
    // some example functions you might have
    //activateWaterHeater();
    //activateWaterPump();
}

void setup() {
// Initializing all pins to receive command

/*
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
  */  
// *** Note to self *** --> Check HW logic in order to get rid of this issue forcing us to turn relays off at Photon reboot (it may cause unwanted behaviour)
// Turning all pins off
/*
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
*/  
// Initialize serial port
    Serial.begin(9600);

// In order to use the serial port for debugging purpouse you can use similar commands:


// Here you can find how to monitor your Photon serial, using the usb port of your computer:
// https://docs.particle.io/reference/cli/#particle-serial-monitor

// Here you can find:
// https://docs.particle.io/guide/getting-started/connect/photon/


// Row below needs to be uncommented whenever the ChangeRelayS function is complete to enable function publishing on the cloud
// Particle.function("changeRelayS", changeRelayS);
}

void loop() {
// Any code added to this section will run on an endless loop
changeRelayS("D0,ON");
    //parse your data here. example:
    //double x = Double.parseDouble(first);
}