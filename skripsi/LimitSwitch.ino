void LimitSwitch(){
  for(int a = 0; a<2;a++){
    buttonState[a] = digitalRead(SwitchArray[a]);

    if (buttonState[a] == HIGH) {
//      Serial.print("Pintu ");
//      Serial.print(a+1);
//      Serial.println(" tertutup");
    } else {
//      Serial.print("Pintu ");
//      Serial.print(a+1);
//      Serial.println(" terbuka");
      pathJsonResponse(idBoxArray[a]);
      doorArraySerial[a] = 0;
    }
  }
}
