#!/bin/bash

# Pfade zu den PlatformIO Tools (Windows Pfad-Syntax in Bash)
export PATH="$PATH:$USERPROFILE/.platformio/packages/toolchain-atmelavr/bin"
export PATH="$PATH:$USERPROFILE/.platformio/packages/tool-avrdude"

echo "Starte Kompilierung..."
avr-gcc -mmcu=atmega48 -Os -o main.elf src/main.c
#avr-gcc -mmcu=atmega48 -Os -o main.elf src/main_11_3_26_17_26.c

echo "Erstelle HEX-Datei..."
avr-objcopy -O ihex main.elf main.hex

echo "Lade auf ATmega48 hoch..."
# Hinweis: "usbasp" ist der Standardname, "usbasp-clone" wird selten erkannt
avrdude -c usbasp -p m48 -U flash:w:main.hex -B 3

echo "Fertig!"