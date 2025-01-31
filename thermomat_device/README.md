
I only use the espmqtt.ino file as the main programm 

# ESP Wiring

| From     | To                                                                                       |
| -------- | ---------------------------------------------------------------------------------------- |
| VCC      | +                                                                                        |
| GPIO14   | Female cable or switch to ground (used to reset WIFI and Server Settings when set to low |
| CH_PC/EN | +                                                                                        |
| REST/RST | GPIO16                                                                                   |
| TX       | RX                                                                                       |
| RX       | TX                                                                                       |
| GPIO04   | Roatary encoder PIN1                                                                     |
| GPIO05   | Roatary encoder PIN2                                                                     |
| GPIO0    | GND for programming                                                                      |
| GPIO15   | GND                                                                                      |
| GND      | GND                                                                                      |

# Thermostat Wiring

| From                 | To     |
| -------------------- | ------ |
| Roatary encoder PIN1 | GPIO04 |
| Roatary encoder PIN2 | GPIO05 |
| Roatary encoder GND  | GND    |
| +                    | VCC    |
| GND                  | GND    |

# Scheme

![thermomtat](https://user-images.githubusercontent.com/58222491/92621430-1949cc00-f2c4-11ea-8f5f-025a6b75946f.jpg)

# Pictures

![IMG_6568](https://user-images.githubusercontent.com/58222491/92623073-17810800-f2c6-11ea-9966-dea7dbdfa5fb.JPG)

![IMG_6567](https://user-images.githubusercontent.com/58222491/92623084-1a7bf880-f2c6-11ea-825d-ca24aa10928e.JPG)

![IMG_6564](https://user-images.githubusercontent.com/58222491/92623090-1c45bc00-f2c6-11ea-88f1-e7fa66be0976.JPG)


# Arduino IDE Settings

1. Datei -> Voreinstellungen -> Zusätzliche Boardverwalter-URLs : http://arduino.esp8266.com/stable/package_esp8266com_index.json einfügen

2. Werkzeuge -> Boards:
   Generic ESP8266 Module auswählen

3. Werkzeuge -> Flash Size:
   512KB (FS:64KB) auswählen

4. Werkzeuge -> Serieller Monitor -> 115200 Baud:
   um Daten zu empfangen

# How to flash assembly

1. Restart device with GPIO0 connected to Programmer GND to go into flash mode.
2. Press compile and upload Sketch
3. When IDE is trying to connect, connect 3.3V to VCC

| From            | To    |
| --------------- | ----- |
| Programmer GND  | GPIO0 |
| Programmer TX   | RX    |
| Programmer RX   | TX    |
| Programmer 3.3V | VCC   |
