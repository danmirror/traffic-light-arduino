// ==================================================================
//  title   = traffic light
//  author  = Danu andrean
//  date    = 26/01/2020
//  
//  note    = rumus menentukan timer merah, M = (H*2)+(H-K);
//          = m = merah
//            k = kuning
//            h = hijau
//
//====================================================================



//*****************masukan ke pin output sesui hardware**************
int lampu_1_hijau = 1;
int lampu_2_hijau = 2;
int lampu_3_hijau = 3;
int lampu_4_hijau = 4;

int lampu_1_merah = 5;
int lampu_2_merah = 6;
int lampu_3_merah = 7;
int lampu_4_merah = 8;

int lampu_1_kuning = 9;
int lampu_2_kuning = 10;
int lampu_3_kuning = 11;
int lampu_4_kuning = 12;

//******************************************************************


//nilai timer lampu => timer merah sesuaikan dengan rumus
//----------------------------------------------------------
int timer_merah = 50;
int timer_hijau = 20;
int timer_kuning = 10;
//----------------------------------------------------------

int panel_1_merah = timer_merah;
int panel_2_merah = timer_merah;
int panel_3_merah = timer_merah;
int panel_4_merah = timer_merah;

int panel_1_hijau = timer_hijau;
int panel_2_hijau = timer_hijau;
int panel_3_hijau = timer_hijau;
int panel_4_hijau = timer_hijau;

int panel_1_kuning = timer_kuning;
int panel_2_kuning = timer_kuning;
int panel_3_kuning = timer_kuning;
int panel_4_kuning = timer_kuning;

int time_1_m;
int time_2_m;
int time_3_m;
int time_4_m;

int time_1_h;
int time_2_h;
int time_3_h;
int time_4_h;

int time_1_k;
int time_2_k;
int time_3_k;
int time_4_k;


int keadaan = 1;
int start = 0;


void reset(){
  //mengisi nilai time dengan nilai masukan timer 
  time_1_m = panel_1_merah;
  time_2_m = panel_2_merah;
  time_3_m = panel_3_merah;
  time_4_m = panel_4_merah;

  time_1_h = panel_1_hijau;
  time_2_h = panel_2_hijau;
  time_3_h = panel_3_hijau;
  time_4_h = panel_4_hijau;

  time_1_k = panel_1_kuning;
  time_2_k = panel_2_kuning;
  time_3_k = panel_3_kuning;
  time_4_k = panel_4_kuning;

  start = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  reset();

  pinMode(lampu_1_hijau,OUTPUT);
  pinMode(lampu_2_hijau,OUTPUT);
  pinMode(lampu_3_hijau,OUTPUT);
  pinMode(lampu_4_hijau,OUTPUT);

  pinMode(lampu_1_merah,OUTPUT);
  pinMode(lampu_2_merah,OUTPUT);
  pinMode(lampu_3_merah,OUTPUT);
  pinMode(lampu_4_merah,OUTPUT);

  pinMode(lampu_1_kuning,OUTPUT);
  pinMode(lampu_2_kuning,OUTPUT);
  pinMode(lampu_3_kuning,OUTPUT);
  pinMode(lampu_4_kuning,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  
  //algoritma jika mulai || hanya sekali jalan di awal
  if(!start){
     time_2_m = panel_2_merah - panel_2_hijau - panel_2_kuning;
     time_3_m = panel_3_merah - panel_3_kuning;
     start = 1;
  }
  else{
    //hanya reset time merah jika nilai 0
  
    if(time_1_m == 0) time_1_m = panel_1_merah;
    if(time_2_m == 0) time_2_m = panel_2_merah;
    if(time_3_m == 0) time_3_m = panel_3_merah;
    if(time_4_m == 0) time_4_m = panel_4_merah;

    //algoritma keadaan lampu
  
    if(keadaan == 1){ 
      // LOW = mematikan lampu
      // HIGH = menyalakan lampu
      
      digitalWrite(lampu_4_hijau,LOW);
      digitalWrite(lampu_1_merah,LOW);
      
      digitalWrite(lampu_1_hijau,HIGH);
      digitalWrite(lampu_2_merah,HIGH);
      digitalWrite(lampu_3_merah,HIGH);
      if(time_1_h == panel_1_hijau){
        Serial.println("-------------------");
      }
      Serial.print("hijau 1 : ");
      Serial.print(time_1_h);
      Serial.print("\t merah 2 : ");
      Serial.print(time_2_m);
      Serial.print("\t merah 3 : ");
      Serial.print(time_3_m);
      
       time_1_h--;
       time_2_m--;
       time_3_m--;
         
      if (time_4_k == 0){ 
        digitalWrite(lampu_4_kuning,LOW);
        digitalWrite(lampu_4_merah,HIGH);
          
        Serial.print("\t merah 4 : ");
        Serial.println(time_4_m);
        time_4_m--;
      }
      else{
        //ini di hitung terlebih dahulu jika terpenuhi masuk kondisi if di atas
        digitalWrite(lampu_4_kuning,HIGH);
        
        Serial.print("\t kuning 4 : ");
        Serial.println(time_4_k);
        time_4_k--;
      }
      if (time_1_h == 0){
        keadaan = 2;

        //reset nilai
        time_1_h = panel_1_hijau;
        time_4_k = panel_4_kuning;
      }
      
    }
    else if(keadaan == 2){
      // LOW = mematikan lampu
      // HIGH = menyalakan lampu
      
      digitalWrite(lampu_1_hijau,LOW);
      digitalWrite(lampu_2_merah,LOW);
      
      digitalWrite(lampu_2_hijau,HIGH);
      digitalWrite(lampu_3_merah,HIGH);
      digitalWrite(lampu_4_merah,HIGH);
  
      if(time_2_h == panel_2_hijau){
        Serial.println("-------------------");
      }
      Serial.print("hijau 2 : ");
      Serial.print(time_2_h);
      Serial.print("\t merah 3 : ");
      Serial.print(time_3_m);
      Serial.print("\t merah 4 : ");
      Serial.print(time_4_m);
      time_2_h--;
      time_3_m--;
      time_4_m--;
     
      
      if(time_1_k == 0){
        digitalWrite(lampu_1_kuning,LOW);
        digitalWrite(lampu_1_merah,HIGH);  
  
        Serial.print("\t merah 1 : ");
        Serial.println(time_1_m);
        time_1_m--;
      }
      else{
        digitalWrite(lampu_1_kuning,HIGH);
  
        Serial.print("\t kuning 1 : ");
        Serial.println(time_1_k);
        time_1_k--;
      }
      if(time_2_h == 0){
        keadaan = 3;

        //reset nilai
        time_2_h = panel_2_hijau;
        time_1_k = panel_1_kuning;
      }
    }
  
    else if(keadaan == 3){
      // LOW = mematikan lampu
      // HIGH = menyalakan lampu
      
      digitalWrite(lampu_2_hijau,LOW);
      digitalWrite(lampu_3_merah,LOW);
      
      digitalWrite(lampu_3_hijau,HIGH);
      digitalWrite(lampu_1_merah,HIGH);
      digitalWrite(lampu_4_merah,HIGH);
      
      if(time_3_h == panel_3_hijau){
        Serial.println("-------------------");
      }
      Serial.print("hijau 3 : ");
      Serial.print(time_3_h);
      Serial.print("\t merah 1 : ");
      Serial.print(time_1_m);
      Serial.print("\t merah 4 : ");
      Serial.print(time_4_m);
      time_3_h--;
      time_1_m--;
      time_4_m--;
      
      if(time_2_k == 0){
        digitalWrite(lampu_2_kuning,LOW);
        digitalWrite(lampu_2_merah,HIGH); 
  
        Serial.print("\t merah 2 : ");
        Serial.println(time_2_m);
        time_2_m--;
      }
      else{
        digitalWrite(lampu_2_kuning,HIGH);
  
        Serial.print("\t kuning 2 : ");
        Serial.println(time_2_k);
        time_2_k--;
      }
      if (time_3_h == 0){
        keadaan = 4;

        //reset nilai
        time_3_h = panel_3_hijau;
        time_2_k = panel_2_kuning;
      }
    }
    else if(keadaan == 4){
      // LOW = mematikan lampu
      // HIGH = menyalakan lampu
      
      digitalWrite(lampu_3_hijau,LOW);
      digitalWrite(lampu_4_merah,LOW);
      
      digitalWrite(lampu_4_hijau,HIGH);
      digitalWrite(lampu_2_merah,HIGH);
      digitalWrite(lampu_1_merah,HIGH);
  
      if(time_4_h == panel_4_hijau){
        Serial.println("-------------------");
      }
      Serial.print("hijau 4 : ");
      Serial.print(time_4_h);
      Serial.print("\t merah 2 : ");
      Serial.print(time_2_m);
      Serial.print("\t merah 1 : ");
      Serial.print(time_1_m);
      time_4_h--;
      time_2_m--;
      time_1_m--;
      
      if(time_3_k == 0){
        digitalWrite(lampu_3_kuning,LOW);
        digitalWrite(lampu_3_merah,HIGH);  
  
        Serial.print("\t merah 3 : ");
        Serial.println(time_3_m);
        time_3_m--;
      }
      else{
        digitalWrite(lampu_3_kuning,HIGH);
  
        Serial.print("\t kuning 3 : ");
        Serial.println(time_3_k);
        time_3_k--;
      }
      if(time_4_h == 0){
        keadaan = 1;

        //reset nilai
        time_4_h = panel_4_hijau;
        time_3_k = panel_3_kuning;
      }
    }//akhir keadaan 4
    
  }
}
