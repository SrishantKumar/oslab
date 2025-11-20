#include <stdio.h>
#include <stdlib.h> 

int main() {
    int queue[100]; 
    int n;          
    int head;      
    int seek_count = 0;
    float avg_seek_time;

    printf("--- FCFS Disk Scheduling Simulation ---\n");

   
    printf("Enter the initial head position (cylinder number): ");
    if (scanf("%d", &head) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    
    printf("Enter the number of disk requests: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid number of requests. Exiting.\n");
        return 1;
    }

    
    printf("Enter the request queue (cylinder numbers separated by spaces):\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &queue[i]);
    }

    
    queue[0] = head;

    printf("\n--- Disk Head Movement ---\n");


    for (int i = 0; i < n; i++) {
        int current_cylinder = queue[i];
        int next_cylinder = queue[i + 1];

      
        int distance = abs(next_cylinder - current_cylinder);

        
        seek_count += distance;

        printf("Move from %d to %d with seek distance %d\n", current_cylinder, next_cylinder, distance);
    }

   
    printf("\nTotal Seek Time (Total Head Movement): %d\n", seek_count);

    
    avg_seek_time = (float)seek_count / n;
    printf("Average Seek Time: %.2f\n", avg_seek_time);

    return 0;
}