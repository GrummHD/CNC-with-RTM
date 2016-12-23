#define llm 1
#define mn 60
float Xpoint = 0;
float Ypoint = 0;
float Zpoint = 0;
float Feedrate1;
const int Eilgang = 450;
  float Feedrateo;
  boolean verbose = false;
float Speed;
char* indexS;
struct point {
  float x;
  float y;
  float z;
};
int StepDelay = 0;
struct point actuatorPos;
int Gactivation=0;
boolean cs = 1;
#define stepsperMillimeterX  320
#define stepsperMillimeterY  320
#define stepsperMillimeterZ  320
#define Xmin  0
#define Xmax  300
#define Ymin  0
#define Ymax  250
#define Zmin  0
#define Zmax  20
#define d 1
const int stpx =2;
const int sttpx =3;
const int stpy =4;
const int sttpy=5;
const int stpz =11;
const int sttpz =12;
float Xpos = Xmin;
float Ypos = Ymin;
float Zpos = Zmax;
const int lol1 = 5;
const int lol2 = 6;
const int lol4 = 11;
const int enx = 8;
const int eny = 9;
const int enz = 13;
#define Baudrate 115200
#define Enableall 1
#define StepsRevo = 200;
#define Spindel 6
#define LINE_BUFFER_LENGTH 512
 #define rampup
//all what is needed for interrupts here:
#define OVERFLOW_INTER 100
#define CBufflength 6
volatile unsigned long i;
volatile float input_line[4][CBufflength]; 
//Buffer 
  int Write_PointerY;
volatile int Read_Pointer;
volatile float ISRX;
volatile float ISRY;
volatile float ISRZ;
volatile float ISRPAUSE;
volatile unsigned long cx;
volatile unsigned long cy;
volatile unsigned long cz;
volatile int dir;
volatile int fx;
volatile int fy;
volatile int fz;
volatile unsigned long timer_var;
volatile byte outx;
volatile byte outy;
volatile byte outz;
volatile byte out;
#define XOUT B00000001;
#define YOUT B00000010;
#define ZOUT B00000100;
