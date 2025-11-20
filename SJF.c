#include<stdio.h>

int main()
{
    int i = 0, pno[10], bt[10], n, wt[10], temp = 0, j, tt[10];
    float sum, at;
    
    printf("\nEnter the no of process: ");
    scanf("%d", &n);
    
    printf("\nEnter the burst time of each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("p%d: ", i);
        scanf("%d", &bt[i]);
        pno[i] = i;
    }
    
    // Sort processes according to burst time (SJF)
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                // Swap process numbers
                temp = pno[i];
                pno[i] = pno[j];
                pno[j] = temp;
            }
        }
    }
    
    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tt[0] = bt[0];
    sum = 0;
    
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tt[i] = wt[i] + bt[i];
        sum += wt[i];
    }
    
    at = sum / n;
    sum = 0;
    
    printf("\nprocess no\tburst time\twaiting time\tturn around time\n");
    for(i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t\t%d\t\t%d\n", pno[i], bt[i], wt[i], tt[i]);
        sum += tt[i];
    }
    
    printf("Average waiting time: %f\n", at);
    printf("Average turn around time: %f\n", sum/n);
    
    return 0;
}