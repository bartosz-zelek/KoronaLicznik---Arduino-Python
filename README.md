# KoronaLicznik---Arduino-Python

![90593908_855986191535747_5022615771910504448_n](https://github.com/user-attachments/assets/0736e124-3ab9-4cf0-99ca-da9f87fcb248)

### Ubuntu instructions
1. Insert sketch_mar23a.ino to your Arduino.
2. Install dependencies: pip3 install -r requirements.txt
3. In ar.py:
    * Set USB connected to Arduino (eg. "dmesg | grep tty" in terminal).
    * Set your country and api key (You will find it on https://rapidapi.com/Gramzivi/api/covid-19-data).

### Windows instructions
1. Insert sketch_mar23a.ino to your Arduino.
2. Install dependencies: pip3 install -r requirements.txt
3. In ar.py:
    * Set USB connected to Arduino (eg. Device manager -> Ports -> Your Arduino - look for COMX).
    * Set your country and api key (You will find it on https://rapidapi.com/Gramzivi/api/covid-19-data).
