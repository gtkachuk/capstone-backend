################################################################################
# Arduino project settings. 
#
ARDUINO_DIR             = /usr/share/arduino
TARGET                  = backend
ARDUINO_LIBS            = SPI
BOARD_TAG               = uno
ARDUINO_PORT            = /dev/ttyACM0
 
include /usr/share/arduino/Arduino.mk


################################################################################
# Other targets.
#
SOURCES                 = backend.ino RGBTile.cpp
VENDOR_SOURCES          = Adafruit_WS2801.cpp bitlash.cpp
HEADERS                 = RGBTile.h
VENDOR_HEADERS          = Adafruit_WS2801.h bitlash.h

#.PHONY: style
#style: $(SOURCES) $(HEADERS)
#	astyle  --indent=spaces=4 \
#		--convert-tabs \
#		--pad-oper \
#		--style=java \
#		$^
#	rm -f *.orig

tags: $(SOURCES) $(VENDOR_SOURCES) $(HEADERS) $(VENDOR_HEADERS)
	ctags $^
