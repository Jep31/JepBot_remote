int analog_pin_sharp;
int signal_sharp;
int seuil_sharp;
int pin_led_sharp;

void initSharps(){
  analog_pin_sharp = 5;
   signal_sharp = 0;
   seuil_sharp = 100;
   pin_led_sharp = 2;
   pinMode(pin_led_sharp, OUTPUT); 
}

void detection(){
 signal_sharp = analogRead(analog_pin_sharp);
 if(signal_sharp >  seuil_sharp){
   digitalWrite(pin_led_sharp, HIGH);
   setPwmD(constrain(getPwmD(), -255, 0));
   setPwmG(constrain(getPwmG(), -255, 0));
   //pwmG = constrain(pwmG, -255, 0);
   //pwmD = constrain(pwmD, -255, 0);
   //arretMoteur();
 }else{
   digitalWrite(pin_led_sharp, LOW);
   //demarrageMoteur();
 }
}
