
volatile int i;
void setup() {
cli();
TCCR1A = 0;
TCCR1B = 0;
TCNT1 = 0;
OCR1A = 249;
TCCR1B |= (0<<CS12) | (0<<CS11) | (1<<CS10);
TCCR1B |= (1<<WGM12);
TIMSK1 |= (1<<OCIE1A);
sei();
Serial.begin(9600);
pinMode(13,1);
}

void loop() {

}
ISR(TIMER1_COMP_vect)
{
if(i== 5000);


  
}

