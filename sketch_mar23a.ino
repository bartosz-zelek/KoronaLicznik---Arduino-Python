    /*
    *  LCM1602 & Arduino Uno
    *  VCC - > 5 V
    *  GND - GND
    *  SCL -> A5
    *  SDA -> A4
    */
     
    #include <Wire.h>   // standardowa biblioteka Arduino
    #include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD
     
    LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
     
    String dataToArduino = "0";
    void setup()  
    {
      Serial.begin(9600);
      
      lcd.begin(16,2);   // Inicjalizacja LCD 2x16
      
      lcd.backlight(); // zalaczenie podwietlenia 
      lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
      lcd.print("Zarazeni: ");
      delay(500);
      lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
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
          lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
          for(int i=0; i<sizeof(dataToArduino); i++){
            if(dataToArduino[i] == ',' || dataToArduino[i] == 'K'){
              data[j] = temp;
              temp = "";
              j++;
              continue;
            }
            temp += dataToArduino[i];
          }
          lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
          
          lcd.print("Zarazeni: "+data[0]);
          delay(500);
          lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
          lcd.print("Zgony: 0"+data[1]);
        }
    }
