


#ifndef coSched_h
#define coSched_h
#include<stdio.h>



#define TOTALTASKS   5   

/********************************************************
 API's Declarations
********************************************************/

 struct node {
    int priority;
    int delay;
    void (*tFun)(void);
    struct node *next;
};

 void TaskA(void);
typedef  struct node* n;


void QueTask(void (*tFun)(void), int priority);
void insertR(n temp);

void ReRunMe(int delay);
void QueDelay(n nodeDelay);
void DecrementDelay(void);
void insertD(n temp);

void Dispatch(void);
void Init(void);
void TaskA();
void TaskB();
void TaskC();

#endif //#ifndef coSched_H
