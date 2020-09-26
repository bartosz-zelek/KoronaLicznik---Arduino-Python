# api https://rapidapi.com/Gramzivi/api/covid-19-data?endpoint=apiendpoint_90422c25-72f4-4e9a-a792-67e3dc7553a1

import serial
import time
import requests
import json
arduino = serial.Serial('/dev/ttyUSB0', 9600) # set port
time.sleep(10)

while True:
    try:
        url = "https://covid-19-data.p.rapidapi.com/country"
        querystring = {
            "format": "json",
            "name": "poland" # set country
        }
        headers = {
            "x-rapidapi-host": "covid-19-data.p.rapidapi.com",
            "x-rapidapi-key": "" # set api key
        }
        response = requests.get(url, headers=headers, params=querystring)
        res = json.loads(response.text)[0]
        sick = str(res["confirmed"] - res["recovered"])
        deaths = str(res["deaths"])
    except Exception as e:
        # print(e)
        sick = "Error"
        deaths = "Error"
    dataToArduino = sick+','+deaths+"K"
    # print(dataToArduino)
    arduino.write(bytes(dataToArduino, 'utf-8'))
    time.sleep(900)
