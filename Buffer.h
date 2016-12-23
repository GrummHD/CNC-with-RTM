void CircularBuffer(float x, float y, float z, float pause,  byte direction)

{
 if (Write_PointerY >= CBufflength)
  {
    Write_PointerY = 0;
  }
  else {
    Write_PointerY++;
  }
  int Write_PointerX = 1;
  cli();
  input_line[Write_PointerX][Write_PointerY] = x;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = y;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = z;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = pause;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = direction;
   sei();

}
