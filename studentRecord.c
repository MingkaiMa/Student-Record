// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>
#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
  int validID;
  printf("Enter student ID: ");
  while(1){
    validID = readInt();
    if(validID >= 1000000 && validID <= 9999999){
      return validID;
    }
    else{
      printf("Not valid. Enter a valid value: ");
      continue;
    }
  }   
}

int readValidCredits(void) {
  int validCredits;
  printf("Enter credit points: ");
  while(1){
    validCredits = readInt();
    if(validCredits >=2 && validCredits <= 48){
      return validCredits;
    }
    else{
      printf("Not valid. Enter a valid value: ");
      continue;
    }
  }
}

float readValidWAM(void) {
  float validWAM;
  printf("Enter WAM: ");
  while(1){
    validWAM = readFloat();
    if(validWAM >= 50 && validWAM <= 100){
      return validWAM;
    }
    else{
      printf("Not valid. Enter a valid value: ");
      continue;
    }
  }
}

void printStudentData(int zID, int credits, float WAM) {
  printf("------------------------\n");
  printf("Student zID: z%d\n", zID);
  printf("Credits: %d\n", credits);
  printf("Level of performance: ");
  if(WAM < 50){
    printf("FL\n");
  }else if(WAM >= 50 && WAM < 65){
    printf("PS\n");
  }else if(WAM >= 65 && WAM < 75){
    printf("CR\n");
  }else if(WAM >= 75 && WAM < 85){
    printf("DN\n");
  }else {
    printf("HD\n");
  }
  printf("------------------------\n");
  
  return;  /* needs to be replaced */
}

