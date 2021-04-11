#include "coSched.h"
#include <stdlib.h>




 //Define node as pointer of data type struct LinkedList

static n rhead;
static n dhead;
static n curtask;

void Init(void)
{

rhead = NULL;
dhead = NULL;
curtask = NULL;
}

void insertR(n temp){
n curs = rhead;
if (rhead==NULL){
            rhead=temp;
    }
    else{
        while(curs!=NULL){
         if (rhead->priority < temp->priority)
         {
             temp->next = rhead;
             rhead = temp;
             break;
         }
         else if ((curs->next->priority) < (temp->priority))
         {
                temp->next = curs->next;
              curs->next = temp;
                break;
         }
          
         else if (curs->next == NULL){
              curs->next = temp;
                break;
         }
         curs = curs->next;
        }

    }
}
void insertD(n temp){
n curs = dhead;
if (dhead==NULL){
            dhead=temp;
    }
    else{
        while(curs!=NULL){
         if (dhead->delay < temp->delay)
         {
           temp->next = rhead;
             rhead = temp;
             break;
         }
         else if (curs->next->delay < temp->delay)
         {
                temp->next = curs->next;
              curs->next = temp;
                break;
         }
          
         else if (curs->next == NULL){
              curs->next = temp;
                break;
         }
         curs = curs->next;
        }
    }
}

void QueTask(void (*tFun)(void), int priority){

  n temp = (n)malloc(sizeof(struct node));
    temp->tFun = tFun;
    temp->priority = priority;
    temp->next = NULL;
    insertR(temp);
    
}

void QueDelay(n nodeDelay){

  n temp = (n)malloc(sizeof(struct node));
  temp->tFun = nodeDelay->tFun;
    temp->priority = nodeDelay->priority;
    temp->delay = nodeDelay->delay;
    temp->next = NULL;
    insertD(temp);
    
}

void DecrementDelay(void){

n curs = dhead;

    while(curs!=NULL)
    {
      curs->delay = curs->delay -1;
        if (curs->delay == 0)
            QueTask(curs->tFun,curs->priority);
    }
}

void Dispatch(){
 //rhead->tFun();
 n curs = rhead->next;
    //free (rhead);
curtask = rhead;
rhead->next=NULL;
rhead = NULL;
rhead = curs;
curtask->tFun();
curtask = NULL;

}

void ReRunMe(int delay){
    
    curtask-> delay = delay;
    QueDelay(curtask);
}
void TaskA(){

// do something here
    printf("Task A\n");
   QueTask(&TaskB ,4);
    ReRunMe(2);
// Rerun again after 10 ticks (500 msec)
}
void TaskB(){

// do something here
    printf("Task B\n");
    QueTask(&TaskC ,7);
    ReRunMe(3);
// Rerun again after 10 ticks (500 msec)
 
}
void TaskC(){

// do something here
    printf("Task C\n");
    ReRunMe(4);
// Rerun again after 10 ticks (500 msec)
}
int main()
{
    Init();
    QueTask(&TaskA,3);
    QueTask(&TaskB,4); 
    QueTask(&TaskC,6);

    while (1) {
            Dispatch();
    }
}
