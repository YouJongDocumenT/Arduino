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

int fordom, lfordom, rfordom, rcycle, lcycle, tsp, pown, rskill, skill, meso;

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

    for(int i = 1; i <= 4; i++){
      lfordom = random(2,5);
      for(int i = 1; i < lfordom; i++){
        Left_Down();
        random_delay(100,30);
        Left_Up();
        random_delay(60,20);
      }
    lcycle = random(3, 4);
    for(int i = 1; i <= lcycle; i++){
      Jump_cs();    
    }
    rfordom = random(2,5);
    for(int i = 1; i < rfordom; i++){
      Right_Down();
      random_delay(100,30);
      Right_Up();
      random_delay(60,20);
    }
    rcycle = random(3, 4);
    for(int i = 1; i <= rcycle; i++){
      Jump_cs();
    }
  }

      lfordom = random(2,5);
      for(int i = 1; i < lfordom; i++){
        Left_Down();
        random_delay(100,30);
        Left_Up();
        random_delay(60,20);
      }
    lcycle = random(4, 5);
    for(int i = 1; i <= lcycle; i++){
      Jump_cs();    
    }
    rfordom = random(2,5);
    for(int i = 1; i < rfordom; i++){
      Right_Down();
      random_delay(100,30);
      Right_Up();
      random_delay(60,20);
    }
    rcycle = random(3, 4);
    for(int i = 1; i <= rcycle; i++){
      Jump_cs();
    }

  Up_Jump();
  
}

void Build_Start(){
    Down_Down();
    random_delay(300,50);
    D_Down();
    random_delay(300,50);
    D_Up();
    random_delay(500,100);
    V_Down();
    random_delay(200,50);
    V_Up();
    random_delay(50,20);
    A_Down();
    random_delay(200,70);
    A_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);    
    Down_Up();
    random_delay(300,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 파운틴 설치 후 아랫점 써든메익  
    Left_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up();
    random_delay(100,50);
    Up_Down();
    random_delay(100,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Right_Down();
    random_delay(100,50);
    Alt_Down();
    random_delay(100,30);
    Alt_Up();
    random_delay(50,20); 
    Right_Up();
    random_delay(50,20); 
    Up_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(100,20);
    //@@@@@@@@@@@@@@d@@@@@@@@@@@@@@@@@@@@@@@@@ 왼쪽 점프3번 어썰트 3층 진입 후 메익
    Right_Down();
    random_delay(100,30);
    V_Down();
    random_delay(100,30);
    C_Down();
    random_delay(100,30);
    X_Down();
    random_delay(100,30);
    Z_Down();
    random_delay(100,30);
    V_Up();
    random_delay(50,20);
    C_Up();
    random_delay(50,20);
    X_Up();
    random_delay(50,20);
    Z_Up();
    random_delay(50,20);
    Right_Up();
    random_delay(350,50);  
    F_Down();
    random_delay(300,50);
    F_Up();
    random_delay(900,90);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 크스메익 후 플레어
    Left_Down();
    random_delay(100,30);
    V_Down();
    random_delay(100,30);
    C_Down();
    random_delay(100,30);
    X_Down();
    random_delay(100,30);
    Z_Down();
    random_delay(100,30);
    V_Up();
    random_delay(50,20);
    C_Up();
    random_delay(50,20);
    X_Up();
    random_delay(50,20);
    Z_Up();
    random_delay(50,20);
    Left_Up();
    random_delay(500,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 왼쪽 점프 크스메익 후 3층 복귀  
    Down_Down();
    random_delay(200,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Delete_Down();
    random_delay(300,50);
    Delete_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(250,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 아랫점프 절개메익
    V_Down();
    random_delay(200,50);
    V_Up();
    random_delay(50,20);
    X_Down();
    random_delay(200,70);
    X_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);    
    Down_Up();
    random_delay(300,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 아랫점프 크스메익
    Right_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Right_Up();
    random_delay(100,50); // 중요
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번 후 [ 딜레이 ] 중요
}


void Left_cycle(){
    Left_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up();
    random_delay(100,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번
    Up_Down();
    random_delay(100,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Right_Down();
    random_delay(100,50);
    Alt_Down();
    random_delay(100,30);
    Alt_Up();
    random_delay(50,20); 
    Right_Up();
    random_delay(50,20); 
    Up_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);
    Left_Down();
    random_delay(350,30);
    Left_Up();
    random_delay(2500,200);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 윗점 어썰트 후 3층 복귀 [ 딜레이 ]
}

void Left_cycle_Nodelay(){
    Left_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Jump_cs();
    Left_Up();
    random_delay(100,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번
    Up_Down();
    random_delay(100,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Right_Down();
    random_delay(100,50);
    Alt_Down();
    random_delay(100,30);
    Alt_Up();
    random_delay(50,20); 
    Right_Up();
    random_delay(50,20); 
    Up_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);
    Left_Down();
    random_delay(350,30);
    Left_Up();
    random_delay(1300,100);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 윗점 어썰트 후 3층 복귀 [ 딜레이 ]
}

void Right_cycle(){
    Down_Down();
    random_delay(200,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Delete_Down();
    random_delay(300,50);
    Delete_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(250,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 아랫점프 절개메익
    V_Down();
    random_delay(200,50);
    V_Up();
    random_delay(50,20);
    X_Down();
    random_delay(200,70);
    X_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);    
    Down_Up();
    random_delay(300,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 애랫점프 크스메익
    Right_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Right_Up();
    random_delay(2900,200); // 중요
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번 후 [ 딜레이 ]
}



void Right_cycle_Nodelay(){
    Down_Down();
    random_delay(200,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Delete_Down();
    random_delay(300,50);
    Delete_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(250,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 아랫점프 절개메익
    V_Down();
    random_delay(200,50);
    V_Up();
    random_delay(50,20);
    X_Down();
    random_delay(200,70);
    X_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);    
    Down_Up();
    random_delay(300,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 애랫점프 크스메익
    Right_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Right_Up();
    random_delay(50,20); // 중요
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번 후 [ 딜레이X ]
}

void Right_cycle_Middledelay(){
    Down_Down();
    random_delay(200,50);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,20);
    Delete_Down();
    random_delay(300,50);
    Delete_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(250,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 아랫점프 절개메익
    V_Down();
    random_delay(200,50);
    V_Up();
    random_delay(50,20);
    X_Down();
    random_delay(200,70);
    X_Up();
    random_delay(50,20);
    Z_Down();
    random_delay(100,50);
    Z_Up();
    random_delay(50,20);    
    Down_Up();
    random_delay(300,50);
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 애랫점프 크스메익
    Right_Down();
    random_delay(100,50);
    Jump_cs();
    Jump_cs();
    Right_Up();
    random_delay(1900,100); // 중요
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오른쪽 점프 3번 후 [ 딜레이X ]
}


void Up_Jump(){
    Up_Down();
    random_delay(100,30);
    Left_Down();
    random_delay(400,50);
    V_Down();
    random_delay(100,30);
    C_Down();
    random_delay(100,30);
    Up_Up();
    random_delay(50,20);
    V_Up();
    random_delay(50,20);
    C_Up();
    random_delay(50,20);
    Left_Up();
    Right_Down();
    random_delay(1200,100);
    Right_Up();
    random_delay(500,50);
}


void Jump_cs(){

  tsp = random(1,7);
  if(tsp == 1){

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    X_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    X_Up();
    Z_Up();
    random_delay(600,80);
  }else if(tsp == 2){

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    X_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    X_Up();
    Z_Up();
    random_delay(600,80);
  }else if(tsp == 3){

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    PageUp_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    PageUp_Up();
    Z_Up();
    random_delay(600,80);
  }else if(tsp == 4){

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    Insert_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    Insert_Up();
    Z_Up();
    random_delay(600,80);
  }else if(tsp == 5){

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    Home_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    Home_Up();
    Z_Up();
    random_delay(600,80);
  }else{

    meso = random(1, 3);
    if(meso == 1){
      Z_Down();
      random_delay(50,10);
      Z_Up();
      random_delay(50,10);    
    }
    
    V_Down();
    random_delay(100,50);
    V_Up();
    random_delay(50,10);
    V_Down();
    random_delay(120,30);
    C_Down();
    random_delay(120,30);

    skill = random(1, 7);
    if(skill == 1){
      Ctrl_Down();
      random_delay(50,10);
      Ctrl_Up();
      random_delay(50,10);
    }else if(skill == 4){
      PageDown_Down();
      random_delay(50,10);
      PageDown_Up();
      random_delay(50,10);
    }
    
    Insert_Down();
    random_delay(100,50);
    Z_Down();
    random_delay(100,50);
    V_Up();
    C_Up();
    Insert_Up();
    Z_Up();
    random_delay(600,80);
  }
}





//##########################
//#########[방향키]##########
//##########################

//========================== "↑"

void Up_Down(){
  digitalWrite(2, HIGH);
}
void Up_Up(){
  digitalWrite(2, LOW);
}

//========================== "↓"

void Down_Down(){
  digitalWrite(3, HIGH);
}
void Down_Up(){
  digitalWrite(3, LOW);
}

//========================== "←"

void Left_Down(){
  digitalWrite(4, HIGH);
}
void Left_Up(){
  digitalWrite(4, LOW);
}

//========================== "→"

void Right_Down(){
  digitalWrite(5, HIGH);
}
void Right_Up(){
  digitalWrite(5, LOW);
}

//##########################
//#########[특수키]##########
//##########################

//========================== "Insert"

void Insert_Down(){
  digitalWrite(6, HIGH);
}
void Insert_Up(){
  digitalWrite(6, LOW);
}

//========================== "Home"

void Home_Down(){
  digitalWrite(7, HIGH);
}
void Home_Up(){
  digitalWrite(7, LOW);
}

//========================== "PageUp"

void PageUp_Down(){
  digitalWrite(8, HIGH);
}
void PageUp_Up(){
  digitalWrite(8, LOW);
}

//========================== "Delete"

void Delete_Down(){
  digitalWrite(9, HIGH);
}
void Delete_Up(){
  digitalWrite(9, LOW);
}

//========================== "End"

void End_Down(){
  digitalWrite(10, HIGH);
}
void End_Up(){
  digitalWrite(10, LOW);
}

//========================== "PageDown"

void PageDown_Down(){
  digitalWrite(11, HIGH);
}
void PageDown_Up(){
  digitalWrite(11, LOW);
}

//##########################
//########[사이드키]#########
//##########################

//========================== "RShift"

void RShift_Down(){
  digitalWrite(12, HIGH);
}
void RShift_Up(){
  digitalWrite(12, LOW);
}

//========================== "Ctrl"

void Ctrl_Down(){
  digitalWrite(22, HIGH);
}
void Ctrl_Up(){
  digitalWrite(22, LOW);
}

//========================== "Alt"

void Alt_Down(){
  digitalWrite(23, HIGH);
}
void Alt_Up(){
  digitalWrite(23, LOW);
}

//========================== "LShift"

void LShift_Down(){
  digitalWrite(24, HIGH);
}
void LShift_Up(){
  digitalWrite(24, LOW);
}

//##########################
//##########[3열]###########
//##########################

//========================== "Z"

void Z_Down(){
  digitalWrite(25, HIGH);
}
void Z_Up(){
  digitalWrite(25, LOW);
}

//========================== "X"

void X_Down(){
  digitalWrite(26, HIGH);
}
void X_Up(){
  digitalWrite(26, LOW);
}

//========================== "C"

void C_Down(){
  digitalWrite(27, HIGH);
}
void C_Up(){
  digitalWrite(27, LOW);
}

//========================== "V"

void V_Down(){
  digitalWrite(28, HIGH);
}
void V_Up(){
  digitalWrite(28, LOW);
}

//##########################
//##########[2열]###########
//##########################

//========================== "A"

void A_Down(){
  digitalWrite(29, HIGH);
}
void A_Up(){
  digitalWrite(29, LOW);
}

//========================== "D"

void D_Down(){
  digitalWrite(30, HIGH);
}
void D_Up(){
  digitalWrite(30, LOW);
}

//========================== "F"

void F_Down(){
  digitalWrite(31, HIGH);
}
void F_Up(){
  digitalWrite(31, LOW);
}
