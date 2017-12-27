int NORTH = A8;
int SOUTH = A10;
int EAST = A9;
int WEST = A11;


//Transceiver Direction Mode//

//const int RobotReadings = 7;
//int DirectionArray[7];

int robotDirection;
int index = 0;
char Direction[9];

void setup()
{
  Serial.begin(9600);
 
}

/* void loop()
{
  
  robotDir = 0;
  robotDir = getBeaconDirection();
  printBeacon();
  delay(500);
}
*/

void loop()
{
  
  for (int index = 0; index < 9 ; index++)
  {
    SCANDIRECTION();
    WHICHDIRECTION(index);
    delay(100);
  }
  PrintDirection();
  delay (2000); // 5 second delay
  for (int i = 0; i <7 ; i++)
  {
    Direction[index] = ' ';
  }
}

void PrintDirection()
{
  Serial.println(Direction);
}

 
void SCANDIRECTION()
{
   NORTH = analogRead(A8);
   SOUTH = analogRead(A10);
   EAST = analogRead(A9);
   WEST = analogRead(A11);
}

void WHICHDIRECTION(int index )
{
  
  // Case 1: BEACON NORTH
  if (NORTH < 900 && SOUTH > 500 && EAST > 500 && WEST > 500) 
  {
    Direction[index] = 'N';
    robotDirection = 0;   // Face Forward [ DO NOT TURN AROUND]
  }
  // CASE 2: BEACON SOUTH
  else if (NORTH > 500 && SOUTH < 900 && EAST > 500 && WEST > 500)
  {
     Direction[index] = 'S';
     robotDirection = 1;
  }
  // CASE 3: BEACON EAST
  else if (NORTH > 500 && SOUTH > 500 && EAST < 900 && WEST > 500)
  {
     Direction[index] = 'E';
     robotDirection = 2; // TURN RIGHT
  }
  // CASE 4: BEACON WEST
  else if (NORTH > 500 && SOUTH > 500 && EAST > 500 && WEST < 900)
  {
     Direction[index] = 'W';
     robotDirection = 3; // TURN LEFT
  }
  
}

#define North A1

void setup(){
  Serial.begin(9600);
  pinMode(North,INPUT);
   B
}

void loop()

{
  
  int range;
  range = analogRead(North);
  Serial.println(range);
  
  delay(100);
}﻿



