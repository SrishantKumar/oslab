#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int isPagePresent(int page, const int frames[], int frame_size) {
    for (int i = 0; i < frame_size; i++) {
        if (frames[i] == page) {
            return 1; 
        }
    }
    return 0;
}


void printFrames(const int frames[], int frame_size, int page_fault) {
    for (int i = 0; i < frame_size; i++) {
        if (frames[i] == -1) {
            printf("[ ] "); 
        } else {
            printf("[%d] ", frames[i]);
        }
    }
    if (page_fault) {
        printf("--> F (Page Fault)\n");
    } else {
        printf("\n");
    }
}


int findLRU(const int frames[], int frame_size, const int page_reference[], int current_time) {
    int lru_index = -1;
    int max_distance = -1; 

    for (int i = 0; i < frame_size; i++) {
        int page = frames[i];
        int last_used_time = -1;

        for (int j = current_time - 1; j >= 0; j--) {
            if (page_reference[j] == page) {
                last_used_time = j;
                break;
            }
        }

        if (last_used_time < max_distance || lru_index == -1) {
             max_distance = last_used_time;
             lru_index = i;
        }
    }
    return lru_index;
}

int main() {
    int frame_size;
    int page_count;
    int page_reference[100];
    int frames[10];
    int page_faults = 0;

    printf("--- LRU Page Replacement Simulation ---\n");

  
    printf("Enter the number of frames (e.g., 3): ");
    if (scanf("%d", &frame_size) != 1 || frame_size <= 0 || frame_size > 10) {
        printf("Invalid frame size. Exiting.\n");
        return 1;
    }

    
    printf("Enter the number of pages in the reference string: ");
    if (scanf("%d", &page_count) != 1 || page_count <= 0 || page_count > 100) {
        printf("Invalid page count. Exiting.\n");
        return 1;
    }

    
    printf("Enter the page reference string (%d numbers separated by spaces):\n", page_count);
    for (int i = 0; i < page_count; i++) {
        scanf("%d", &page_reference[i]);
    }

    
    for (int i = 0; i < frame_size; i++) {
        frames[i] = -1;
    }

    printf("\nReference String\tFrames\n");
    printf("----------------------------------------\n");

    
    for (int i = 0; i < page_count; i++) {
        int incoming_page = page_reference[i];
        int fault = 0;

        printf("  Page %d:\t\t", incoming_page);

        if (!isPagePresent(incoming_page, frames, frame_size)) {
            
            page_faults++;
            fault = 1;

            
            int empty_frame_index = -1;
            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) {
                    empty_frame_index = j;
                    break;
                }
            }

            if (empty_frame_index != -1) {
                
                frames[empty_frame_index] = incoming_page;
            } else {
                
                int lru_index = findLRU(frames, frame_size, page_reference, i);
                frames[lru_index] = incoming_page;
            }
        }

        
        printFrames(frames, frame_size, fault);
    }

    printf("\n----------------------------------------\n");
    printf("Total number of Page Faults: %d\n", page_faults);

    return 0;
}