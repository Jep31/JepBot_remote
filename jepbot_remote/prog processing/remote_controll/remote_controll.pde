
float puissance;
float coeff;
int pwmG;
int pwmD;
float facteur;


void setup() {
  size(1000,600);
  background(255,255,255);
  initJoypad();
  initSerie();
}



void draw() {
  background(facteur,255- facteur,0);
  acquisitionJoypad();
  communication();
  affichageStick();
 
}

