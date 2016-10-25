
volatile int i;
volatile float input_line[4][6]; 
void setup() {
cli();
TCCR1A = 0;
TCCR1B = 0;
TCNT1 = 0;
OCR1A = 15600;
TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);
TCCR1B |= (1<<WGM12);
TIMSK1 |= (1<<OCIE1A);
sei();
Serial.begin(9600);
}

void loop() {
delay(1000);
Serial.println(i);
}
ISR(TIMER1_COMPA_vect){
  i++;
}



  


