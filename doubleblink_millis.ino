///////////////////////////////////////////////////////////////////////////////////
//   Double Blink
//   Blinks on two LEDs for two diferent periods using the millis function.
//
// Based on:
//    - NodeMCU and Arduino open hardware and software community. Thank you all!
//
// Licensed under Creative Commons (SH-BY-NC). @AGordiGuerrero
//
// Antonio Gordillo Guerrero
// anto@unex.es
// @AGordiGuerrero
// Smart Open Lab. Escuela Politécnica de Cáceres. Universidad de Extremadura.
// @SolEpcc 
//
////////////////////////////////////////////////////////////////////////////////////

// I edit this line for test of branching in Github

// Arduino NodeMCU pin mapping
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)


// Timing variables
const int PROGMEM LED1_change_time = 1000; // interval to change the dimming level
const int PROGMEM LED2_change_time = 500; // interval to change the dimming level
unsigned long previousMillis_LED1=0;
unsigned long previousMillis_LED2=0;

//LED variable
boolean LED1_state=LOW;
boolean LED2_state=LOW;
int LED1_pin=D7;
int LED2_pin=D8;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED1 as an output.
  pinMode(LED1_pin, OUTPUT);
  // initialize digital pin LED2 as an output.
  pinMode(LED2_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

// I also edit this line for test of branching in Github


// Timing the switch of LED1
  if(millis() - previousMillis_LED1 > LED1_change_time){
     // guardar el ultimo instante en el que se movio el servo 
    LED1_state = !LED1_state; //switch LED1 value
    digitalWrite(LED1_pin, LED1_state);   // write the LED state into the defined pin
    previousMillis_LED1 = millis(); //update timing variable   
  }

// Timing the switch of LED2
  if(millis()- previousMillis_LED2 > LED2_change_time){
     // guardar el ultimo instante en el que se movio el servo 
    LED2_state = !LED2_state; //switch LED1 value
    digitalWrite(LED2_pin, LED2_state);   // write the LED state into the defined pin
    previousMillis_LED2 = millis(); //update timing variable   
  }


}
