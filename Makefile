all: main.hex

main.hex: main
	avr-objcopy -O ihex -R .eeprom $< $@

main: main.o serial.o motor.o wifly.o ulcd.o misc.o
	avr-g++ -mmcu=atmega2560 -o $@ $^

main.o: main.cpp
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

serial.o: serial.cpp serial.h
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

motor.o: motor.cpp motor.h
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

wifly.o: wifly.cpp wifly.h
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

ulcd.o: ulcd.cpp ulcd.h
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

misc.o: misc.cpp
	avr-g++ -c -O2 -mmcu=atmega2560 -o $@ $<

upload: main.hex
	avrdude -c wiring -p m2560 -P /dev/ttyACM0 -U $<


