#include "Speed.h"
#include "Buffer.h"
void CalcMovements(float x, float y, float z,float Feedratein){
	byte direction;
	float Dx;
	float Dy;
	float Dz;
	Feedratein = feedrate(Feedratein);
if (Gactivation != 1)
{

 Dx = actuatorPos.x - x;
   Dy = actuatorPos.y - y;
   Dz = actuatorPos.z - z;
  Dx = abs(Dx* stepsperMillimeterX);
  Dy = abs(Dy* stepsperMillimeterY);
  Dz = abs(Dz* stepsperMillimeterZ);
}
else{
	Dx = abs(x* stepsperMillimeterX);
	Dy = abs(y* stepsperMillimeterY);
	Dz = abs(z* stepsperMillimeterZ);
	
}
if (Dx >= Dy && Dx >= Dz)
{
	direction =1;
} 
 else if ( Dy>=Dx&&Dy>=Dz)
{
	direction = 2;
}
else if ( Dz>= Dx && Dz >= Dy )
{
	direction = 3;
}
CircularBuffer(Dx,Dy,Dz,Feedratein, direction);

}