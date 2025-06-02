/*
 GIOIA - glittering fashion

gioia_r_mixbutton.ino

Animations selected by function button for Gioia 21 monochrome leds type
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
int n0;
int rain0,rain1,rain2,rain3,rain4;
bool h0;
bool but, but_p, but_mem;
int prog;
bool paint;
bool start;

//oscillator 0
unsigned long t0;
unsigned long speed0;
bool a0,b0;

//oscillator 1
unsigned long t1;
unsigned long speed1;
bool a1,b1;


//pos trig0
bool p0,p0_mem;

//asymmetric oscillator 
unsigned long elapsed_time2;
unsigned long count_time2; 
bool time2_q;
unsigned long elapsed_time3;
unsigned long count_time3; 
bool time3_q;
unsigned long speed2, speed3;


int y0,y1,y2,y3,y4;

void(* Riavvia)(void) = 0; //Sketch Reset procedure


//-----------------------------------------------------------------------------------------------------------

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
paint=true;
b0=false;
t0=0;
n0=0;
rain0=-1;
rain1=-4;
rain2=0;
rain3=-3;
rain4=-2;
h0=true;
speed0=10000;
start=false;
}

//-----------------------------------------------------------------------------------------------------------

void loop()
{
//oscillator 0
a0=false;
if (millis() - t0 >= speed0) 
      {
       a0=true;
       b0=!b0;
       t0 += speed0;
      }

//oscillator 1
a1=false;
if (millis() - t1 >= speed1) 
      {
       a1=true;
       b1=!b1;
       t1 += speed1;
      }

button();


if (prog==1) {
  analogWrite(enablepin, 240);
  brilla(15,80);
  }


else if (prog==2) {
  speed0 = 1500;
  speed1 = 40;
  analogWrite(enablepin, 240);
  if (a1) {
       vert (n0,paint);
       n0++;
       if (n0>4) {
        n0=0;
        paint=!paint;
        }
      }
  }
  
else if (prog==3) {
  speed0 = 1500;
  speed1 = 40;
  analogWrite(enablepin, 240);
  if (a1) {
       oriz (n0,paint);
       n0++;
       if (n0>4) {
        n0=0;
        paint=!paint;
        }
      }
   } 

else if (prog==4) {
  speed0 = 1500;
  speed1 = 40;
  analogWrite(enablepin, 240);
  if (a1) {
       obli_sx (n0,paint);
       n0++;
       if (n0>6) {
        n0=0;
        paint=!paint;
        }
      }
  } 

else if (prog==5) {
  speed0 = 1500;
  speed1 = 40;
  analogWrite(enablepin, 240);
  if (a1) {
       obli_dx (n0,paint);
       n0++;
       if (n0>6) {
        n0=0;
        paint=!paint;
        }
      }
   } 

else if (prog==6) {
  speed0 = 5000;
  speed1 = 70;
  
  if (a1) {
       int dim;
       if (h0) {dim =254-n0;}
       else {dim =245+n0;}
       analogWrite(enablepin, dim);
       led_full();       
       n0++;
       if (n0>10) {
        n0=0;
        h0=!h0;
        }
      }
   } 

else if (prog==7) {
  speed0 = 5000;
  unsigned long rain_speed = 75;
  rain(0,rain0,rain_speed,false);
  rain(1,rain1,rain_speed,false);
  rain(2,rain2,rain_speed,false);
  rain(3,rain3,rain_speed,false);
  rain(4,rain4,rain_speed,false);
   } 

else if (prog==8) {
  speed2 = 750;
  speed3 = 100;
  
  //asymmetric oscillator 
  time2_q = TON (!time3_q, speed2, elapsed_time2, count_time2);
  time3_q = TON (time2_q, speed3, elapsed_time3, count_time3);
  p0 =  PosTrig (time2_q, p0_mem);
  analogWrite(enablepin, 240);
  if (time3_q) {
         if (n0==0) {_G();}
         else if (n0==1) {_I();}
         else if (n0==2) {_O();}
         else if (n0==3) {_I();}
         else if (n0==4) {_A();}
         else if (n0==5) {_heart();}
         n0++;
         if (n0>5) {n0=0;}
         }
   if (p0) {led_clear();}
      
  } 

}

//-----------------------------------------------------------------------------------------------------------

void led_clear() {
  led = 0;
  exec(); 
}

//-----------------------------------------------------------------------------------------------------------

void led_full() {
  led = 16777215;
  exec(); 
}

//-----------------------------------------------------------------------------------------------------------

void pix (int x, int y, bool s) {
  int who [5][5] {
        {1,4,14,13,2},
        {0,5,11,8,15},
        {7,6,12,10,9},
        {19,17,21,23,16},
        {3,22,20,18,1},
        };
  int who_is = who[y][x];
  if (s) {
         bitSet (led,who_is);
         exec();
         }
  else {
        bitClear (led,who_is);
        exec();
        }
}

//-----------------------------------------------------------------------------------------------------------

void vert (int x, bool s) {
    for (int j = 0; j < 5; j++) {
    pix (x,j,s);
    exec(); 
    }
}

//-----------------------------------------------------------------------------------------------------------

void oriz (int y, bool s) {
  for (int j = 0; j < 5; j++) {
    pix (j,y,s);
    exec();
  }
}

//-----------------------------------------------------------------------------------------------------------

void obli_sx (int j, bool s) {
  if (j==0) { 
    pix(0,1,s);
    pix(1,0,s);
    }
  if (j==1) { 
    pix(0,2,s);
    pix(1,1,s);
    pix(2,0,s);
    }
  if (j==2) { 
    pix(0,3,s);
    pix(1,2,s);
    pix(2,1,s);
    pix(3,0,s);
    }
    if (j==3) { 
    pix(1,3,s);
    pix(2,2,s);
    pix(3,1,s);
    }
    if (j==4) { 
    pix(1,4,s);
    pix(2,3,s);
    pix(3,2,s);
    pix(4,1,s);
    }
    if (j==5) { 
    pix(2,4,s);
    pix(3,3,s);
    pix(4,2,s);
    }
    if (j==6) { 
    pix(3,4,s);
    pix(4,3,s);
    }
  exec();
}

//-----------------------------------------------------------------------------------------------------------

void obli_dx (int j, bool s) {
  if (j==0) { 
    pix(3,0,s);
    pix(4,1,s);
    }
  if (j==1) { 
    pix(2,0,s);
    pix(3,1,s);
    pix(4,2,s);
    }
  if (j==2) { 
    pix(1,0,s);
    pix(2,1,s);
    pix(3,2,s);
    pix(4,3,s);
    }
    if (j==3) { 
    pix(1,1,s);
    pix(2,2,s);
    pix(3,3,s);
    }
    if (j==4) { 
    pix(0,1,s);
    pix(1,2,s);
    pix(2,3,s);
    pix(3,4,s);
    }
    if (j==5) { 
    pix(0,2,s);
    pix(1,3,s);
    pix(2,4,s);
    }
    if (j==6) { 
    pix(0,3,s);
    pix(1,4,s);
    }
  exec();
}

//-----------------------------------------------------------------------------------------------------------
void _A(){
led = 13006192; //lettera A
exec(); 
}

//-----------------------------------------------------------------------------------------------------------
void _B(){
led = 13784432; //lettera B
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _C(){
led = 5660784; //lettera C
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _D(){
led = 13780336;  //lettera D
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _E(){
led = 5664880;  //lettera E
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _F(){
led = 4354160;  //lettera F
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _G(){
led = 14050416; //lettera G
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _H(){
led = 12989808; //lettera H
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _I(){
led = 7632912; //lettera I
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _J(){
led = 14034176;  //lettera J
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _K(){
led = 12988784;  //lettera K
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _L(){
led = 5636208; //lettera L
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _M(){
led = 12987760;  //lettera M
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _N(){
led = 13002096;  //lettera N
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _O(){
led = 14050672; //lettera O
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _P(){
led = 4355440; //lettera P
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _Q(){
led = 10904944;  //lettera Q
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _R(){
led = 13005168; //lettera R
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _S(){
led = 13923440;  //lettera S
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _T(){
led = 3176464;  //lettera T
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _U(){
led = 14034288;  //lettera U
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _V(){
led = 9577840;  //lettera V
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _W(){
led = 15082864; //lettera W
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _X(){
led = 12988720; //lettera X
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _Y(){
led = 3159408; //lettera Y
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _Z(){
led = 5665040; //lettera Z
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _heart(){
led = 9611921; //simbolo cuore
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _esclamativo(){
led = 1071104; //simbolo !
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _apostrofo(){
led = 18432; //simbolo '
exec(); 
}
//-----------------------------------------------------------------------------------------------------------
void _smile(){
led = 6103056; //simbolo smile
exec(); 
}
//-----------------------------------------------------------------------------------------------------------

void brilla(int res, int time1){
    speed1 = time1;
    if (a1){
        led_full();
        for (int j = 0; j < res; j++) {
            int a = random (0,5);
            int b = random (0,5);
            int c = random (240, 255);
            analogWrite(enablepin, c);
            pix (a,b,false);
            
          }
    }
}

//-----------------------------------------------------------------------------------------------------------

void rain (int x, int &y, unsigned long rain1_s0, bool doppio){
   speed1=rain1_s0;
   //int gap;
   if (a1){
     vert(x,false);
     pix (x,y,true);
     //gap = y +2;
     //if (doppio && (gap<5)) {pix (x,gap,true); }
     y++;
     if (y>4) {y=0;}
   }
    
}

//-----------------------------------------------------------------------------------------------------------


void exec(){
    digitalWrite(latchPin, 0);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, led >> 16); 
    shiftOut(dataPin, clockPin, MSBFIRST, led >> 8);  
    shiftOut(dataPin, clockPin, MSBFIRST, led);       
    digitalWrite(latchPin, HIGH);
}

//-----------------------------------------------------------------------------------------------------------

/*PosTrig - function that return the positive edge of a boolean variable*/

bool PosTrig (bool in, bool &memory)
{
if (!in) { memory = false;}
if (in && !memory) { memory = true; return 1; } 
else { return 0; } 
}

//-----------------------------------------------------------------------------------------------------------

/*NegTrig - function that return the negative edge of a boolean variable*/

bool NegTrig (bool in, bool &memory)
{
if (in) { memory = true;}
if (!in && memory) { memory = false; return 1; } 
else { return 0; } 
}

//-----------------------------------------------------------------------------------------------------------

void button() {
 but = !digitalRead(butPin);
but_p = PosTrig(but, but_mem);

if (but_p) {
  n0=0;
  prog++;
  if (prog > 8) {
    n0=0;
    prog =1;
    }
  k=0;
  } 
}

//-----------------------------------------------------------------------------------------------------------
/* TON Timer function.*/

bool TON(bool en, unsigned long preset, unsigned long &elapsed, unsigned long &count){
 if (en==true)
{
  if (elapsed<preset)
  {
    elapsed=millis()-count;
    return false;
  }
  else
  {
    elapsed=preset;
    return true; 
  }
}
else
{
  elapsed=0;
  count=millis();
  return false;
}
}
