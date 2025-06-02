/*
 GIOIA - glittering fashion

gioia_rgb_dimmer.ino

dimmer animations for Gioia 8 RGB leds type
Date 24/05/2025 created by Sergio Ghirardelli (first release)

*/

int enablepin = 1; //pin5 (PWM)
int latchPin = 3; //pin2
int clockPin = 4; //pin3
int dataPin = 0; //pin6
int butPin = 2;
long randNumber;
bool pippo;
uint32_t led;
int k;
int j;
bool but, but_p, but_mem;
int prog;
int min_light, max_light, dim_speed, off_time;

void setup() 
{
//set pins to output so you can control the shift register
pinMode(enablepin, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(butPin, INPUT_PULLUP);
//pinMode(LED_BUILTIN, OUTPUT);
//randomSeed(analogRead(A0));
pippo = false;
prog = 1;
led = 0;
k=0;
led_clear();
analogWrite(enablepin, 250);
min_light= 255;
max_light= 230;
dim_speed= 75;
off_time= 250;
}

void loop()
{




switch (prog) {
  case 1: //red dim
   dim_all1 (min_light,max_light,dim_speed,off_time,1);   
   break;
  
  case 2: //all red
  analogWrite(enablepin, 250);
   for (int h = 0; h < 8; h++) {
      led_write(h,1);
      exec();
      } 
  break;
    
  case 3: //green dim
  dim_all1 (min_light,max_light,dim_speed,off_time,2);  
  break;
    
  case 4://all green
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,2);
      exec();
      }
    break;

  case 5: //blue dim
  dim_all1 (min_light,max_light,dim_speed,off_time,3); 
  break;
  
  case 6://all blue
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,3);
      exec();
      }
    break; 

  case 7: //yellow dim
  dim_all1 (min_light,max_light,dim_speed,off_time,4);  
  break;
  
  case 8://all yellow
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,4);
      exec();
      }
    break;

  case 9: //fuchsia dim
  dim_all1 (min_light,max_light,dim_speed,off_time,5);  
  break;
  
  case 10://all fuchsia
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,5);
      exec();
      }
    break;

  case 11: //aqua dim
  dim_all1 (min_light,max_light,dim_speed,off_time,6);  
  break;
  
  case 12://all aqua
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,6);
      exec();
      }
    break;

  case 13: //white dim
  dim_all1 (min_light,max_light,dim_speed,off_time,7); 
  break;
  
  case 14://all white
  analogWrite(enablepin, 250);
    for (int h = 0; h < 8; h++) {
      led_write(h,7);
      exec();
      }
    break;
    
}




}

void led_clear() {
  led = 0;
  exec(); 
}


void led_write (int x, int color) {
  int n;
  if (x==0) {n=2;}
  else if (x==1) {n=4;}
  else if (x==2) {n=3;}
  else if (x==3) {n=5;}
  else if (x==4) {n=6;}
  else if (x==5) {n=7;}
  else if (x==6) {n=0;}
  else if (x==7) {n=1;}
   
  if (color==0) { //led off
    bitClear (led,0+(n*3));
    bitClear (led,1+(n*3));
    bitClear (led,2+(n*3));
    }
  else if (color==1) { //led red
    bitSet (led,0+(n*3));
    bitClear (led,1+(n*3));
    bitClear (led,2+(n*3));
    }
  else if (color==2) { //led green
    bitClear (led,0+(n*3));
    bitSet (led,1+(n*3));
    bitClear (led,2+(n*3));
    }
  else if (color==3) { //led blue
    bitClear (led,0+(n*3));
    bitClear (led,1+(n*3));
    bitSet (led,2+(n*3));
    }
  else if (color==4) { //led yellow
    bitSet (led,0+(n*3));
    bitSet (led,1+(n*3));
    bitClear (led,2+(n*3));
    }
  else if (color==5) { //led fuchsia
    bitSet (led,0+(n*3));
    bitClear (led,1+(n*3));
    bitSet (led,2+(n*3));
    }
   else if (color==6) { //led aqua
    bitClear (led,0+(n*3));
    bitSet (led,1+(n*3));
    bitSet (led,2+(n*3));
    } 
   else if (color==7) { //white
    bitSet (led,0+(n*3));
    bitSet (led,1+(n*3));
    bitSet (led,2+(n*3));
    } 
  }

void exec(){
    button();
    digitalWrite(latchPin, 0);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, led >> 16); 
    shiftOut(dataPin, clockPin, MSBFIRST, led >> 8);  
    shiftOut(dataPin, clockPin, MSBFIRST, led);       
    digitalWrite(latchPin, HIGH);
}


void random_colors(int spd1) { //each led lights with a random color, with the speed you want
for (int j = 0; j < 8; j++) {
     int randomcolor = random(1,8);
    led_write(j,randomcolor);
    exec();    
    delay(spd1);
    }
}


void bar1 (int spd1, int color) { //bargraph
led_clear();
for (int j = 0; j < 8; j++) {
    led_write(j,color);
    exec();    
    delay(spd1);
    }
for (int j = 0; j < 8; j++) {
    led_write(j,0);
    exec();    
    delay(spd1);
    }  
}

void scroll1 (int spd1, int color, bool dir) { //leds light on one by one. dir=false means clockwise
led_clear();
    if (!dir) {
         for (int y = 0; y < 8; y++) {
          if (y>0) {led_write(y-1,0);}
          led_write(y,color);
          exec();    
          delay(spd1);
          }
    }  
    else {
         for (int y = 7; y >= 0; y--) {
          if (y<7) {led_write(y+1,0);}
          led_write(y,color);
          exec();    
          delay(spd1);
          }
    }      
}

void paint_all (int color) {
        for (int j = 0; j < 8; j++) {
          led_write(j,color);
          exec();   
        }  
}

void dim_all1 (int led_min, int led_max, int spd_dim, int spd_clr, int color){
      for (int j = led_min; j > led_max; j--) {
        analogWrite(enablepin, j);
        paint_all(color);
        button();
        delay(spd_dim);
        }
      led_clear();
      delay(spd_clr);
}

void all_colors_scrolling (int spd1){
     
     for (int j = 1; j < 8; j++) {
          for (int x = 0 ; x < 8; x++) {
            int y = x-j;
            if (y<1) {y=x-j+8;}
            led_write(x,y);
            exec();  
            }
             
          delay(spd1);
          }
}

/*PosTrig - function that return the positive edge of a boolean variable*/

bool PosTrig (bool in, bool &memory)
{
if (!in) { memory = false;}
if (in && !memory) { memory = true; return 1; } 
else { return 0; } 
}


/*NegTrig - function that return the negative edge of a boolean variable*/

bool NegTrig (bool in, bool &memory)
{
if (in) { memory = true;}
if (!in && memory) { memory = false; return 1; } 
else { return 0; } 
}

void button() {
 but = !digitalRead(butPin);
but_p = PosTrig(but, but_mem);

if (but_p) {
  prog++;
  if (prog > 14) {prog =1;}
  k=0;
  } 
}
