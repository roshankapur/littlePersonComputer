#include <stdio.h>
#include <stdlib.h>
#include "lpc.h"

void loadProgram(int memory[]) {
    int instruction;
    int location = 0;
    
    while (1) {
        instruction = getValidatedInput();
        if (instruction == SENTINEL) {
            break;
        }
        
        if (location >= SIZE) {
            printf("***FATAL ERROR - Memory overflow***\n");
            exit(0);
        }
        
        memory[location++] = instruction;
    }
}
int getValidatedInput(void) {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number between %d and %d: ", MIN_VALUE, MAX_VALUE);
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        
        if (input == SENTINEL) {
            return SENTINEL;
        }
        
        if (input >= MIN_VALUE && input <= MAX_VALUE) {
            return input;
        }
        
        printf("Number out of range. Please enter a number between %d and %d: ", MIN_VALUE, MAX_VALUE);
    }
}