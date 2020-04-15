This repository contains Two files:

(i) First come First Serve disk scheduling algorithm

It's a c program for First Come First Serve(FCFS) disk scheduling algorithm for the following question

Suppose that a disk drive has 5000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder 143, and the 
previous request was at cylinder 125. The queue of pending requests, in FIFO order is: 86, 1470, 913, 1774, 948, 1509, 1022, 1750, 
130.

(ii)  A scheduling program to implements processes with:
      Level 1 : Fixed priority preemptive Scheduling
      Level 2: Round Robin Scheduling
      
For a Fixed priority preemptive Scheduling (Queue1), the Priority 0 is highest priority. If one process P1 is scheduled and
running, another process P2 with higher priority comes. The New process (high priority) process P2 preempts currently running
process P1 and process P1 will go to second level queue. Time for which process will strictly execute must be considered in the
multiples of 2. All the processes in second level queue will complete their execution according to round robin scheduling.

