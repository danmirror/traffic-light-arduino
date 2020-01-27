// ==================================================================
//  title   = traffic light
//  author  = Danu andrean
//  date    = 27/01/2020
//  
//  note    =manual
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

int button_panel_1 = 13;
int button_panel_2 = 14;
int button_panel_3 = 15;
int button_panel_4 = 16;
//******************************************************************


//nilai bebas
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


int keep_panel_1 = 0;
int keep_panel_2 = 0;
int keep_panel_3 = 0;
int keep_panel_4 = 0;
int on = 0;

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
  
  pinMode(button_panel_1,INPUT);
  pinMode(button_panel_2,INPUT);
  pinMode(button_panel_3,INPUT);
  pinMode(button_panel_4,INPUT);
}


void loop() {
  // default semua lampu mati

  //===========================awal panel 1=====================
  // LOW = mematikan lampu
  // HIGH = menyalakan lampu
  //Serial.print untuk menampilkan data ke serial

  //jika button di tekan
  if(button_panel_1 == 1){
    //menyalakan lampu hijau
    if(keep_panel_1 == 0){
      digitalWrite(lampu_1_hijau,HIGH);
      Serial.print("hijau 1 : ");
      Serial.print(time_1_h);
      time_1_h --; //nilai berkurang

      //jika hijau sudah 0 maka akan pindah ke lampu selanjutnya
      if(time_1_h <= 0){
        digitalWrite(lampu_1_hijau,LOW);
        time_1_h = panel_1_hijau;
        keep_panel_1 = 1;
        
      }   
    }
   //menyalankan lampu kuning
    if(keep_panel_1 == 1){
      time_1_k --;
      digitalWrite(lampu_1_kuning,HIGH);
      Serial.print(" kuning 1 : ");
      Serial.print(time_1_k);
      
      if(time_1_k <= 0){
        digitalWrite(lampu_1_kuning,LOW);
        time_1_k = panel_1_kuning;
        keep_panel_1 = 2;
      }
    }
    //menyalakan lampu merah
    if(keep_panel_1 == 2){
      time_1_m --;
      digitalWrite(lampu_1_merah,HIGH);
      Serial.print(" merah 1 : ");
      Serial.print(time_1_m);
      
      if(time_1_m <= 0){
        digitalWrite(lampu_1_merah,LOW);
        time_1_m = panel_1_merah;
        keep_panel_1 = 0;
      }
    }
    delay(250);
  }
  //===========================akhir panel 1=====================
  // LOW = mematikan lampu
  // HIGH = menyalakan lampu
  //Serial.print untuk menampilkan data ke serial
  
   if(button_panel_2 == 0){
    //menyalakan lampu hijau
    if(keep_panel_2 == 1){
      digitalWrite(lampu_2_hijau,HIGH);  
      Serial.print("\t hijau 2 : ");
      Serial.print(time_2_h);
      time_2_h --; //nilai berkurang
      
      if(time_2_h <= 0){
        digitalWrite(lampu_2_hijau,LOW);
        time_2_h = panel_2_hijau;
        keep_panel_2 = 1;
      }   
    }
    //menyalakan lampu kuning
    if(keep_panel_2 == 1){
      digitalWrite(lampu_2_kuning,HIGH);
      Serial.print("\t kuning 2 : ");
      Serial.print(time_2_k);
      time_2_k --; //nilai berkurang
      
      if(time_2_k <= 0){
        digitalWrite(lampu_2_kuning,LOW);
        time_2_k = panel_2_kuning;
        keep_panel_2 = 2;
      }
    }
    //menyalakan lampu merah
    if(keep_panel_2 == 2){
      
      digitalWrite(lampu_2_merah,HIGH);
      Serial.print("\t merah 2 : ");
      Serial.print(time_2_m);
      time_2_m --; //nilai berkurang
      
      if(time_2_m <= 0){
        digitalWrite(lampu_2_merah,LOW);
        time_2_m = panel_2_merah;
        keep_panel_2 = 0;
      }
    }
    delay(250);
  }
  //===========================akhir panel 2=====================
  // LOW = mematikan lampu
  // HIGH = menyalakan lampu
  // Serial.print untuk menampilkan data ke serial
    
  if(button_panel_3 == 1){
    //menyalakan lampu hijau
    if(keep_panel_3 == 0){
      digitalWrite(lampu_3_hijau,HIGH);
      Serial.print("\t hijau 3 : ");
      Serial.print(time_3_h);
      time_3_h --; //nilai berkurang
      
      if(time_3_h <= 0){
        digitalWrite(lampu_3_hijau,LOW);
        time_3_h = panel_3_hijau;
        keep_panel_3 = 1;
      }   
    }
    //menyalakan lampu kuning
    if(keep_panel_3 == 1){
      digitalWrite(lampu_3_kuning,HIGH);
      Serial.print("\t kuning 3 : ");
      Serial.print(time_3_k);
      time_3_k --;
      
      if(time_3_k <= 0){
        digitalWrite(lampu_3_kuning,LOW);
        time_3_k = panel_3_kuning;
        keep_panel_3 = 2;
      }
    }
    //menyalakan lampu merah
    if(keep_panel_3 == 2){
      digitalWrite(lampu_3_merah,HIGH);
      Serial.print("\t merah 3 : ");
      Serial.print(time_3_m);
      time_3_m --;
      
      if(time_3_m <= 0){
        digitalWrite(lampu_3_merah,LOW);
        time_3_m = panel_3_merah;
        keep_panel_3 = 0;
      }
    }
    delay(250);
  }
  //===========================akhir panel 3=====================
  // LOW = mematikan lampu
  // HIGH = menyalakan lampu
  //Serial.print untuk menampilkan data ke serial
  
  if(button_panel_4 == 1){
    //menyalakan lampu hijau
    if(keep_panel_4 == 0){
      digitalWrite(lampu_4_hijau,HIGH);
      Serial.print("\t hijau 4 : ");
      Serial.println(time_4_h);
      time_4_h --; //nilai berkurang
      
      if(time_4_h <= 0){
        digitalWrite(lampu_4_hijau,LOW);
        time_4_h = panel_4_hijau;
        keep_panel_4 = 1;
      }   
    }
    //menyalakan lampu kuning
    if(keep_panel_4 == 1){
      digitalWrite(lampu_4_kuning,HIGH);
      Serial.print("\t kuning 4 : ");
      Serial.println(time_4_k);
      time_4_k --;
      
      if(time_4_k <= 0){
        digitalWrite(lampu_4_kuning,LOW);
        time_4_k = panel_4_kuning;
        keep_panel_4 = 2;
      }
    }
    //menyalakan lampu merah
    if(keep_panel_4 == 2){
      digitalWrite(lampu_4_merah,HIGH);
      Serial.print("\t merah 4 : ");
      Serial.println(time_4_m);
      time_4_m --;
      
      if(time_4_m <= 0){
        digitalWrite(lampu_4_kuning,LOW);
        time_4_m = panel_4_merah;
        keep_panel_4 = 0;
      }
    }
   delay(250);
  }
  //===========================akhir panel 4=====================
   
}
