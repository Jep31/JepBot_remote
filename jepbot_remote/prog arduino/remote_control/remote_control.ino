


void setup(){
  initialisationMoteur();
  initialisationLiaisonSerie();
  initSharps();
  demarrageMoteur();
}


void loop(){
  liaisonMotors();
  coontrolMotors();
  detection();
}


