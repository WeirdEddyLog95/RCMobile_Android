char comando;
String string;
boolean ledon = false;
#define led 5

  void setup()
  {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      comando = ((byte)Serial.read());
      
      if(comando == ':')
      {
        break;
      }
      
      else
      {
        string += comando;
      }
      
      delay(1);
    }
    
    if(string == "TO")
    {
        ledOn();
        ledon = true;
    }
    
    if(string =="TF")
    {
        ledOff();
        ledon = false;
        Serial.println(string);
    }
    
    if ((string.toInt()>=0)&&(string.toInt()<=255))
    {
      if (ledon==true)
      {
        analogWrite(led, string.toInt());
        Serial.println(string);
        delay(10);
      }
    }
 }

//Para activar el led
void ledOn()
   {
      analogWrite(led, 255);
      delay(10);
    }

//Para apagar el led
void ledOff()
 {
      analogWrite(led, 0);
      delay(10);
 }
 

    
