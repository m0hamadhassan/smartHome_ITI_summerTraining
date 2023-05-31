# SmartHome ITI Summer Training - Graduation Project

This repository contains the source code and documentation for the SmartHome project, developed as part of the ITI Embedded Systems Summer Training.

## Specifications:
The SmartHome system consists of two separate microcontrollers. One microcontroller is responsible for secure login and main menu control, while the other microcontroller controls and automates external devices. The communication between the two microcontrollers is implemented using the SPI communication protocol. Asynchronous functions are utilized to handle concurrent tasks. An external interrupt is employed to handle alarms. The system incorporates secure login with a 4-digit password, which is set on the first launch. In case of three consecutive incorrect password attempts, the system is locked down until a specific action is taken. However, alarms and automations will continue to operate during the lockdown.

## Implemented Drivers:
The following drivers have been implemented as part of the project:
- DIO (Digital Input/Output)
- LCD (Liquid Crystal Display)
- KEYPAD (Matrix Keypad)
- External Interrupt
- SPI (Serial Peripheral Interface)
- ADC (Analog-to-Digital Converter)

## Functionalities:
### Master Unit:
- On the first launch, the user is prompted to set a password and confirm it. The set password is stored in the internal EEPROM, and a specific byte is marked to indicate that the password has been set by the user.
- The user is then asked to enter the set password. If the correct password is entered, the main menu is displayed. If not, the user has two more attempts to enter the correct password. After three failed attempts, the system locks down and cannot be accessed until the external EEPROM is reset to its initial condition (all bytes set to 0xFF).
- The user is prompted to choose which unit to control: Doors Unit, Rooms Unit, or Kitchen Unit.
    - Doors Unit:
        - The user can choose to open or close a door. They are then asked to select the specific door from a list of available options (Room1, Room2, Room3, Main).
    - Rooms Unit:
        - The user is asked to select a specific room (Room1, Room2, Room3). Within each room, the user can choose to control various devices, such as lights, air conditioners, TVs, and windows.
        - For each device, the user can choose to turn it on or off, open or close windows, etc.
    - Kitchen Unit:
        - The user can choose to wait for the microwave timer to finish and receive an alert upon completion.
- Each selection results in a coded instruction being sent to the Rooms Unit using the SPI protocol.

### Rooms Unit:
- Listens for instructions sent by the Master Unit and performs corresponding actions to control external devices based on the received instructions.
- Additionally, continuously monitors the Light Dependent Resistor (LDR) in the entrance unit to detect day time and night time. This information is used to control the lights in the entrance room.

