//double maxVoltage = 3.3;
//double voltResolution = 255;
//double High_octet =  0.7 * 255 * (3.3/5.0);
//double Low_octet = 0.3 * 255 * (3.3/5);
int i = 0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    for(i = 0; i <=13 ; i++) {
        pinMode(i, OUTPUT);   // 出力に設定  
    }

}

void loop() {
  //Serial.println(High_octet);
  //digitalWrite(13,HIGH);
  //digitalWrite(8,HIGH);

  HandOver4dBstep(2000);
  
/*
  setXdB(LOW,LOW,LOW,LOW,LOW,LOW);
  set0dB();
  delay(2000);
  set4dB();  
  delay(2000);
  set8dB();
  delay(2000);
  set12dB();
  delay(2000);
  set16dB();
  delay(2000);
  set20dB();
  delay(2000);
  set24dB();
  delay(2000);
  set28dB();
  delay(2000);
  set32dB();
  delay(2000);
*/
  
}

void setPin(String pinArrange, unsigned char v1_HL,unsigned char v2_HL,unsigned char v3_HL,unsigned char v4_HL,unsigned char v5_HL,unsigned char v6_HL){
  if(pinArrange =="p13p8"){
    digitalWrite(13,v1_HL); // V1 0.5dB
    digitalWrite(12,v2_HL); // V2 1dB
    digitalWrite(11,v3_HL); // V3 2dB 
    digitalWrite(10,v4_HL); // V4 4dB
    digitalWrite(9,v5_HL); // V5 8dB
    digitalWrite(8,v6_HL); // V6 16dB
  }
  else if(pinArrange =="p0p5"){
    digitalWrite(0,v1_HL); // V1 0.5dB
    digitalWrite(1,v2_HL); // V2 1dB
    digitalWrite(2,v3_HL); // V3 2dB 
    digitalWrite(3,v4_HL); // V4 4dB
    digitalWrite(4,v5_HL); // V5 8dB
    digitalWrite(5,v6_HL); // V6 16dB
  }
  else if(pinArrange =="p13p8andp0p5"){ 
    
    digitalWrite(13,v1_HL); // V1 0.5dB
    digitalWrite(12,v2_HL); // V2 1dB
    digitalWrite(11,v3_HL); // V3 2dB 
    digitalWrite(10,v4_HL); // V4 4dB
    digitalWrite(9,v5_HL); // V5 8dB
    digitalWrite(8,v6_HL); // V6 16dB
    
    digitalWrite(0,(1-v1_HL)); // V1 0.5dB
    digitalWrite(1,1-v2_HL); // V2 1dB
    digitalWrite(2,1-v3_HL); // V3 2dB 
    digitalWrite(3,1-v4_HL); // V4 4dB
    digitalWrite(4,1-v5_HL); // V5 8dB
    digitalWrite(5,1-v6_HL); // V6 16dB
  }
}


void HandOver4dBstep(int sleepTime){
  //up down
  setPin("p13p8andp0p5",0,0,0,0,0,0); // 0,32dB 
  delay(sleepTime);  
  setPin("p13p8andp0p5",0,0,0,1,0,0); //4,28dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,1,0); //8,24dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,1,0); //12,20dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,0,1); //16,16dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,0,1); //20,12dB 
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,1,1); //24,8dB  
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,1,1); //28,4dB
  delay(sleepTime);
  setPin("p13p8andp0p5",1,1,1,1,1,1); //32,0dB  
  delay(sleepTime);

  //down up
  setPin("p13p8andp0p5",0,0,0,1,1,1); //28,4dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,1,1); //24,8dB  
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,0,1); //20,12dB 
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,0,1); //16,16dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,1,0); //12,20dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,1,0); //8,24dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,1,0,0); //4,28dB
  delay(sleepTime);
  setPin("p13p8andp0p5",0,0,0,0,0,0); // 0,32dB 
  delay(sleepTime);  
  
}


void set0dB(String PinArrange){
    digitalWrite(13,LOW); // V1 0.5dB
    digitalWrite(12,LOW); // V2 1dB
    digitalWrite(11,LOW); // V3 2dB 
    digitalWrite(10,LOW); // V4 4dB
    digitalWrite(9,LOW); // V5 8dB
    digitalWrite(8,LOW); // V6 16dB
}

void set4dB(){
    digitalWrite(13,LOW); // V1 0.5dB
    digitalWrite(12,LOW); // V2 1dB
    digitalWrite(11,LOW); // V3 2dB 
    digitalWrite(10,HIGH); // V4 4dB
    digitalWrite(9,LOW); // V5 8dB
    digitalWrite(8,LOW); // V6 16dB
}


void set8dB(){
    digitalWrite(13,LOW); // V1 0.5dB
    digitalWrite(12,LOW); // V2 1dB
    digitalWrite(11,LOW); // V3 2dB 
    digitalWrite(10,LOW); // V4 4dB
    digitalWrite(9,HIGH); // V5 8dB
    digitalWrite(8,LOW); // V6 16dB
}

void set12dB(){
  digitalWrite(13,LOW); // V1 0.5dB
  digitalWrite(12,LOW); // V2 1dB
  digitalWrite(11,LOW); // V3 2dB 
  digitalWrite(10,HIGH); // V4 4dB
  digitalWrite(9,HIGH); // V5 8dB
  digitalWrite(8,LOW); // V6 16dB
}

void set16dB(){
  digitalWrite(13,LOW); // V1 0.5dB
  digitalWrite(12,LOW); // V2 1dB
  digitalWrite(11,LOW); // V3 2dB 
  digitalWrite(10,LOW); // V4 4dB
  digitalWrite(9,LOW); // V5 8dB
  digitalWrite(8,HIGH); // V6 16dB
}

void set20dB(){
  digitalWrite(13,LOW); // V1 0.5dB
  digitalWrite(12,LOW); // V2 1dB
  digitalWrite(11,LOW); // V3 2dB 
  digitalWrite(10,HIGH); // V4 4dB
  digitalWrite(9,LOW); // V5 8dB
  digitalWrite(8,HIGH); // V6 16dB
}

void set24dB(){
  digitalWrite(13,LOW); // V1 0.5dB
  digitalWrite(12,LOW); // V2 1dB
  digitalWrite(11,LOW); // V3 2dB 
  digitalWrite(10,LOW); // V4 4dB
  digitalWrite(9,HIGH); // V5 8dB
  digitalWrite(8,HIGH); // V6 16dB
}

void set28dB(){
  digitalWrite(13,LOW); // V1 0.5dB
  digitalWrite(12,LOW); // V2 1dB
  digitalWrite(11,LOW); // V3 2dB 
  digitalWrite(10,HIGH); // V4 4dB
  digitalWrite(9,HIGH); // V5 8dB
  digitalWrite(8,HIGH); // V6 16dB
}

void set32dB(){
  digitalWrite(13,HIGH); // V1 0.5dB
  digitalWrite(12,HIGH); // V2 1dB
  digitalWrite(11,HIGH); // V3 2dB 
  digitalWrite(10,HIGH); // V4 4dB
  digitalWrite(9,HIGH); // V5 8dB
  digitalWrite(8,HIGH); // V6 16dB
}
