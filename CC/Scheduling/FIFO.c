#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

int main() {
    int frames, pages, pageFaults = 0;
    int pageQueue[MAX_PAGES], pageTable[MAX_PAGES];

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    printf("Enter the page references:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageTable[i]);
    }

    for (int i = 0; i < frames; i++) {
        pageQueue[i] = -1;  // Initialize page queue with -1 indicating an empty slot
    }

    int front = 0;  // Points to the front of the queue

    for (int i = 0; i < pages; i++) {
        int currentPage = pageTable[i];
        int pageFound = 0;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (pageQueue[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        // Page fault
        if (!pageFound) {
            printf("Page %d caused a page fault.\n", currentPage);
            pageQueue[front] = currentPage;  // Replace the oldest page in the queue
            front = (front + 1) % frames;    // Move the front pointer to the next position
            pageFaults++;
        }

        // Display the current state of the page queue
        printf("Current page queue: ");
        for (int j = 0; j < frames; j++) {
            printf("%d ", pageQueue[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
