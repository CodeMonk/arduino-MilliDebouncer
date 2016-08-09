/*

   Digital.cpp - Library for debouncing a very slow digital signal.
   Created by David Frascone, August 8, 2016

*/
#include <Arduino.h>
#include <DigitalDebouncer.h>

DigitalDebouncer::DigitalDebouncer(int pin, bool initial_state = false,
        int millis_to_reset = 1000)
{
    _pin = pin;
    _debouncer = MilliDebouncer(initial_state, millis_to_reset);
}

bool DigitalDebouncer::getDebouncedState() {

    int rawResult = digitalRead(_pin);
    bool result = false;

    if (rawResult = HIGH) {
        // We read a true
        result = _debouncer.getDebouncedState(true);
    } else {
        // We read a false
        result = _debouncer.getDebouncedState(false);
    }
    return result;
}
