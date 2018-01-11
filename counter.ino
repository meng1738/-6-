int num=0;
int ounum=0;
int ent;
int ot;
int total;
void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);pinMode(11,OUTPUT);
  pinMode(5,INPUT);pinMode(10,OUTPUT);
}

void loop() { 
  int enter = Detect(11,3,38000);
  int  out  = Detect(10,5,38000);
  
     if(enter == 1){
    num++;
    Serial.print("num=");
    Serial.println(num);
    do {
    ent = Detect(11,3,38000);
       delay(50);  
     }while(ent == 1);
    }
    
     if(out == 1){
    ounum--;
    Serial.print("ounum=");
    Serial.println(ounum);
    do {
    ot = Detect(10,5,38000);
       delay(50);  
     }while(ot == 1);   
    }
  total = num+ounum;
  Serial.print("total=");
  Serial.println(total); 
  delay(100);
    
}
int Detect(int Led,int Rece,long Freq){
  tone(Led,Freq,8);
  delay(1);
  int ir = digitalRead(Rece);
  delay(1);
  return ir;
}

