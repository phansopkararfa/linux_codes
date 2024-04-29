#include <stdio.h>

#define MAX_MEMORY_SIZE 100

struct Partition {
    int start_address;
    int size;
    int allocated;
};

void first_fit(struct Partition memory[], int num_partitions, int process_size) {
    int i;
    for (i = 0; i < num_partitions; i++) {
        if (memory[i].allocated == 0 && memory[i].size >= process_size) {
            // Allocate memory to the process
            memory[i].allocated = 1;
            printf("Process of size %d allocated to partition starting at address %d\n", process_size, memory[i].start_address);
            break;
        }
    }
    if (i == num_partitions) {
        printf("No suitable partition available for process of size %d\n", process_size);
    }
}

int main() {
    // Initialize memory partitions
    struct Partition memory[] = {
        {0, 10, 0}, // Start address: 0, Size: 10, Allocated: 0
        {10, 20, 0}, // Start address: 10, Size: 20, Allocated: 0
        {30, 15, 0}, // Start address: 30, Size: 15, Allocated: 0
        {45, 25, 0}  // Start address: 45, Size: 25, Allocated: 0
    };
    int num_partitions = sizeof(memory) / sizeof(memory[0]);

    // Allocate processes using First Fit algorithm
    first_fit(memory, num_partitions, 12); // Allocate process of size 12
    first_fit(memory, num_partitions, 20); // Allocate process of size 20
    first_fit(memory, num_partitions, 30); // Allocate process of size 30
    first_fit(memory, num_partitions, 10); // Allocate process of size 10

    return 0;
}