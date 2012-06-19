
import procontroll.*;
import java.io.*;

ControllIO controll;
ControllDevice device;
ControllStick stick;
ControllButton button;

void setup(){
  size(400,400);
  
  controll = ControllIO.getInstance(this);
  controll.printDevices();
  
  device = controll.getDevice(2);
  device.printSticks();
  device.setTolerance(0.05f);
  
  device.printSliders();
  ControllSlider sliderX = device.getSlider(1);
  ControllSlider sliderY = device.getSlider(0);
  
  stick = new ControllStick(sliderX,sliderY);
  
  //button = device.getButton("Taste 0");
  
  fill(0);
  rectMode(CENTER);
}

float totalX = width/2;
float totalY = height/2;

void draw(){
  background(255);
  
  //if(button.pressed()){
  fill(255,0,0);
 // }else{
  //  fill(0);
  //}
  
  totalX = constrain(totalX + stick.getX(),10,width-10);
  totalY = constrain(totalY + stick.getY(),10,height-10);
  print("X: "); 
  println(stick.getX());
  print("Y: "); 
  println(stick.getY());
  rect(totalX,totalY,20,20);
}
