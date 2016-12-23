/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include "Pref.h"
#include "Boot.h"
#include "G_commands.h"
#include "M_commands.h"
#include "Parseandinterpret.h"

//Beginning of Auto generated function prototypes by Atmel Studio
ISR(TIMER1_COMPA_vect );
//End of Auto generated function prototypes by Atmel Studio


void setup() {
cli();
TCCR1A = 0;
TCCR1B = 0;
TCNT1 = 0;
OCR1A = OVERFLOW_INTER;
TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);
TCCR1B |= (1<<WGM12);
TIMSK1 |= (1<<OCIE1A);
sei();
DDRB =	B11111111;
PORTB = B00000000;
Serial.begin(Baudrate);
Boot();
}


void loop() {
  delay(200);
  char line[ LINE_BUFFER_LENGTH ];
  char c;
  int lineIndex;
  bool lineIsComment, lineSemiColon;
  lineIndex = 0;
  lineSemiColon = false;
  lineIsComment = false;
  while(1){

while ( Serial.available() > 0 ) {

      c = Serial.read();
      if (( c == '\n') || (c == '\r') ) {             // End of line reached
        if ( lineIndex > 0 ) {                        // Line is complete. Then execute!
          line[ lineIndex ] = '\0';                   // Terminate string
          if (verbose) {
           
          }
         processIncomingLine( line, lineIndex );

          lineIndex = 0;
        }
        else {
          // Empty or comment line. Skip block.
        }
        lineIsComment = false;
        lineSemiColon = false;
cli();

        Serial.println("ok");

        sei();

      }
      else {
        if ( (lineIsComment) || (lineSemiColon) ) {   // Throw away all comment characters
          if ( c == ')' )  lineIsComment = false;     // End of comment. Resume line.
        }
        else {
          if ( c <= ' ' ) {                           // Throw away whitespace and control characters
          }
          else if ( c == '/' ) {                    // Block delete not supported. Ignore character.
          }
          else if ( c == '(' ) {                    // Enable comments flag and ignore all characters until ')' or EOL.
            lineIsComment = true;
          }
          else if ( c == ';' ) {
            lineSemiColon = true;
          }
          else if ( lineIndex >= LINE_BUFFER_LENGTH - 1 ) {
            Serial.println( "ERROR - lineBuffer overflow" );
            lineIsComment = false;
            lineSemiColon = false;
          }
          else if ( c >= 'a' && c <= 'z' ) {        // Upcase lowercase
            line[ lineIndex++ ] = c - 'a' + 'A';
          }
          else {
            line[ lineIndex++ ] = c;
          }
        }
      }
   }
}
}
ISR(TIMER1_COMPA_vect){
  i++;
  digitalWrite ()
  if(cx >= ISRX || cy >= ISRY || cz >= ISRZ){
   ISRX = input_line[Read_Pointer][0];
   ISRY = input_line[Read_Pointer][1];
   ISRZ = input_line[Read_Pointer][2];
   ISRPAUSE = input_line[Read_Pointer][3];
   dir = input_line[Read_Pointer][4];
   cy = 0;
   cx = 0;
   cz = 0;
   if (Read_Pointer >= CBufflength )
   { Read_Pointer=0;
	  
   }
   else{
	   
	   Read_Pointer++;
	   
   }
   
  } 
  else if(timer_var==true){
	  
switch ( dir){


	case 1:
	 { 
		 cx++;
		 fy = fy - ISRY;
	  fz = fz - ISRZ;
	  outx = XOUT;
	  if ( fy <= 0 && ISRY > 0)
	  { 

		outy = YOUT;
		  fy = fy + ISRX;
	  }
	  if  (fz < 0 && ISRZ > 0) {
		  
outz = ZOUT;

		  fz = fz + ISRX;
	  }
	  
	  out= outx | outy | outz;
	  PORTB = out;
break;

  }
  
  
  case 2:
  
  {
	  cy++;
	   fx = fx - ISRX;
	  fz = fz - ISRZ;
	  outy = YOUT
	  if ( fx <= 0 && ISRX > 0)
	  { 
	  outx = XOUT;


		  fx = fx + ISRY;
	  }
	  if  (fz < 0 && ISRZ > 0) {
		  fz = fz + ISRY;
		  outz = ZOUT;
	  }  

  PORTB = out;

  
break;
  }

  
  case 3:
  {
	  cz++;
	   fx = fx - ISRX;
	  fy = fy - ISRX;
	  outz = ZOUT;
	  if ( fx <= 0 && ISRX > 0)
	  { 


		  fx = fx + ISRZ;	
		  outx = XOUT;

	  }
	  if  (fy < 0 && ISRZ > 0) {



		  fy = fy + ISRZ;
		  outy = YOUT;
	  }

  PORTB = out;
	  

break;
  }

  }
  }
  }
	  // Bresenham
	  
	    /* 
		
		
		 cy = 0;
		 cx = 0;
		 cz = 0;

		int overx = 0;
		int overy = 0;
		float x0 = Xpos;
		float y0 = Ypos;
		float z0 = Zpos;
		if (ax < 0) {
			sx = 0; //Vorwärts? Rückwärts? gar nicht?
		}
		else if ( ax == 0) {
			sx = 0;
		}
		else {
			sx = 1;
		}
		if (ay < 0) {
			sy = 0;
		}
		else if ( ay == 0) {
			sy = 0;
		}
		else {
			sy = 1;
		}
		if (az < 0) {
			sz = 0;
		}
		else if ( az == 0) {
			sz = 0;
		}
		else {
			sz = 1;
		}

		int ix = 0;
		int iy = 0;
		int iz = 0;
		float dx = abs(ax * stepsperMillimeterX);
		float dy = abs(ay * stepsperMillimeterY);
		float dz = abs(az * stepsperMillimeterZ);
		if ( dx == 0 && dy == 0 && dz == 0) {}
		else {
			if ( dx >= dy && dx >= dz) {
				float fy = dx / 2;
				float fz = dx / 2;
				Serial.println(Feedrate1);
				Serial.println("x");

				for (unsigned long i = 0; i < dx; i++) {


					//                digitalWrite(enx, 0);

					st(stpx, sx, Feedrate1, sttpx);
					//        digitalWrite(enx, 1);


					//        int p =  i % 10;
					//        if (p == 0) {
					//          reupdatepos(ix, i, iz);
					//        }
					fy = fy - dy;
					fz = fz - dz;
					if ( fy <= 0 && dy > 0)
					{ iy++;
						//          digitalWrite(eny, 0);

						st(stpy, sy, Feedrate1, sttpy);
						//          digitalWrite(eny, 1
						//                      );


						fy = fy + dx;
					}
					if  (fz < 0 && dz > 0) {
						iz++;
						//          digitalWrite(enz, 0);
						st(stpz, sz, Feedrate1, sttpz);
						//          digitalWrite(enz, 1);


						fz = fz + dx;
					}

				}

			}

			if (dy > dx && dy > dz) {

				float fx = dy / 2;
				float fz = dy / 2;
				Serial.println(Feedrate1);
				Serial.println("Y");

				for ( unsigned long i = 0; i < dy; i++) {
					//        digitalWrite(eny, 0);


					st(stpy, sy, Feedrate1, sttpy);
					//        digitalWrite(eny, 1);


					//        int p =  i % 10;
					//        if (p == 0) {
					//          reupdatepos(ix, i, iz);
					//        }
					fx = fx - dx;
					fz = fz - dz;
					if ( fx <= 0 && dx > 0)
					{ ix++;
						//          digitalWrite(enx, 0);

						st(stpx, sx, Feedrate1, sttpx);
						//          digitalWrite(enx, 1);

						fx = fx + dy;
					}
					if  (fz < 0 && dz > 0) {
						iz++;
						//          digitalWrite(enz, 0);
						st(stpz, sz, Feedrate1, sttpz);
						//          digitalWrite(enz, 1);
						fz = fz + dy;
					}

				}

			}

			if (dz > dx && dz > dy) {

				float fx = dy / 2;
				float fy = dy / 2;
				Serial.println(Feedrate1);
				Serial.println("Z");


				for ( unsigned long i = 0; i < dz; i++) {
					//        digitalWrite(enz, 0);

					st(stpz, sz, Feedrate1, sttpz);
					//        digitalWrite(enz, 1);

					//        int p =  i % 10;
					//        if (p == 0) {
					//          reupdatepos(ix, i, iz);
					//        }
					fx = fx - dx;
					fy = fy - dy;
					if ( fx <= 0 && dx > 0)
					{ ix++;
						//          digitalWrite(enx, 0);

						st(stpx, sx, Feedrate1, sttpx);
						//          digitalWrite(enx, 1);

						fx = fx + dz;
					}
					if  (fy < 0 && dz > 0) {
						iy++;
						//          digitalWrite(eny, 0);


						st(stpy, sy, Feedrate1, sttpy);
						//          digitalWrite(eny, 1);

						fy = fy + dz;
					}

				}
			}






		}
		*/
  
  

		
  

  


