# Cooperative-scheduler
Ashraf Ibrahim 900152964
Nourhan Mokbel 900162020
# Project Explanation
We developed two queues using linkedlist. The two queues are ready and delay queue. Each queue has its own head which are rhead and dhead,respectively. Moreover, extra pointer called curtask is used to point to current task to be excuted from the dipatch function. Quetask function is used to answer the task into ready queue according to its pirority. Where our highest pirority is considered to be our rhead as for delay queue is used to answer the tasks node into the delay queue according to its delay and it is called from the ReRun function.
# software
    keiluvision5
    STM32CubeMX
# Hardware
    STM32l432KC " STM32 Nucleo Board"
    RTC DS3231
# Unit Tests
In first screenshot: taskA is queued from the main. taskB is queued from A and C is queued from B while dispatch is continuously running in while loop present in the main 
# Applications
    Ambient temperature monitor
    Parking sensor 
