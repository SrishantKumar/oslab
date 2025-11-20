

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#include <math.h> 

int main() {
    int queue[100]; 
    int n;          
    int head;      
    int seek_count = 0;
    int serviced_count = 0;
    int visited[100] = {0}; 
    float avg_seek_time;

    printf("--- SSTF Disk Scheduling Simulation ---\n");

    
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
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int current_head = head;
    printf("\n--- Disk Head Movement ---\n");

    
    while (serviced_count < n) {
        int min_seek_distance = INT_MAX;
        int next_request_index = -1;

        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) { 
                int distance = abs(current_head - queue[i]);

                if (distance < min_seek_distance) {
                    min_seek_distance = distance;
                    next_request_index = i;
                }
            }
        }

        if (next_request_index != -1) {
            
            int next_cylinder = queue[next_request_index];

            printf("Move from %d to %d with seek distance %d\n", current_head, next_cylinder, min_seek_distance);

            
            seek_count += min_seek_distance;
            current_head = next_cylinder;
            visited[next_request_index] = 1;
            serviced_count++;

        } else {
            
            break;
        }
    }

    
    printf("\nTotal Seek Time (Total Head Movement): %d\n", seek_count);

   
    avg_seek_time = (float)seek_count / n;
    printf("Average Seek Time: %.2f\n", avg_seek_time);

    return 0;
}