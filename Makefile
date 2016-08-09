include /usr/local/opt/arduino-mk/Arduino.mk

ARDUINO_DIR=/Applications/Arduino.app/Contents/Java
ARDMK_DIR=/usr/local
AVR_TOOLS_DIR=$(ARDUINO_DIR)/hardware/tools/avr
BOARD_TAG=uno

CXXFLAGS_STD+=-I.
CXXFLAGS_STD+=-I../libraries/elapsedMillis

USER_LIB_PATH+=.
USER_LIB_PATH+=../libraries
ARDUINO_LIBS+=elapsedMillis
ARDUINO_LIBS+=MilliDebouncer
ARDUINO_LIBS+=AnalogDebouncer
ARDUINO_LIBS+=DigitalDebouncer
