#include<stdio.h>

struct process
{
    int burst;
    int rem_burst;
    int wait;
    int finished;
};

int main()
{
    int n, i, time = 0, quantum;
    int totalwait = 0, totalturn = 0;
    
    struct process p[20]; 
    
    printf("\nEnter The No Of Process:");
    scanf("%d", &n);
    
    printf("\nEnter The Quantum time (in ms) :");
    scanf("%d", &quantum);
    
    for (i = 0; i < n; i++)
    {
        printf("Enter The Burst Time (in ms) For Process #%2d :", i + 1);
        scanf("%d", &p[i].burst);
        
        p[i].rem_burst = p[i].burst;
        p[i].wait = 0;
        p[i].finished = 0;
    }
    
    printf("\nOrder Of Execution \n");
    printf("\nProcess Starting Ending Remaining");
    printf("\n\t\tTime \tTime \t Time");
    
    int completed_processes = 0;
    int last_preempt_time[n]; 
    for(i=0; i<n; i++) {
        last_preempt_time[i] = 0;
    }

    while (completed_processes < n)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i].finished == 0)
            {
                p[i].wait += (time - last_preempt_time[i]); 

                int execute_time = (p[i].rem_burst > quantum) ? quantum : p[i].rem_burst;
                
                int starting_time = time;
                time += execute_time;

                p[i].rem_burst -= execute_time;
                last_preempt_time[i] = time;

                printf("\nprocess # %-3d %-10d %-10d %-10d", 
                       i + 1, starting_time, time, p[i].rem_burst);
                
                if (p[i].rem_burst == 0)
                {
                    p[i].finished = 1;
                    completed_processes++;
                }
            }
        }
    }
    
    printf("\n\n-------------------------------------------------------------");
    printf("\nProcess \t Waiting Time \t TurnAround Time ");
    
    for (i = 0; i < n; i++)
    {
        int turnaround_time = p[i].wait + p[i].burst;
        
        printf("\nProcess #%-12d %-15d %-15d", i + 1, p[i].wait, turnaround_time);
        
        totalwait += p[i].wait;
        totalturn += turnaround_time;
    }
    
    printf("\n\nAverage\n--------------------");
    printf("\nWaiting Time: %fms", totalwait / (float)n);
    printf("\nTurn Around Time: %fms\n\n", totalturn / (float)n);
    
    return 0;
}