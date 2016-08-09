/*

   MilliDebouncer.cpp - Library for debouncing a very slow signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/
#include <Arduino.h>
#include <MilliDebouncer.h>

#undef DEBUG
#ifdef DEBUG
#endif

MilliDebouncer::MilliDebouncer(int pin, bool initial_state = false,
        int millis_to_reset = 1000, double analog_threshold = 0.1)
{
    _pin = pin;
    _on = initial_state;
    _millisToReset = millis_to_reset;
    _analogThreshold = analog_threshold;
    _elapsed = 0;
    if (_on) {
        // We're on, so, set elapsed to zero
        _elapsed = 0;
    } else {
        // We're starting out off, so, set elapsed to millsToReset
        _elapsed = _millisToReset;
    }
#ifdef DEBUG
    Serial.begin(9600);
#endif
}

bool MilliDebouncer::getDebouncedState() {
    double rawResult = analogRead(_pin);
    bool result = false;

#ifdef DEBUG
    Serial.print("RAW Read port "); Serial.print(_pin);
    Serial.print(": "); Serial.print(rawResult);
    Serial.print(" ("); Serial.print((rawResult > _analogThreshold)?"On ":"Off");
    Serial.print(")  (elapsed="); Serial.print(_elapsed);
    Serial.print(" prev_state="); Serial.print(_on?"On":"Off");
    Serial.print("): Returning: ");
#endif
    if (rawResult > _analogThreshold) {
        // We read a true
        _on = true;
        result = true;
    } else {
        // We read a false -- but -- let the signal settle, maybe
        if (_on == true) {
            // We were previously on -- reset all counters, and
            // still return on
            _elapsed = 0;
            _on = false;
            result =  true;
        } else {
            // We were previously off -- check our elapsed time
            if ( _elapsed >= _millisToReset ) {
                // Yay -- we've been off long enough - return false
                result =  false;
            } else {
                // Haven't been off long enough
                result =  true;
            }
        }
    }
#ifdef DEBUG
    Serial.println(result?"On":"Off");
#endif
    return result;
}
