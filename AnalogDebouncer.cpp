/*

   AnalogDebouncer.cpp - Library for debouncing a very slow analog signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/
#include <Arduino.h>
#include <AnalogDebouncer.h>

AnalogDebouncer::AnalogDebouncer(int pin, bool initial_state = false,
        int millis_to_reset = 1000, double analog_threshold = 0.1)
{
    _pin = pin;
    _analogThreshold = analog_threshold;
    _debouncer = MilliDebouncer(initial_state, millis_to_reset);
}

bool AnalogDebouncer::getDebouncedState() {

    double rawResult = analogRead(_pin);
    bool result = false;

    if (rawResult >= _analogThreshold) {
        // We read a true
        result = _debouncer.getDebouncedState(true);
    } else {
        result = _debouncer.getDebouncedState(false);
    }
    return result;
}
