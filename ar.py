import serial
import time
import pandas as pd
arduino = serial.Serial('COM3', 9600)
time.sleep(2)

while True:
    try:
    	data = pd.read_html('https://www.worldometers.info/coronavirus/')[0]
    	data = data.loc[data['Country,Other'] == 'Italy']
    	sick = str(int(data['ActiveCases']))
    	deaths = str(int(data['TotalDeaths']))
    except:
        sick = "Error"
        deaths = "Error"
    dataToArduino = sick+','+deaths+"K"
    print(dataToArduino)
    arduino.write(bytes(dataToArduino, 'utf-8'))
    time.sleep(5)
    
