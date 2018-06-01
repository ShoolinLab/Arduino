int a[6]={1,2,3,4,5,6};
int i;
void setup() {
  for(i=0; i<=6; i++){
    pinMode(a[i],OUTPUT);
  }

}


void loop() { 
  for(i=0; i<=6; i++){
    digitalWrite(a[i],1);
    delay(100);
    
  } 
  for(i=6; i>=0; i--){
    digitalWrite(a[i],0);
    delay(100);
    
  } 

}
