#include <stdio.h>
#include <math.h>
struct process
    {
        int processNumber, burstTime, arrivalTime, priority;
    };
int main()
{
    struct process a[100], b[100];
    int totalProcess = 0;
    int timeQuantum = 2;
    int lenB = 0;
    printf("Enter total number of process: ");
    scanf("%d", &totalProcess);
    int i = 0;
    for (i = 0; i < totalProcess; i++)
    {
        printf("Enter the process number : ");
        scanf("%d", &a[i].processNumber);
        printf("Enter the burst time for the process: ");
        scanf("%d", &a[i].burstTime);
        printf("Enter the arrival time for the process : ");
        scanf("%d", &a[i].arrivalTime);
        printf("Enter the priority for the process : ");
        scanf("%d", &a[i].priority);
    }
    printf("==============================================");
    printf("\n Processes for Priority Scheduling");
    for(i = 0; i < totalProcess; i++)
    {
    	printf("\n %d\t %d\t %d\t %d ", a[i].processNumber, a[i].burstTime, a[i].arrivalTime, a[i].priority);
	}
    for (i = 0; i < totalProcess - 1; i++)
    {
    	int j = 0;
        for(j = i; j < totalProcess; j++)
		if(a[i].arrivalTime > a[j].arrivalTime)
		{
			int temp = a[i].arrivalTime;
			a[i].arrivalTime = a[j].arrivalTime;
			a[j].arrivalTime = temp;
		} 
    }
    
    for (i = 0; i < totalProcess - 1; i++)
    {
    	int j = 0;
    	int leastPriority = a[i].priority;
    	for(j = i; j < totalProcess; j++)
    	{
			if (leastPriority > a[j].priority)
			{
				a[i].burstTime = a[i].burstTime - (a[j].arrivalTime - a[i].arrivalTime);
				if(a[i].burstTime <= 0)
				{
					continue;
				}
				else
				{
					b[i] = a[i];
					lenB++;
					printf("Process number %d not executed completely\n", a[i].processNumber);
				}
			}
		}
    }
    printf("\n==============================================");
    printf("\n Processes for Round Robin");
    for(i = 0; i < lenB; i++)
    {
    	printf("\n %d\t %d\t %d\t %d ", b[i].processNumber, b[i].burstTime, b[i].arrivalTime, b[i].priority);
	}
	int largestBurstTime = 0;
	for(i = 0; i < lenB; i++)
	{
		if(b[i].burstTime > largestBurstTime)
		{
			largestBurstTime = b[i].burstTime;
		}
	}
    for(i = 0; i < lenB - 1; i++)
    {
    	int j = i;
    	for(j = i; i < lenB; j++)
    	{
    		if(b[i].arrivalTime > b[j].arrivalTime)
			{
				int temp = b[i].arrivalTime;
				b[i].arrivalTime = b[j].arrivalTime;
				b[j].arrivalTime = temp;
			} 	
		}
	}
	
	int loop = round(largestBurstTime/2);
	
	for(i = 0; i < loop; i++)
	{
		int j = 0;
		for(j = i; j < lenB; j++)
		{
			if(b[j].burstTime != 0)
			{
				b[j].burstTime = b[j].burstTime - timeQuantum;
				printf("Remaining burst time for process %d is %d \n", b[i].processNumber, b[i].burstTime);
			}
		}
	}
	printf("All process completed");
}
