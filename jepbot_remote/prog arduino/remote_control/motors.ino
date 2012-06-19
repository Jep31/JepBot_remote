///////////// Gestion des moteurs /////////////

// Sécurité qui active ou désactive les moteurs
boolean startBaseRoulante=false;

//Initialisation moteurs

//Pins des PWM de la base roulante
int pinPwmd = 5;    
int pinPwmg = 6;    

//Pins de sens de la base roulante
int sensAvantGauche = 7; 
int sensArriereGauche = 8;
int sensAvantDroit = 4;
int sensArriereDroit = 12;

// Variables Moteurs
int pwmG;
int pwmD;

void initialisationMoteur(){

  //Configuration pins en sortie
  pinMode(pinPwmd, OUTPUT); 
  pinMode(pinPwmg, OUTPUT); 
  pinMode(sensAvantGauche, OUTPUT); 
  pinMode(sensArriereGauche, OUTPUT); 
  pinMode(sensAvantDroit, OUTPUT); 
  pinMode(sensArriereDroit, OUTPUT); 

}

void setPwmD(int valeur){
  pwmD = valeur;
}

void setPwmG(int valeur){
  pwmG = valeur;
}

int getPwmG(){
 return pwmG;
}

int getPwmD(){
 return pwmD;
}

void demarrageMoteur(){
  startBaseRoulante=true;
}


void arretMoteur(){
  startBaseRoulante=false;
}

void coontrolMotors(){
  pwmG = constrain(pwmG, -250, 250);
  pwmD = constrain(pwmD, -250, 250);
 if(startBaseRoulante == true){
   commandeMotor(pwmG, 'g');
   commandeMotor(pwmD, 'd');
 }else{
   commandeMotor(0, 'g');
   commandeMotor(0, 'd');
 }
}


void commandeMotor(int valeur , char moteur){
  if(valeur>0){
    sensMoteurs(moteur, 'a');  //défini le sens de rotation
    constrain(valeur,0,250);  //limitation basse et haute des pwm
    switch (moteur){

    case 'g' :
      analogWrite(pinPwmg,valeur);
      break;

    case 'd' :
      analogWrite(pinPwmd,valeur);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans setPwm");
      break;

    }

  }

  if(valeur<0){
    sensMoteurs(moteur,'r');  //défini le sens de rotation
    valeur= -valeur;
    constrain(valeur,0,250); //limitation basse et haute des pwm
    switch (moteur){
      
    case 'g' :
      analogWrite(pinPwmg,valeur);
      break;

    case 'd' :
      analogWrite(pinPwmd,valeur);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans setPwm");
      break;
    }
  }

  if(valeur==0){

    /////Choix frein ou roue libre par defaut
    //sensMoteurs(moteur, 'f');   //frein
    sensMoteurs(moteur,'l');   // roue libre
    switch (moteur){

    case 'g' :
      analogWrite(pinPwmg,valeur);
      break;

    case 'd' :
      analogWrite(pinPwmd,valeur);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans setPwm");
      break;
    }
  }
}

/* Defini le sens des moteurs
 
 moteur
 
 a = avant
 
 r = recul
 
 f = frein
 
 l = libre
 
 
 
 cote
 
 g = gauche
 
 d = droit
 
 //*/



void sensMoteurs(char moteur, char sens){
  switch (sens){
    //////////// Marche Avant /////////////
  case 'a' :
    switch (moteur){
      
    case 'g' :
      digitalWrite(sensArriereGauche, LOW);
      digitalWrite(sensAvantGauche, HIGH);
      break;

    case 'd' :
      digitalWrite(sensArriereDroit, LOW);
      digitalWrite(sensAvantDroit, HIGH);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans sensMoteurs"); 
      break; 

    }
    break;
    //////////// Marche Arriere /////////////
  case 'r' :
    switch (moteur){

    case 'g' :
      digitalWrite(sensArriereGauche, HIGH);
      digitalWrite(sensAvantGauche, LOW);
      break;

    case 'd' :
      digitalWrite(sensArriereDroit, HIGH);
      digitalWrite(sensAvantDroit, LOW);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans sensMoteurs");  
      break;

    }

    break;
    //////////// Freinage //////////////
  case 'f' :
    switch (moteur){

    case 'g' :
      digitalWrite(sensArriereGauche, HIGH);
      digitalWrite(sensAvantGauche, HIGH);
      break;

    case 'd' :
      digitalWrite(sensArriereDroit, HIGH);
      digitalWrite(sensAvantDroit, HIGH);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans sensMoteurs");  
      break;

    }

    break;
    
    //////////// Roues libres /////////////
  case 'l' :
    switch (moteur){
      
    case 'g' :
      digitalWrite(sensArriereGauche, LOW);
      digitalWrite(sensAvantGauche, LOW);
      break;
      
    case 'd' :
      digitalWrite(sensArriereDroit, LOW);
      digitalWrite(sensAvantDroit, LOW);
      break;

    default :
      Serial.println("Donnée du type de moteur non conforme dans sensMoteurs");  
      break;

    }
    break;
    ///////////////// ERREUR ////////////
    
  default :
    Serial.println("Donnée du sens moteur non conforme dans sensMoteurs");  
    break;
  }
}





