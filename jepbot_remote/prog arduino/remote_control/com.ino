
int sensG;
int sensD;


int donnee = 1;
int valeur = 0;
void initialisationLiaisonSerie(){
  Serial.begin(9600);       // use the serial port
}


void liaisonMotors(){
  if (Serial.available()){

    switch (donnee){

    case 1:
      valeur = Serial.read();
      if(valeur == 0){
        sensG = -1;
      }
      if(valeur == 1){
        sensG = 1;
      }
      donnee++;   
      break;
    case 3:
      valeur = Serial.read();
      if(valeur == 0){
        sensD = -1;
      }
      if(valeur == 1){
        sensD = 1;
      }
      donnee++;   
      break;
    case 2:
      valeur = Serial.read();
      setPwmG(sensG * valeur);
      //pwmG = sensG * valeur;
      donnee++;   
      break;
    case 4:
      valeur = Serial.read();
      //pwmD = sensD * valeur;
      setPwmD(sensD * valeur);
      donnee = 1;   
      break;
    }
  }
}








