void CircleBuffer(float x, float y, float z, float pause)
{ if (Write_PointerY >= CBufflength)
  {
    Write_PointerY = 0;
  }
  else {
    Write_PointerY++;
  }
  int Write_PointerX;
  input_line[Write_PointerX][Write_PointerY] = x;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = y;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = z;
  Write_PointerX++;
  input_line[Write_PointerX][Write_PointerY] = pause;

Serial.println(input_line[0][Write_PointerY]);
Serial.println(Write_PointerY);
}
