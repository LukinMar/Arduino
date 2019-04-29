
const int c = 261;
const int d = 294; 
const int e = 329;
const int f = 349;
const int g = 391; 
const int a = 440; 
const int b = 466;
const int cH = 523; 

const int buzzerPin = 10;
const int ledPin1 = 8;
const int ledPin2 = 7;

int counter = 0;
 
void setup(){
  pinMode(buzzerPin, OUTPUT);
}
  
void loop(){
  hinoFlamengo();
}
 
void beep(int note, int duration){
  //Play tone
  tone(buzzerPin, note, duration);
 
  //Play LED
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone
  noTone(buzzerPin);
 
  delay(50);
 
  counter++;
}
 
void hinoFlamengo()
{
  
  beep(e, 200);
  beep(e, 200);    
  beep(f, 400);
  beep(e, 200);
  beep(g, 400);
  beep(d, 400); 
  
  delay(200);
  
  beep(e, 200);
  beep(g, 400);    
  beep(e, 200);
  beep(d, 200);
  beep(c, 400);

  delay (400);
  
  beep(c, 200);
  beep(d, 200);    
  beep(c, 200);
  beep(a, 400);
  beep(f, 200);
  beep(cH, 500);
  beep(a, 200);
  beep(g, 400);

  delay (400);

  beep(c, 200);
  beep(d, 200);    
  beep(c, 200);
  beep(a, 400);
  beep(f, 200);
  beep(cH, 500);

  delay (300);
  
  beep(b, 200);
  beep(g, 200);    
  beep(e, 200);
  beep(b, 400);

  delay (300);

  beep(a, 200);
  beep(f, 200);    
  beep(d, 200);
  beep(a, 400);
  beep(f, 400);

  delay (200);

  beep(g, 200);
  beep(e, 200);
  beep(c, 200);
  beep(a, 400);
  
  delay (200);

  beep(e, 400);
  beep(g, 400);    
  beep(f, 400);
  beep(c, 400);
  beep(d, 200);
  beep(e, 400);

  delay (300);

  beep(e, 200);
  beep(e, 200);    
  beep(f, 400);
  beep(e, 200);
  beep(g, 400);
  beep(d, 400);
  
  delay(100);
  
  beep(f, 200);
  beep(e, 200);  
  beep(d, 200);
  beep(g, 400);
  beep(e, 200);
  beep(c, 400);

  delay (2000);
}
