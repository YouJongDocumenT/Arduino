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
    Build_Flair();

    cycle = random(6, 9);
    for(int j = 0; j <= cycle; j++){
      Left_Down(200,20);
      for(int i = 0; i <= 2; i++){
        Jump_cs();
      }
      Left_Up(200,20);

      Right_Down(200,20);
      for(int i = 0; i <= 2; i++){
        Jump_cs();
      }
      Right_Up(200,20);
    }
}

void Build_Flair(){
    Left_Down(200,20);
    V_Down(200,30);
    V_Up(50,20);
    Z_Down(200,30);
    Z_Up(600,50);
    V_Down(200,30);
    V_Up(50,20);
    Z_Down(200,30);
    Z_Up(600,50);
    Left_Up(200,20);

    F_Down(1000,100);
    F_Up(300,30);

    Jump_cs();
    random_delay(200, 20);

    D_Down(1000,100);
    D_Up(300,30);

    Jump_cs();
    random_delay(600, 60);

    Right_Down(200,20);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Right_Up(200,20);
}



void Jump_cs(){

  tsp = random(1,7);
  if(tsp == 1){
    V_Down(80,20);
    C_Down(80,20);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    
    X_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(0,0);
    Z_Up(600,80);
    
  }else if(tsp == 2){

    V_Down(80,20);
    C_Down(80,20);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    X_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    X_Up(0,0);
    Z_Up(600,80);
    
  }else if(tsp == 3){

    V_Down(80,20);
    C_Down(80,20);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    PageUp_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    PageUp_Up(0,0);
    Z_Up(600,80);
    
  }else if(tsp == 4){

    V_Down(80,20);
    C_Down(80,20);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    Insert_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(0,0);
    Z_Up(600,80);
    
  }else if(tsp == 5){

    V_Down(80,20);
    C_Down(80,20);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    Home_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Home_Up(0,0);
    Z_Up(600,80);
    
  }else{

    V_Down(80,20);
    C_Down(80,20);
    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down(50,10);
      Ctrl_Up(50,10);
    }else if(skill == 4){
      PageDown_Down(50,10);
      PageDown_Up(50,10);
    }
    Insert_Down(100,50);
    Z_Down(100,50);
    V_Up(0,0);
    C_Up(0,0);
    Insert_Up(0,0);
    Z_Up(600,80);
  }
}















//##########################
//#########[방향키]##########
//##########################

//========================== "↑"

void Up_Down(int basic, int margin){
  digitalWrite(2, HIGH);
  random_delay(basic, margin);
}
void Up_Up(int basic, int margin){
  digitalWrite(2, LOW);
  random_delay(basic, margin);
}

//========================== "↓"

void Down_Down(int basic, int margin){
  digitalWrite(3, HIGH);
  random_delay(basic, margin);
}
void Down_Up(int basic, int margin){
  digitalWrite(3, LOW);
  random_delay(basic, margin);
}

//========================== "←"

void Left_Down(int basic, int margin){
  digitalWrite(4, HIGH);
  random_delay(basic, margin);
}
void Left_Up(int basic, int margin){
  digitalWrite(4, LOW);
  random_delay(basic, margin);
}

//========================== "→"

void Right_Down(int basic, int margin){
  digitalWrite(5, HIGH);
  random_delay(basic, margin);
}
void Right_Up(int basic, int margin){
  digitalWrite(5, LOW);
  random_delay(basic, margin);
}

//##########################
//#########[특수키]##########
//##########################

//========================== "Insert"

void Insert_Down(int basic, int margin){
  digitalWrite(6, HIGH);
  random_delay(basic, margin);
}
void Insert_Up(int basic, int margin){
  digitalWrite(6, LOW);
  random_delay(basic, margin);
}

//========================== "Home"

void Home_Down(int basic, int margin){
  digitalWrite(7, HIGH);
  random_delay(basic, margin);
}
void Home_Up(int basic, int margin){
  digitalWrite(7, LOW);
  random_delay(basic, margin);
}

//========================== "PageUp"

void PageUp_Down(int basic, int margin){
  digitalWrite(8, HIGH);
  random_delay(basic, margin);
}
void PageUp_Up(int basic, int margin){
  digitalWrite(8, LOW);
  random_delay(basic, margin);
}

//========================== "Delete"

void Delete_Down(int basic, int margin){
  digitalWrite(9, HIGH);
  random_delay(basic, margin);
}
void Delete_Up(int basic, int margin){
  digitalWrite(9, LOW);
  random_delay(basic, margin);
}

//========================== "End"

void End_Down(int basic, int margin){
  digitalWrite(10, HIGH);
  random_delay(basic, margin);
}
void End_Up(int basic, int margin){
  digitalWrite(10, LOW);
  random_delay(basic, margin);
}

//========================== "PageDown"

void PageDown_Down(int basic, int margin){
  digitalWrite(11, HIGH);
  random_delay(basic, margin);
}
void PageDown_Up(int basic, int margin){
  digitalWrite(11, LOW);
  random_delay(basic, margin);
}

//##########################
//########[사이드키]#########
//##########################

//========================== "RShift"

void RShift_Down(int basic, int margin){
  digitalWrite(12, HIGH);
  random_delay(basic, margin);
}
void RShift_Up(int basic, int margin){
  digitalWrite(12, LOW);
  random_delay(basic, margin);
}

//========================== "Ctrl"

void Ctrl_Down(int basic, int margin){
  digitalWrite(22, HIGH);
  random_delay(basic, margin);
}
void Ctrl_Up(int basic, int margin){
  digitalWrite(22, LOW);
  random_delay(basic, margin);
}

//========================== "Alt"

void Alt_Down(int basic, int margin){
  digitalWrite(23, HIGH);
  random_delay(basic, margin);
}
void Alt_Up(int basic, int margin){
  digitalWrite(23, LOW);
  random_delay(basic, margin);
}

//========================== "LShift"

void LShift_Down(int basic, int margin){
  digitalWrite(24, HIGH);
  random_delay(basic, margin);
}
void LShift_Up(int basic, int margin){
  digitalWrite(24, LOW);
  random_delay(basic, margin);
}

//##########################
//##########[3열]###########
//##########################

//========================== "Z"

void Z_Down(int basic, int margin){
  digitalWrite(25, HIGH);
  random_delay(basic, margin);
}
void Z_Up(int basic, int margin){
  digitalWrite(25, LOW);
  random_delay(basic, margin);
}

//========================== "X"

void X_Down(int basic, int margin){
  digitalWrite(26, HIGH);
  random_delay(basic, margin);
}
void X_Up(int basic, int margin){
  digitalWrite(26, LOW);
  random_delay(basic, margin);
}

//========================== "C"

void C_Down(int basic, int margin){
  digitalWrite(27, HIGH);
  random_delay(basic, margin);
}
void C_Up(int basic, int margin){
  digitalWrite(27, LOW);
  random_delay(basic, margin);
}

//========================== "V"

void V_Down(int basic, int margin){
  digitalWrite(28, HIGH);
  random_delay(basic, margin);
}
void V_Up(int basic, int margin){
  digitalWrite(28, LOW);
  random_delay(basic, margin);
}

//##########################
//##########[2열]###########
//##########################

//========================== "A"

void A_Down(int basic, int margin){
  digitalWrite(29, HIGH);
  random_delay(basic, margin);
}
void A_Up(int basic, int margin){
  digitalWrite(29, LOW);
  random_delay(basic, margin);
}

//========================== "D"

void D_Down(int basic, int margin){
  digitalWrite(30, HIGH);
  random_delay(basic, margin);
}
void D_Up(int basic, int margin){
  digitalWrite(30, LOW);
  random_delay(basic, margin);
}

//========================== "F"

void F_Down(int basic, int margin){
  digitalWrite(31, HIGH);
  random_delay(basic, margin);
}
void F_Up(int basic, int margin){
  digitalWrite(31, LOW);
  random_delay(basic, margin);
}