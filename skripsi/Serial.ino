void serialData(){
  if(Serial.available() > 0)  
  {          
      
      char receiveVal = (char)Serial.read();  
      if (receiveVal == '\n'){
        if(Command == 'a'){      
          doorArraySerial[0] = 1;
        }
        else if(Command == 'b'){  
          doorArraySerial[1] = 1;
        }
      }
      else{
        Command = receiveVal;
      }       
  }      
}
