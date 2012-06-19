import procontroll.*;
import java.io.*;


ControllIO controll;
ControllDevice device;
ControllStick stick;
ControllSlider sliderX;
ControllSlider sliderY;
ControllSlider sliderZ;
//stick = new ControllStick(sliderX, sliderY);


void initJoypad() {
  controll = ControllIO.getInstance(this);
  controll.printDevices();
  //try{
  device = controll.getDevice("Controller (XBOX 360 For Windows)");
  //}catch{
  //println("PAS DE MANETTE CONNECTE XBOX 360"); 
  //}
  device.printSticks();
  device.printSliders();
  device.printButtons();
  device.setTolerance(0.05f);

  sliderX = device.getSlider(1);
  sliderY = device.getSlider(0);
  sliderZ = device.getSlider(4);
  //sliderX.setMultiplier(255);
  //sliderY.setMultiplier(255);  

  stick = new ControllStick(sliderX, sliderY);
}


void acquisitionJoypad() {
  //facteur multipliateur
  //facteur = (255*sliderZ.getValue() + 255)/2; linux
  facteur = -255*sliderZ.getValue();
  println(facteur);
  puissance =  2*facteur*sqrt(stick.getX()*stick.getX() + stick.getY()*stick.getY() ) ;
  coeff = 0;
  //Angle:
  float angle = -atan2(stick.getY(), stick.getX());
  pwmD = 0;
  pwmG = 0;
  if (angle >= 0 && angle<1.57) {
    pwmG = int(puissance/2);
    pwmD = int(  -cos(angle*2)*puissance/2  );
  }
  if (angle <= 0 && angle>-1.57) {
    pwmD = -int(puissance/2);
    pwmG = int( cos(angle*2)*puissance/2  );
  }
  if (angle > 1.57 && angle <= 3.14) {
    pwmD = int(puissance/2);
    pwmG = int(  -cos(angle*2)*puissance/2  );
  }
    if (angle < -1.57 && angle >= -3.15) {
    pwmG = -int(puissance/2);
    pwmD = int(  cos(angle*2)*puissance/2  );
  }
  pwmG = int(constrain(pwmG, -facteur, facteur));
  pwmD = int(constrain(pwmD, -facteur, facteur));
}

void affichageStick() {
  //CADRES:
  fill(0,0,0);
  rectMode(CENTER); 
  smooth();
  int pwm_width = 50;

  //Central
  rect(width/2, height/2, facteur*2, facteur*2);
  //PWMG
  rect(width/10, height/2, pwm_width, 255*2);
  //PWMD
  rect(width - width/10, height/2, pwm_width, 255*2);

  //curseur
  fill(0, 0, 255);
  //Central
  int stickX = int(constrain(stick.getX()*facteur, -facteur, facteur));
  int stickY = int(constrain(stick.getY()*facteur, -facteur, facteur));
  ellipse(width/2 + stickX, height/2 + stickY, 20, 20);
  //PWMG:
  rect(width/10, height/2 - pwmG, pwm_width, 20);
  //PWMD:
  rect(width - width/10, height/2 - pwmD, pwm_width, 20);
}

