/*

   MilliDebouncer.h - Library for debouncing a very slow signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/

#ifndef MilliDebouncer_h
#define MilliDebouncer_h

#include <elapsedMillis.h>

class MilliDebouncer {
    private:
        bool           _prev;               // if true, pin was on the last read
        unsigned       _millisToReset;      // Number of ticks to call the signal off
        elapsedMillis  _elapsed;            // Number of ticks we've been off for

    public:
        MilliDebouncer(bool initial_state=false, unsigned millis_to_reset=1000);

        bool getDebouncedState(bool newState);
};

#endif /* MilliDebouncer_h */
