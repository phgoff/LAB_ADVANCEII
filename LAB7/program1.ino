const  int rs_pin = 12;
const  int en_pin = 11;
const int  data_pin[] =  {5,4,3,2};

void write4bits(int value){
  delayMicroseconds(1);   //delay 1us
  digitalWrite(en_pin, HIGH);
  
  for(int i=0;i<4;i++)
    digitalWrite(data_pin[i],(value >> i) & 1);
   
  delayMicroseconds(1);
  digitalWrite(en_pin, LOW);
  delayMicroseconds(100);
}
// bool isData - false = command , true = data
void sendLCD8bits(int value, bool isData){
  if(isData) 
    digitalWrite(rs_pin, HIGH); // true - Data
  else
    digitalWrite(rs_pin, LOW); // false - command
  
  delayMicroseconds(1);
  write4bits(value >> 4); //4bit'H to 4bit'L
  write4bits(value);
  
}

void setupLCD(){
    pinMode(rs_pin, OUTPUT);
    pinMode(en_pin, OUTPUT);

    for(int i=0;i<4;i++)
      pinMode(data_pin[i], OUTPUT);
    
    digitalWrite(rs_pin, LOW);
    digitalWrite(en_pin, LOW);  
    
    delay(50);
    write4bits(0x03);
    delay(5);
    write4bits(0x03);
    delay(5);
    write4bits(0x03);
    delay(5);
    write4bits(0x02);
    delay(5);
    
   sendLCD8bits(0x28, false);
   sendLCD8bits(0x06, false);
   sendLCD8bits(0x0F, false);
   sendLCD8bits(0x01, false);
   delay(10);   
}

void setup(){
  setupLCD();
}
// Display
void loop(){
  //MUDASAY074
  sendLCD8bits(0x4D, true);  
  sendLCD8bits(0x55, true);
  sendLCD8bits(0x44, true);
  sendLCD8bits(0x41, true);
  sendLCD8bits(0x53, true);
  sendLCD8bits(0x41, true);
  sendLCD8bits(0x59, true);
  sendLCD8bits(0x3A, true);
  sendLCD8bits(0x30, true);
  sendLCD8bits(0x37, true);
  sendLCD8bits(0x34, true);
  // new line
  sendLCD8bits(0xC0, false);

   //PHIRATHAT090
  sendLCD8bits(0x50, true);  
  sendLCD8bits(0x48, true);
  sendLCD8bits(0x49, true);
  sendLCD8bits(0x52, true);
  sendLCD8bits(0x41, true);
  sendLCD8bits(0x54, true);
  sendLCD8bits(0x48, true);
  sendLCD8bits(0x41, true);
  sendLCD8bits(0x54, true);
  sendLCD8bits(0x3A, true);
  sendLCD8bits(0x30, true);
  sendLCD8bits(0x39, true);
  sendLCD8bits(0x30, true);
  
  while(1);
}
