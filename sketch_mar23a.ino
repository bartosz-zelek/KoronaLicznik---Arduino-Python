    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
     
    LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
     
    String dataToArduino = "";
    void setup()  
    {
      Serial.begin(9600);
      
      lcd.begin(16,2);
      
      lcd.backlight(); 
      lcd.setCursor(0,0);
      lcd.print("Zarazeni: ");
      delay(500);
      lcd.setCursor(0,1);
      lcd.print("Zgony: ");
     
    }
     
    void loop() 
    {
        if(Serial.available() > 0){
          lcd.clear();
          String dataToArduino = Serial.readString();
          String data[2];
          int j = 0;
          String temp = "";
          
          for(int i=0; i<dataToArduino.length(); i++){
            if(dataToArduino[i] == ',' || dataToArduino[i] == 'K'){
              data[j] = temp;
              temp = "";
              j++;
              continue;
            }
            temp += dataToArduino[i];
          }
          lcd.setCursor(0,0);
          lcd.print("Zarazeni: "+data[0]);
          delay(500);
          lcd.setCursor(0,1);
          lcd.print("Zgony: 0"+data[1]);
        }
    }
