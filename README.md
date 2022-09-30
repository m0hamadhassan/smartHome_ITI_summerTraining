# smartHome_ITI_summerTraining
Graduation project for ITI Embedded Systems Summer Training

• Specifications :
- Two separate micro controllers :
    ONE for secure log in and main menu control, THE OTHER is for controling and automating exteral devices.
- SPI communucation protocol is used.
- Asynchronous functions are implemented.
- External Interrupt is used (For Alarm).
- Secure login with 4 digits password, Passwor is set on first launch of the system.
- In case of 3 wrong password tries the system is lockdown and never run until a specific action is taken.
- Alarms and automations will not be affected by system lockdown.
• Implemented Drivers
-DIO
-LCD
-KEYPAD
-External Interrupt
-SPI
-ADC
• Functionalities:
-MasterUnit : 
  -On first launch, Asking user to set password then confirm password and the set password is write on internal EEPROM and mark on certain byte thatpassword is set by
  user, Then asking user to Enter the set password, If correct; main menu is launched, If not the user hav 2 more tries to enter correct password, If these tries are
  wasted then system is lockdown and never runs again until the External EEPROM is erased to its initial condition (all bytes 0xFF).
  -At first user is Asked to choose which unit to control {1-Doors Unit , 2-Rooms Unit , 2-Kitchen Unit}.
        1- Doors Unit :
        User is Asked to {1-Open Door , 2-Close Door}, by each choice the user is asked to select the chosen door among {1-Room1 , 2-Room2 , 3-Room3 , 4-Main}.
        2- Rooms Unit:
        User is asked to select chosen Room { 1-Room1 , 2-Room2 , 3-Room3},
        by each choice the user is asked to select device to control among {1-Lights , 2- Conditioner , 3-TV , 4-Windows}
        1- Lights : {1-TurnON , 2-TurnOff}
        2- Conditioner : {1-TurnON , 2-TurnOff}
        3- TV : {1-TurnON , 2-TurnOff}
        4- Windows : {1-Open , 2-Close}
        3- Kitchen Unit :
        One choice is to wait for Microwave timer to finish and alert user by its finishing.
  -Each final choice ends with a coded instruction sent to Rooms Unit by SPI protocol.
RoomsUnit:
-Listen to coming instruction from master unit and peroform actions -according to coming instruction- to control external devices
-In addition to continous checking for LDR on entrance unit to detect day time and night time to control lights on entrance room.
