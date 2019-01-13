/*int SensorValStore_Prev[8][8] = { {0,0,0,0,0,0,0,0}, \
                                  {0,0,0,0,0,0,0,0}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {0,0,0,0,0,0,0,0}, \
                                  {0,0,0,0,0,0,0,0}};

int SensorValStore_Curr[8][8]={ {0,0,0,0,0,0,0,0}, \
                                  {0,0,0,0,0,0,0,0}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,1,1,1,1,1,1}, \
                                  {1,1,0,1,1,1,1,1}, \
                                  {0,0,0,0,0,0,0,0}, \
                                  {0,1,0,0,0,0,0,0}};*/ // Testing If move generation works
int SensorValStore_Prev[8][], SensorValStore_Curr[8][];
bool isSent = false,isWrongMove,isCheck,isCompMove;
int sum1[8],sum2[8],temp[8][8],k,l,i,j,rank,nextRow,limit;
String file,moveSan,Temp,bestMove;
char Buffer[20];
void doAction();        // #1
void ReadSensor();      // #2
void binToIntCalc();    // #3
void Difference();      // #4
void check();           // #5
void getMovePlayed();   // #6
void SendMove();        // #7
void getMove();         // #8
void SendStringtoLcd(); // #9
void validateMove();    // #10

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(22,INPUT_PULLUP); // Reed switch - Row1
  pinMode(24,INPUT_PULLUP); // Reed switch - Row2
  pinMode(26,INPUT_PULLUP); // Reed switch - Row3
  pinMode(28,INPUT_PULLUP); // Reed switch - Row4
  pinMode(30,INPUT_PULLUP); // Reed switch - Row5 
  pinMode(32,INPUT_PULLUP); // Reed switch - Row6 
  pinMode(34,INPUT_PULLUP); // Reed switch - Row7 
  pinMode(36,INPUT_PULLUP); // Reed switch - Row8 
  pinMode(11,INPUT_PULLUP);// Push Button
  pinMode(38,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(38,HIGH);
  digitalWrite(40,HIGH);
  digitalWrite(42,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(46,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,HIGH);
  digitalWrite(12,LOW);
  }
void loop() {
  
//while( digitalRead(11) == 0 ) // If pushbutton is pressed
 //{
   isCompMove = false;
   isWrongMove = false;
   //doAction();
   delay(40);
   binToIntCalc();
   delay(40);
    Difference();
   delay(40);
   check();
   delay(40);
   getMovePlayed();
   delay(40);
   getMove();
   delay(40);
   if(isWrongMove == true)
//   continue;
   validateMove();
   delay(40);
 //}
}

void Print(int matrix[8][8]) // For debugging
{
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++)
    {
      Serial.print(matrix[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void doAction() // #1
{
   nextRow = 0;
   for(i=0;i<8;i++)
    {
      
      digitalWrite(38 + nextRow,LOW);
      delay(40);
      ReadSensor(i);
      digitalWrite(38 + nextRow,HIGH);
      delay(40);
      nextRow +=2;
    }
}

void ReadSensor(int iter) // #2
{
   delay(10);
   for(j=0;j<8;j++)
   SensorValStore_Curr[iter][j] = digitalRead(j+2);
}

void binToIntCalc() // #3
{
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
    {
       sum1[i] += pow(2,j)*SensorValStore_Prev[i][j];
       sum2[i] += pow(2,j)*SensorValStore_Curr[i][j];
    }
 }
 
void Difference() // #4
{
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      temp[i][j] = abs(SensorValStore_Curr[i][j] - SensorValStore_Prev[i][j]);
  
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      SensorValStore_Prev[i][j] == SensorValStore_Curr[i][j];
 }
 
void check() // #5
{
  k=0;
  l=0;
  for(i=0;i<8;i++)
  {   
    if(sum2[i]>sum1[i])
       k = i;
    if(sum2[i]<sum1[i])
       l = i;
   delay(40);
  }
}
   
void getMovePlayed() // #6
{
   for(j=0;j<8;j++)
   {    
      if(temp[k][j] == 1)
      {
         rank =k+1;
         file = String(char(97+j));
         delay(40);
         moveSan = file + rank;
         Temp = moveSan;
      }
   }
   for(j=0;j<8;j++)
   { 
     if( temp[l][j] == 1)
     {
       rank =l+1;
       file = String(char(97+j));
       delay(40);
       moveSan = file + rank;
       Temp.concat(moveSan);
     }
   }  
   if(isCompMove == false)
   SendMove(Temp);
} 
   
void SendMove(String movePlayed) // #7
{
  Serial.println("start");
  Serial.println(movePlayed);
}
  
void getMove() // #8
{
  while(1)
  {
    if (Serial.available()>0) 
    {
       bestMove = Serial1.readString();
       if (bestMove == "NV")
       {
         SendStringtoLcd("Wrong Move");
         isWrongMove = true;
       }
       else
       {
         SendStringtoLcd(bestMove);
         delay(40);  
         validateMove(bestMove);
         delay(40);
       break;
    }
  }
}
}

void SendStringtoLcd(String lcdString)// #9
{
  while(1){
   Serial1.println(lcdString);   
   delay(100);
  }
}
void validateMove(String compMove) // #10 -To validate move played by computer
{
while(1)
{  
if(digitalRead(11)==0)
{
  isCompMove = true;
  doAction();
  delay(40);
  binToIntCalc();
  delay(40);
  Difference();
  delay(40);
  check();
  delay(40);
  getMovePlayed();
  delay(40);
  if(compMove == Temp)
  {
    SendStringtoLcd("validated");
    delay(2000);
    SendStringtoLcd("human's turn");
    isCheck == true;
  }
  else
    SendStringtoLcd("Wrong Move");
    isCheck == false;
 }
if(isCheck == true)
break;
}
}

  
  


