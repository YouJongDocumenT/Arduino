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

int fordom, lfordom, rfordom, rcycle, lcycle, tsp, pown, rskill, skill, meso, cycle;

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
    Build_Start();

    for(int i = 0; i <= 0; i++){
      cycle = random(1,4);
      if(cycle == 1){
        Bleto();
      }else{
        furi();
      }
    } 
    furi_t();
    Jump_D();
    
}

void Build_Start(){ 

    E_Down(300,50);
    E_Up(50,20);

    skill = random(1, 7);
    if(skill == 1){
      W_Down(200,10);
      W_Up(50,10);
    }else if(skill == 4){
      W_Down(200,10);
      W_Up(500,500);
    }

    Left_Down(600,50);
    V_Down(130,30);
    V_Up(50,20);
    Up_Down(100,20);
    F_Down(150,50);
    F_Up(50,20);
    Up_Up(200,30);
    Left_Up(500,30);
    S_Down(200,30);
    S_Up(500,30);

    Down_Down(300,50);
    D_Down(500,50);
    D_Up(500,100);
    V_Down(130,30);
    V_Up(50,20);
    A_Down(300,30);
    A_Up(50,20);
    Down_Up(500,30);

    Left_Down(200,30);
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    
    
    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);
    

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    Delete_Down(200,50);
    Delete_Up(1000,100);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void furi(){

    skill = random(1, 7);
    if(skill == 1){
      W_Down(200,10);
      W_Up(50,10);
    }else if(skill == 4){
      W_Down(200,10);
      W_Up(500,500);
    }

    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    Delete_Down(200,50);
    Delete_Up(1000,100);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void sudden(){
    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    A_Down(100,30);
    Delete_Down(100,30);
    A_Up(500,50);
    Delete_Up(500,50);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void Sinme(){
    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    E_Down(100,30);
    Delete_Down(100,30);
    E_Up(500,50);
    Delete_Up(500,50);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void Cosol(){
    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    W_Down(100,30);
    Delete_Down(100,30);
    W_Up(500,50);
    Delete_Up(500,50);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void Bleto(){
    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(225,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(200,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    Left_Down(350,30);
    End_Down(200,50);
    End_Up(700,800);
    Left_Up(50,20);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(1000,100);
}

void furi_t(){
    skill = random(1, 7);
    if(skill == 1){
      W_Down(200,10);
      W_Up(50,10);
    }else if(skill == 4){
      W_Down(200,10);
      W_Up(500,500);
    }

    Left_Down(600,60);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up(50,20);

    Right_Down(220,20);
    V_Down(100,30);
    V_Up(50,20);
    C_Down(100,20);
    C_Up(400,20);
    Right_Up(50,20);
    Z_Down(100,20);
    Z_Up(2100,50);

    S_Down(300,30);
    S_Up(600,60);
    Right_Down(150,20);
    X_Down(100,20);
    Right_Up(50,20);
    X_Up(1100,100);

    E_Down(300,50);
    E_Up(50,20);

    Down_Down(300,50);
    V_Down(200,30);
    V_Up(50,20);
    Down_Up(50,20);

    Delete_Down(200,50);
    Delete_Up(1000,100);

    Right_Down(300,30);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    V_Down(300,30);
    V_Up(50,20);
    Ctrl_Down(500,30);
    Ctrl_Up(50,20);
    Right_Up(300,50);
}


void Jump_D(){
  V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(150,30);
    X_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(480,50);
}





void Jump_cs(){

  tsp = random(1,7);
  if(tsp == 1){
    
    V_Down(110,30);
    C_Down(140,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }
    
    X_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(600,50);

  }else if(tsp == 2){
    
    V_Down(110,30);
    C_Down(140,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }
    
    X_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(600,50);

  }else if(tsp == 3){

    V_Down(110,30);
    C_Down(140,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }

    PageUp_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    PageUp_Up(600,50);

  }else if(tsp == 4){

    V_Down(110,30);
    C_Down(140,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }
    
    Insert_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(600,50);

    
  }else if(tsp == 5){
    
    V_Down(110,30);
    C_Down(140,30);

    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }

    Home_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    Home_Up(600,50);

  }else{

    V_Down(110,30);
    C_Down(140,30);
    
    skill = random(1, 7);
    if(skill == 1){
      Q_Down(50,10);
      Q_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(100,10);
      PageDown_Up(100,10);
    }
    Shift_Down(150,50);
    V_Up(0,0);
    C_Up(0,0);
    Shift_Up(600,50);
    
  }
}

void Jump_cs_Fast(){

  tsp = random(1,7);
  if(tsp == 1){
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    
    X_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(0,0);
    Z_Up(550,50);
    
  }else if(tsp == 2){
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);   
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    X_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(0,0);
    Z_Up(550,50);
    
  }else if(tsp == 3){
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);   
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    PageUp_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    PageUp_Up(0,0);
    Z_Up(550,50);
    
  }else if(tsp == 4){
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);  
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    Insert_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(0,0);
    Z_Up(550,50);
    
  }else if(tsp == 5){
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    Home_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Home_Up(0,0);
    Z_Up(550,50);
    
  }else{
    meso = random(1, 3);
    if(meso == 1){
      Z_Down(50,10);
      Z_Up(50,10);
    }
    V_Down(100,30);
    V_Up(50,10);
    V_Down(100,30);
    C_Down(100,30);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Up(100,10);
      PageDown_Up(100,10);
    }
    Insert_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(0,0);
    Z_Up(550,50);
  }
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
