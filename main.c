/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
     int inputNumber = atoi(argv[1]);
     float averageWAM = 0;
     float weightedWAM = 0;
     float totalCredits = 0;
     studentRecordT *recordArray = malloc(inputNumber * sizeof(studentRecordT));
     assert(recordArray != NULL);
     for(int i = 0; i < inputNumber; i++){
       recordArray[i].zID = readValidID();
       recordArray[i].credits = readValidCredits();
       recordArray[i].WAM = readValidWAM();
     }
     for(int i = 0; i < inputNumber; i++){
       printStudentData(recordArray[i].zID, recordArray[i].credits, recordArray[i].WAM);
       averageWAM = averageWAM + recordArray[i].WAM;
       weightedWAM = weightedWAM + recordArray[i].WAM * recordArray[i].credits;
       totalCredits = totalCredits + recordArray[i].credits;
     }
     printf("Average WAM: %.3f\n", averageWAM / inputNumber);
     printf("Weighted average WAM: %.3f\n", weightedWAM / totalCredits);
      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch;

   List list = newLL(); // create a new linked list
   int studentId;
   int credits;
   float wam;

   int *n = NULL;
   float *wam_ = NULL;
   float *w_wam = NULL;

   //int *n = &list->length;
   
  
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
	   studentId = readValidID();
	   credits = readValidCredits();
	   wam = readValidWAM();
	   //insertLL(list, studentId, credits, wam);
	   insertOrderLL(list, studentId, credits, wam);
            /*** Insert your code for adding a student record ***/  
	   break;

         case 'f':
         case 'F':
	   studentId = readValidID();
	   inLL(list, studentId);

            /*** Insert your code for finding a student record ***/

	   break;
	    
         case 'g':
         case 'G':
	   
	   getStatLL(list, n, wam_, w_wam);
	   //getStatLL(list);
	   

            /*** Insert your code for getting statistical information ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
	   showLL(list);

            /*** Insert your code for printing all student records ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}
