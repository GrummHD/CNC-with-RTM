/*>In this File we are parsing the String we have received in the loop function */
#include "G_commands.h"
#include "M_commands.h"
#include "Speed.h"
#include "Buffer.h"
void processIncomingLine( char* line, int charNB ) {
  struct point G91;
  G91.x = 0;
  G91.y = 0;
  G91.z = 0;
  int currentIndex = 0;
  char buffer[ 64 ];                                 // Hope that 64 is enough for 1 parameter
  struct point newPos;
  newPos.x = 0.0;
  newPos.y = 0.0;
  newPos.z = 0.0;
  int Vorschub;
  float Feedrate = 0;
  //Serial.println("ok");
  char* indexSX = strchr( line + currentIndex, 'X' );
  newPos.x = atof( indexSX + 1);

  char* indexSY = strchr( line + currentIndex, 'Y' );
  newPos.y = atof( indexSY + 1);


  char* indexSZ = strchr( line + currentIndex, 'Z' );
  newPos.z = atof( indexSZ + 1);


  char* indexF = strchr(line + currentIndex, 'F');
  Feedrate = atof (indexF + 1);
  if (indexF <= 0)
  {
    Feedrate = Feedrateo;

  }

  if ( indexSX <= 0)
  {
    newPos.x  = actuatorPos.x;
    G91.x = 1;
  }
  if (indexSY <= 0) {
    newPos.y = actuatorPos.y;
    G91.y = 1;
  }
  if (indexSZ <= 0) {
    newPos.z = actuatorPos.z;
    G91.z = 1;
  }

  float dx = actuatorPos.x - newPos.x;
  float dy = actuatorPos.y - newPos.y;
  float dz = actuatorPos.z - newPos.z;

  while ( currentIndex < charNB ) {

    switch ( line[ currentIndex++ ] ) {              // Select command, if any


      case 'G': {
          buffer[0] = line[ currentIndex++ ];          // /!\ Dirty - Only works with 2 digit commands
          buffer[1] = line[ currentIndex++ ];
          buffer[2] = '\0';
          //buffer[1] = '\0';

          switch ( atoi( buffer ) ) { //selectG command
            case 02: break;
            case 00:
              { Feedrate1 = feedrate(Eilgang);

                break;
              }
            case 01:
              { Feedrate1 = feedrate(Feedrate);

                break;
              case 91:
                if (G91.x == 1) {
                  newPos.x = 0;
                }
                if (G91.y == 1) {
                  newPos.y = 0;
                }
                if (G91.z == 1) {
                  newPos.z = 0;
                }

                Serial.println(G91.x);
                Serial.println(newPos.y);
                Serial.println(newPos.z);
/*                 drawLine(newPos.x, newPos.y, newPos.z);
 */                actuatorPos.x = actuatorPos.x + newPos.x;
                actuatorPos.y = actuatorPos.y + newPos.y;
                actuatorPos.z = actuatorPos.z + newPos.z;
                Feedrate1 = Feedrate;
                Serial.println(actuatorPos.x);
                Serial.println(actuatorPos.y);
                Serial.println(actuatorPos.z);


                Gactivation = 1;
                break;

              }
            default:
              {}
          }
          break;
        }
      case 'M': {
          buffer[0] = line[ currentIndex++ ];        // /!\ Dirty - Only works with 3 digit commands
          buffer[1] = line[ currentIndex++ ];
          buffer[2] = line[ currentIndex++ ];
          buffer[3] = '\0';
          switch ( atoi( buffer ) ) {
            case 7:
              break
              ;
            case 114:
              Serial.print( "Absolute position : X = " );
              Serial.print( actuatorPos.x );
              Serial.print( "  -  Y = " );
              Serial.println( actuatorPos.y );
              break;// M114 - Repport position
            case 15: {
                Boot();
                actuatorPos.x = 0.0;
                actuatorPos.y = 0.0;
                actuatorPos.z = 0.0;
                newPos.x = 0.0;
                newPos.y = 0.0;
                newPos.z = 0.0;
                break;
              }
            case 03:
              { Serial.println("on");  //neue Commands hier einfügen
                delay(2000);
                break;
              }
            case 5:
              { Serial.println("off");
                delay(2000);
                break;
              }

              break;
            default:
              Serial.print( "Command not recognized : M");
              Serial.println( buffer );

          }
        }
    } //<Idle,MPos:5.529,0.560,7.000,WPos:1.529,-5.440,-0.000>


  }
  //    if (llm == 1) {
  //      digitalWrite(8, 0);
  //      digitalWrite(9, 0);
  //      digitalWrite(13, 0);
  //
  //    }

  
  if (Gactivation == 0) {
  } Gactivation = 0;
  
  CircleBuffer(dx,dy,dz,Feedrate1);
  
  
  
  //    if (llm == 1) {
  //      digitalWrite(8, 1);
  //      digitalWrite(9, 1);
  //digitalWrite(13, 1);
  //
  //    }
  if (Gactivation == 0) {
    actuatorPos.x = newPos.x;
    actuatorPos.y = newPos.y;
    actuatorPos.z = newPos.z;
  }
  Feedrateo = Feedrate;

}