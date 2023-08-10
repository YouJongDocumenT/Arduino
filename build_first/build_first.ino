volatile int state = false; // 매크로 키보드의 구동 미치 정지상태를 저장하는 함수

unsigned button_millis;

void random_delay(long delay_value, int random_value)
{
  delay_value = delay_value + random(-random_value, random_value);
  if(delay_value < 0) return;
  delay(delay_value);
}

void isr()
{
  // debouncing 현상 방지, 0.2초 이내에 버튼이 눌러진 경우
  // 1회 눌러진것으로만 인식시킴
  if( (millis() - button_millis ) < 200 ) return;

  if( state == false )
  {
    state = true;
    digitalWrite(52, HIGH); // 구동중인 경우 LED ON
    digitalWrite(53, LOW); 
  }
  else
  {
    state = false;
    digitalWrite(52, LOW); 
    digitalWrite(53, HIGH); // 정지중인 경우 LED ON
  }
  
  button_millis = millis();
}

int fordom, lfordom, rfordom, rcycle, lcycle, tsp, pown, rskill, skill, meso,cycle;

void setup() {
  
  for(int i = 2; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  for(int j = 22; j<=50; j++){
    pinMode(j, OUTPUT);
  }
  randomSeed(analogRead(0));

  pinMode(51, INPUT_PULLUP); // 버튼
  attachInterrupt(digitalPinToInterrupt(51), isr, RISING); // 버튼을 누를 경우 실행하는 한수를 지정(isr함수)

  
}

void loop() {
    E_Down(300,30);
    E_Up(200,30);

  Pountain();

  for(int i = 0; i <= 3; i++){
    fordom = random(1,3);
    if(tsp == 1){
      W_Down(300,30);
      W_Up(350,30);
    }
    Left_Down(200,20);
    for(int i = 0; i <= 1; i++){
      Jump_cs();
    }
    furi();
    Jump_cs();
    Left_Up(50,20);
    random_delay(300, 50);

    Right_Down(100,20);
    bleto();

    fordom = random(1,3);
    if(tsp == 1){
      PageDown_Down(300,30);
      PageDown_Up(350,30);
    }
    for(int i = 0; i <= 2; i++){
    Jump_cs();
    }
    X_Down(250,50);
    X_Up(200,20);
    Right_Up(100,20);
    random_delay(300, 50);
  }
  Jump_cs();
  
}


void Pountain(){
  Left_Down(100,20);
  V_Down(100,30);;
  C_Down(130,30);
  V_Up(50,20);
  C_Up(50,20);
  Z_Down(100,20);
  Z_Up(1400,100);
  Left_Up(100,20);

  S_Down(300,30);
  S_Up(600,60);

  D_Down(500,50);
  D_Up(500,100);

  Jump_cs();
  Jump_cs();
  Sudden_s();
  random_delay(500, 50);

  
  Right_Down(100,20);
  bleto();
  for(int i = 0; i <= 2; i++){
    Jump_cs();
  }
  X_Down(250,50);
  X_Up(400,20);
  Right_Up(100,20);
  
}





void Jump_cs(){

  tsp = random(1,7);
  if(tsp == 1){
    
    V_Down(120,30);
    C_Down(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }
    
    X_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(620,60);
    

  }else if(tsp == 2){
    
    V_Down(120,30);
    C_Down(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }
    
    Insert_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(620,60);

  }else if(tsp == 3){

    V_Down(120,30);
    C_Down(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }

    PageUp_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    PageUp_Up(620,60);


  }else if(tsp == 4){

    V_Down(120,30);
    C_Down(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }
    
    Shift_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Shift_Up(620,60);
    

    
  }else if(tsp == 5){
    
    V_Down(120,30);
    C_Down(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }

    R_Down(100,50);   // R
    V_Up(0,0);
    C_Up(0,0);
    R_Up(620,60);
    

  }else{

    V_Down(120,30);
    C_Down(120,30);
    
    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      Ctrl_Down(50,20);
      Ctrl_Up(50,20);
    }
    X_Down(100,50);  // Shift
    V_Up(0,0);
    C_Up(0,0);
    X_Up(620,60);
    
  }
}




void bleto(){
  Right_Down(100,20);
  V_Down(80,20);
  C_Down(80,20);
  V_Up(0,0);
  C_Up(0,0);
  F_Down(200,20);
  F_Up(750,50);
  Right_Up(50,20);

  V_Down(200,20);
  V_Up(50,20);

  End_Down(150,50);
  V_Up(0,0);
  C_Up(0,0);
  End_Up(780,60);

  Down_Down(100,20);
  V_Down(400,40);
  V_Up(50,20);
  X_Down(200,20);
  X_Up(50,20);
  Down_Up(300,20);


}

void furi(){
  V_Down(100,30);
  V_Up(50,20);
  V_Down(130,30);
  C_Down(130,30);

  Delete_Down(150,50);
  V_Up(0,0);
  C_Up(0,0);
  Delete_Up(680,60);
}

void Sudden_s(){
  V_Down(100,20);
  C_Down(100,20);
  C_Up(350,30);
  C_Down(100,20);
  C_Up(50,20);

  A_Down(150,50);
  V_Up(0,0);
  C_Up(0,0);
  A_Up(780,60);
}



//##########################
//#########[방향키]##########
//##########################

//========================== "↑"

void Up_Down(int basic, int margin){
  digitalWrite(23, HIGH);
  random_delay(basic, margin);
}
void Up_Up(int basic, int margin){
  digitalWrite(23, LOW);
  random_delay(basic, margin);
}

//========================== "←"

void Left_Down(int basic, int margin){
  digitalWrite(45, HIGH);
  random_delay(basic, margin);
}
void Left_Up(int basic, int margin){
  digitalWrite(45, LOW);
  random_delay(basic, margin);
}

//========================== "↓"

void Down_Down(int basic, int margin){
  digitalWrite(27, HIGH);
  random_delay(basic, margin);
}
void Down_Up(int basic, int margin){
  digitalWrite(27, LOW);
  random_delay(basic, margin);
}

//========================== "→"

void Right_Down(int basic, int margin){
  digitalWrite(46, HIGH);
  random_delay(basic, margin);
}
void Right_Up(int basic, int margin){
  digitalWrite(46, LOW);
  random_delay(basic, margin);
}

//##########################
//#########[특수키]##########
//##########################

//========================== "Insert"

void Insert_Down(int basic, int margin){
  digitalWrite(25, HIGH);
  random_delay(basic, margin);
}
void Insert_Up(int basic, int margin){
  digitalWrite(25, LOW);
  random_delay(basic, margin);
}

//========================== "Home"

void Home_Down(int basic, int margin){
  digitalWrite(24, HIGH);
  random_delay(basic, margin);
}
void Home_Up(int basic, int margin){
  digitalWrite(24, LOW);
  random_delay(basic, margin);
}

//========================== "PageUp"

void PageUp_Down(int basic, int margin){
  digitalWrite(39, HIGH);
  random_delay(basic, margin);
}
void PageUp_Up(int basic, int margin){
  digitalWrite(39, LOW);
  random_delay(basic, margin);
}

//========================== "Delete"

void Delete_Down(int basic, int margin){
  digitalWrite(29, HIGH);
  random_delay(basic, margin);
}
void Delete_Up(int basic, int margin){
  digitalWrite(29, LOW);
  random_delay(basic, margin);
}

//========================== "End"

void End_Down(int basic, int margin){
  digitalWrite(22, HIGH);
  random_delay(basic, margin);
}
void End_Up(int basic, int margin){
  digitalWrite(22, LOW);
  random_delay(basic, margin);
}

//========================== "PageDown"

void PageDown_Down(int basic, int margin){
  digitalWrite(31, HIGH);
  random_delay(basic, margin);
}
void PageDown_Up(int basic, int margin){
  digitalWrite(31, LOW);
  random_delay(basic, margin);
}

//##########################
//########[사이드키]#########
//##########################
//========================== "Ctrl"

void Ctrl_Down(int basic, int margin){
  digitalWrite(35, HIGH);
  random_delay(basic, margin);
}
void Ctrl_Up(int basic, int margin){
  digitalWrite(35, LOW);
  random_delay(basic, margin);
}

//========================== "Alt"

void Alt_Down(int basic, int margin){
  digitalWrite(38, HIGH);
  random_delay(basic, margin);
}
void Alt_Up(int basic, int margin){
  digitalWrite(38, LOW);
  random_delay(basic, margin);
}

//========================== "Shift"

void Shift_Down(int basic, int margin){
  digitalWrite(33, HIGH);
  random_delay(basic, margin);
}
void Shift_Up(int basic, int margin){
  digitalWrite(33, LOW);
  random_delay(basic, margin);
}

//##########################
//##########[3열]###########
//##########################

//========================== "Z"

void Z_Down(int basic, int margin){
  digitalWrite(26, HIGH);
  random_delay(basic, margin);
}
void Z_Up(int basic, int margin){
  digitalWrite(26, LOW);
  random_delay(basic, margin);
}

//========================== "X"

void X_Down(int basic, int margin){
  digitalWrite(41, HIGH);
  random_delay(basic, margin);
}
void X_Up(int basic, int margin){
  digitalWrite(41, LOW);
  random_delay(basic, margin);
}

//========================== "C"

void C_Down(int basic, int margin){
  digitalWrite(40, HIGH);
  random_delay(basic, margin);
}
void C_Up(int basic, int margin){
  digitalWrite(40, LOW);
  random_delay(basic, margin);
}

//========================== "V"

void V_Down(int basic, int margin){
  digitalWrite(43, HIGH);
  random_delay(basic, margin);
}
void V_Up(int basic, int margin){
  digitalWrite(43, LOW);
  random_delay(basic, margin);
}

//##########################
//##########[2열]###########
//##########################

//========================== "A"

void A_Down(int basic, int margin){
  digitalWrite(34, HIGH);
  random_delay(basic, margin);
}
void A_Up(int basic, int margin){
  digitalWrite(34, LOW);
  random_delay(basic, margin);
}

//========================== "S"

void S_Down(int basic, int margin){
  digitalWrite(32, HIGH);
  random_delay(basic, margin);
}
void S_Up(int basic, int margin){
  digitalWrite(32, LOW);
  random_delay(basic, margin);
}

//========================== "D"39

void D_Down(int basic, int margin){
  digitalWrite(42, HIGH);
  random_delay(basic, margin);
}
void D_Up(int basic, int margin){
  digitalWrite(42, LOW);
  random_delay(basic, margin);
}

//========================== "F"40

void F_Down(int basic, int margin){
  digitalWrite(44, HIGH);
  random_delay(basic, margin);
}
void F_Up(int basic, int margin){
  digitalWrite(44, LOW);
  random_delay(basic, margin);
}

//##########################
//##########[1열]###########
//##########################

//========================== "Q"

void Q_Down(int basic, int margin){
  digitalWrite(28, HIGH);
  random_delay(basic, margin);
}
void Q_Up(int basic, int margin){
  digitalWrite(28, LOW);
  random_delay(basic, margin);
}

//========================== "W"

void W_Down(int basic, int margin){
  digitalWrite(37, HIGH);
  random_delay(basic, margin);
}
void W_Up(int basic, int margin){
  digitalWrite(37, LOW);
  random_delay(basic, margin);
}

//========================== "E"

void E_Down(int basic, int margin){
  digitalWrite(36, HIGH);
  random_delay(basic, margin);
}
void E_Up(int basic, int margin){
  digitalWrite(36, LOW);
  random_delay(basic, margin);
}

//========================== "R"

void R_Down(int basic, int margin){
  digitalWrite(30, HIGH);
  random_delay(basic, margin);
}
void R_Up(int basic, int margin){
  digitalWrite(30, LOW);
  random_delay(basic, margin);
}
