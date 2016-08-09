

#include <MilliDebouncer.h>

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

MilliDebouncer input( A0, false, 1500, 1000);

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // Test with one of our blinkers
  bool on = input.getDebouncedState();
  if (on) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
