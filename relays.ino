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

int changeRelayS(String command)
{
  int commaIndex = command.indexOf(','); // look for the matching argument between " " <-- max of 64 characters long
  String pinNumber  = command.substring(0,commaIndex); //store the pinNumber part of the string in pinNumber
  String relayCommand = command.substring(commaIndex+1); //store the relayCommand part of the string in relayCommand
  int pinNumberInt = pinNumber.toInt(); //make pinNumberInt integer to be used with digitalWrite later
  //print relais and action in loop
    Serial.print("Pin Number: " + pinNumber);  
    Serial.println();
    Serial.print("Relay Command: " + relayCommand);  
    Serial.println();
    
  if (relayCommand == "ON") {
      digitalWrite(pinNumberInt, LOW);
      return pinNumberInt;
      
    } else if (relayCommand =="OFF") {
        
        digitalWrite(pinNumberInt, HIGH);
        return pinNumberInt;
        
    } else if (relayCommand == "ON/OFF") {
      
        digitalWrite(pinNumberInt, LOW);
        delay(1000);
        digitalWrite(pinNumberInt, HIGH);
      return pinNumberInt;
      
    }  else {
        
        return -1;
    }
  
}

void setup() {
// Initializing all pins to receive command
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
  
// *** Note to self *** --> Check HW logic in order to get rid of this issue forcing us to turn relays off at Photon reboot (it may cause unwanted behaviour)
// Turning all pins off

    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
  
// Initialize serial port
    Serial.begin(9600);

// In order to use the serial port for debugging purpouse you can use similar commands:
    Particle.function("changeRelayS", changeRelayS);
}

void loop() {

}
