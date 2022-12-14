#define CLOCK 3 //D-
#define DATA 4  //D+



void setup()
{
  Serial.begin(9600);
  pinMode(CLOCK, INPUT_PULLUP); //For most keyboards the builtin pullups are sufficient, so the 10k pullups can be omitted
  pinMode(DATA, INPUT_PULLUP);
  //bitSet(PCICR, PCIE2); // Enable pin change interrupts on pin D0-D7
  //bitSet(PCMSK2, CLOCK); // Pin change interrupt on Clock pin
  attachInterrupt(digitalPinToInterrupt(CLOCK), ps2interrupt, FALLING  );

 }


volatile uint8_t bitcount = 0; //số bit đã được đọc, tức là hiện tại đang có trong rawvalue
volatile uint8_t scancode = 0; 
volatile int16_t rawvalue = 0;

volatile unsigned long prevTime = 0;
volatile unsigned long currentTime;
void ps2interrupt()
{
  /*
  bitcount++;
  if (bitcount == 11){
    Serial.print("bits count: ");
    Serial.println(bitcount);
    bitcount = 0;
  }
  */
    uint8_t bit = digitalRead(DATA); //giá trị bit đã đọc được để đưa vào

    currentTime = millis();
    if (currentTime - prevTime > 250) //hết thời gian cho 1 chu kỳ, ở đây có thể xuất hiện bug, read https://www.networktechinc.com/ps2-prots.html https://www.sra.uni-hannover.de/Lehre/WS21/L_BST/doc/ps2.html
    {
        scancode = 0;
        bitcount = 0;
        rawvalue = 0;
    }

    prevTime = currentTime;
    rawvalue |= (bit << bitcount);
    
    bitcount++;
    if (bitcount == 11) //hết 1 gói bits
    {   
        scancode = (rawvalue >> 1) & 0x00ff;
        //chuyển scancode này thành ascii rồi lưu vào buffer. nếu = 0 thì thôi đừng lưu, như vậy thì chỉ có 1 lần nhất là được ghi, lần nhả không ghi
        Serial.println(scancode, HEX);
        //Serial.print("bits count: ");
        //Serial.println(bitcount);
        rawvalue = 0;
        scancode = 0;
        bitcount = 0;
    }    
  
}

void loop()
{
  Serial.print("Current bitcount: ");
  Serial.println(bitcount);
  delay(2000);
  /*digitalWrite(13, LOW);
  delay(500);  
  digitalWrite(13, HIGH);
  delay(500);*/
}