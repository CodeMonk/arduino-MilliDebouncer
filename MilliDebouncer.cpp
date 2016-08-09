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

MilliDebouncer::MilliDebouncer(bool initial_state = false,
        int millis_to_reset = 1000)
{
    _prev = initial_state;
    _millisToReset = millis_to_reset;
    _elapsed = 0;
    if (_prev) {
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

bool MilliDebouncer::getDebouncedState(bool newState) {
    bool result = false;

#ifdef DEBUG
    Serial.print("New Value: "); Serial.print((newState)?"On ":"Off");
    Serial.print(" (elapsed="); Serial.print(_elapsed);
    Serial.print(") prev_state="); Serial.print(_prev?"On":"Off");
    Serial.print(" Returning: ");
#endif
    if (newState) {
        // We read a true
        _prev = true;
        result = true;
    } else {
        // We have a false -- but -- let the signal settle, maybe
        if (_prev == true) {
            // We were previously on -- reset all counters, and
            // still return on, until _elapsed passes our reset threshold
            _elapsed = 0;
            _prev = false;
            result =  true;
        } else {
            // We were previously off -- check our elapsed time, to see if we're really off
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
