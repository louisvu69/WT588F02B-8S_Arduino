

#define UC8 unsigned char
#define CLK_2A 13
#define P_DATA_2A 11
#define CS_2A 10
void Line_2A_WT588F(unsigned char DDATA) {
  unsigned char S_DATA, j;
  bool B_DATA;

  digitalWrite(CLK_2A, 1);
  digitalWrite(P_DATA_2A, 1);
  S_DATA = DDATA;
  digitalWrite(CLK_2A, 0);
  delay(5);  //delay 5ms
  // B_DATA = S_DATA & 0X01;
  for (j = 0; j < 8; j++) {
    digitalWrite(CLK_2A, 1);
    digitalWrite(P_DATA_2A, B_DATA & 0x01);
    delay(1);  //delay 300us
    digitalWrite(CLK_2A, 0);
    delay(1);  //delay 300us
    S_DATA = S_DATA >> 1;
    B_DATA = S_DATA & 0X01;
  }
  digitalWrite(P_DATA_2A, 1);
  digitalWrite(CLK_2A, 1);
}
void List_2A_Play_WT588F(uint8_t a) {
  Line_2A_WT588F(0xF3);
  delay(2);  //delay 2ms
  Line_2A_WT588F(a);
  delay(2);
  // Line_2A_WT588F(0xF3);
  // delay(2);
  // Line_2A_WT588F(0x02);
  // delay(2);
  // Line_2A_WT588F(0xF3);
  // delay(2);
  // Line_2A_WT588F(0x03);
  // delay(2);
}
void setup() {
  delay(500);
  // put your setup code here, to run once:
  pinMode(CLK_2A, OUTPUT);
  pinMode(P_DATA_2A, OUTPUT);
  pinMode(CS_2A, OUTPUT);
  digitalWrite(CS_2A, 0);
  // P_DATA = 1;
  digitalWrite(P_DATA_2A, 1);
  digitalWrite(CLK_2A, 1);
  List_2A_Play_WT588F(0x01);
  List_2A_Play_WT588F(0xEF);

}

void loop() {
  // put your main code here, to run repeatedly:
  // for (int i = 0; i <= 255; i++) {
    
    
  //   delay(2);
  // }
}
/*--------------------------------------
// ; Module name: Line_2A_WT588F(UC8 DDATA);Function: Realize two-line serial communication function; Input parameters: DDATA is sending data
// ; Output parameters:
// ; CLK_2A //clock line
// ; P_DATA_2A //Data line;-------------------------------------*/
