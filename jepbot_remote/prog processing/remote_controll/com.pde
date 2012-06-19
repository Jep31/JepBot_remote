import processing.serial.*;
Serial port;

void initSerie() {
  println(Serial.list()); //Listage des ports séries
  port = new Serial(this, Serial.list()[0], 9600);
}

void communication() {
  int valeur=0;
  int signe = 0;
  if (pwmG<0) {
    signe=0;
    valeur = -pwmG;
  } 
  else {
    signe=1;
    valeur = pwmG;
  }
  println("MG: signe: " +  signe + " valeur: " + valeur);
  port.write(signe);
  port.write(valeur);
  
  
   if (pwmD<0) {
    signe=0;
    valeur = -pwmD;
  } 
  else {
    signe=1;
    valeur = pwmD;
  }
  
  println("MD: signe: " +  signe + " valeur: " + valeur);
  port.write(signe);
  port.write(valeur);
}

