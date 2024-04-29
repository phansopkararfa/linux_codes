#include <stdio.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

void fifo_page_replacement(int pages[], int num_pages) {
    int frames[NUM_FRAMES] = {-1, -1, -1}; // Initialize frames to -1 (indicating empty)
    int frame_index = 0;

    printf("Page Faults: ");

    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int page_found = 0;

        // Check if page already in frame
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            printf("%d ", page);

            // Replace the oldest page with the current page
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % NUM_FRAMES;
        }
    }

    printf("\n");
}

int main() {
    int pages[NUM_PAGES] = {0, 1, 2, 3, 4, 1, 5, 6, 1, 3}; // Reference string
    fifo_page_replacement(pages, NUM_PAGES);
    return 0;
}