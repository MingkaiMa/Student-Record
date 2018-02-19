#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
  int length;
  NodeT *head;

/* Add more fields if you wish */

} ListRep;

NodeT *makeNewNode(int id, int cr, float wam){
  NodeT *new = malloc(sizeof(NodeT));
  new->data.zID = id;
  new->data.credits = cr;
  new->data.WAM = wam;
  new->next = NULL;
  return new;
}
/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: 
// Explanation: 
List newLL() {
  List L = malloc(sizeof(ListRep));
  L->length = 0;
  L->head = NULL;
  return L;  /* needs to be replaced */
}

// Time complexity: 
// Explanation: 
void dropLL(List listp) {
  NodeT *p = listp->head;
  while(p != NULL){
    NodeT *temp = p->next;
    free(p);
    p = temp;
  }
  free(listp);
  return;  /* needs to be replaced */
}

// Time complexity: 
// Explanation: 
void inLL(List listp, int zid) {
  NodeT *p = listp->head;
  int studentId = zid;
  while(p != NULL){
    if(p->data.zID == studentId){
      printStudentData(p->data.zID, p->data.credits, p->data.WAM);
      return;
    }else{
      p = p->next;
    }
    
  }
  printf("No record found.\n");
  return;  /* needs to be replaced */
}

// Time complexity: 
// Explanation: 
void insertLL(List listp, int zid, int cr, float wam) {
  NodeT *new = makeNewNode(zid, cr, wam);
  if(listp->head == NULL){
    listp->head = new;
    listp->length++;
    printf("Student record added.\n");
  }else{
    new->next = listp->head;
    listp->head = new;
    listp->length++;
    printf("Student record added.\n");
  }
   return;  /* needs to be replaced */
}

void insertOrderLL(List listp, int zid, int cr, float wam){
  NodeT *new = makeNewNode(zid, cr, wam);
  NodeT *p = listp->head;
  if(listp->head == NULL){
    listp->head = new;
    listp->length++;
    printf("Student record added.\n");
    return;
  }else if(listp->head->data.zID == zid){
    new->next = listp->head->next;
    listp->head = new;
    printf("Student record updated.\n");
    return;
  }else if(listp->head->data.zID > zid){
    new->next = listp->head;
    listp->head = new;
    listp->length++;
    printf("Student record added.\n");
    return;
  }else{
    while(p->next != NULL){
      if (p->next->data.zID == zid){
	p->next->data.credits = cr;
	p->next->data.WAM = wam;
	printf("Student record updates.\n");
	return;
      }else if(p->next->data.zID > zid){
	new->next = p->next;
	p->next = new;
	listp->length++;
	printf("Student record added.\n");
	return;
      }else{
	p = p->next;
      }
    }
    p->next = new;
    listp->length++;
    printf("Student record added.\n");
    return;
  }

  return;
}


// Time complexity: 
// Explanation: 
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
  float sum_wam_result = 0;
  float sum_w_wam_result = 0;
  int sum_credits = 0;
  float wam_;
  float w_wam_;
  NodeT *p = listp->head;
  while(p != NULL){
    sum_wam_result += p->data.WAM;
    sum_w_wam_result += p->data.WAM * p->data.credits;
    sum_credits += p->data.credits;
    p = p->next;
  }

  wam_ = sum_wam_result / listp->length;
  w_wam_ = sum_w_wam_result / sum_credits;

  n = &listp->length;
  wam = &wam_;
  w_wam = &w_wam_;
  
  printf("Number of records: %d\n", *n);
  printf("Average WAM: %.3f\n", *wam);
  printf("Average weighted WAM: %.3f\n", *w_wam);
  return;  /* needs to be replaced */
}

// Time complexity: 
// Explanation: 
void showLL(List listp) {
  NodeT *p = listp->head;
  while(p != NULL){
    printStudentData(p->data.zID, p->data.credits, p->data.WAM);
    p = p->next;
  }
  return;  /* needs to be replaced */
}
