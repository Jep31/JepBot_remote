#include <Chrono.h>

Chrono(){
}

 void start(){
   start_time = millis();
 }
 
  void resume(){
   start_time = millis()
  }
  
  int getTime(){
    return millis()-start_time;
  }

