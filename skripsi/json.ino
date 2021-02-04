void getJson(String JSONMessage){
    DynamicJsonDocument doc(2048);
    deserializeJson(doc,JSONMessage);
//    Serial.println(doc.size());
    String code = doc[0]["CodeLocker"];
//    Serial.println("Locker " + code);
    for(int a = 0; a < doc.size();a++){
//      int idbox = doc[a]["id"];
      idBoxArray[a] = doc[a]["id"];
//      int nobox = doc[a]["NoBox"];
      noBoxArray[a] = doc[a]["NoBox"];
//      bool door = doc[a]["IsOpen"];
      doorArray[a] = doc[a]["IsOpen"];
      String password = doc[a]["Password"];
      PasswordArray[a] = password;
      isRentArray[a] = doc[a]["IsRent"];
      TimeOutArray[a] = doc[a]["TimeOut"];

      Serial.println(String(noBoxArray[a]) + "-" + String(PasswordArray[a]) + "-" + String(isRentArray[a]) + "-" + String(TimeOutArray[a]));
//      Serial.println(String(idbox)+" - " + String(nobox) + " - " + String(door) + " - " + String(password));
    }
    BukaPintu();
}

void getJsonResponse(){
    const String getUrl = "?CodeLocker=LOK612016035";
  
    http.begin(baseUrl + getUrl); //Specify the URL
    
    int httpCode = http.GET();
    if (httpCode > 0) { 
        String payload = http.getString();
  //        Serial.println(httpCode);
  //        Serial.println(payload);
        getJson(payload);
//        LimitSwitch(); // nanti di balikan lagi
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
  
    http.end(); //Free the resources
}

void BukaPintu(){
  for(int a = 0; a < 2;a++){
    if(doorArray[a] == 1 || doorArraySerial[a] == 1){
      digitalWrite(PintuArray[a], HIGH);
//      Serial.println("Pintu " + String(noBoxArray[a]) + " Terbuka");
    }
    else if(doorArray[a] == 0 || doorArraySerial[a] == 0){
    digitalWrite(PintuArray[a], LOW);
//    Serial.println("Pintu " + String(noBoxArray[a]) + " Tertutup");
    }
  }
}

void pathJsonResponse(int idBox){
  const String putUrl = "/" + String(idBox) + "/";
  http.begin(baseUrl + putUrl); //Specify the URL
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.PUT("{\"CodeLocker\":\"LOK612016035\", \"IsOpen\":false}"); 
    
  if(httpResponseCode>0){
    String response = http.getString();   
  //  Serial.println(httpResponseCode);
//    Serial.println(response);          
  }
  else{
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();
}
