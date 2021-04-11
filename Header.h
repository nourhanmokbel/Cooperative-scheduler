//
//  Header.h
//  scheduler
//
//  Created by Nourhan Mokbel on 4/10/21.
//

#ifndef Header_h
#define Header_h
#include<stdio.h>

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/

#define TOTALTASKS   5    // The maximum number of tasks (max value is 255 because all id's are chosen to be char variables)

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
