#include <stdio.h>
#include <stdlib.h>
#include "lpc.h"

int main() {
    int memory[SIZE] = {0};  // Initialize memory to 0
    
    loadProgram(memory);     // Load the program
    executeProgram(memory);  // Execute the program
    
    return 0;
}

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

void executeProgram(int memory[]) {
    int accumulator = 0;
    int programCounter = 0;
    int instructionReg = 0;
    int opCode = 0;
    int operand = 0;
    int temp;
    
    printf("***Start LPC Execution***");
    
    while (1) {
        // Fetch instruction
        if (programCounter >= SIZE) {
            fatalError("Program counter out of bounds", memory, accumulator, programCounter, opCode, operand);
        }
        
        instructionReg = memory[programCounter];
        opCode = extractOpCode(instructionReg);
        operand = extractOperand(instructionReg);
        
        // Execute instruction
        switch (opCode) {
            case READ:
                temp = getValidatedInput();
                memory[operand] = temp;
                programCounter++;
                break;
                
            case WRITE:
                printf("\nContents of %d: %d\n", operand, memory[operand]);
                programCounter++;
                break;
                
            case LOAD:
                accumulator = memory[operand];
                programCounter++;
                break;
                
            case STORE:
                memory[operand] = accumulator;
                programCounter++;
                break;
                
            case ADD:
                temp = accumulator + memory[operand];
                if (temp > MAX_VALUE || temp < MIN_VALUE) {
                    fatalError("Arithmetic overflow", memory, accumulator, programCounter, opCode, operand);
                }
                accumulator = temp;
                programCounter++;
                break;
                
            case SUBTRACT:
                temp = accumulator - memory[operand];
                if (temp > MAX_VALUE || temp < MIN_VALUE) {
                    fatalError("Accumulator overflow", memory, accumulator, programCounter, opCode, operand);
                }
                accumulator = temp;
                programCounter++;
                break;
                
            case MULTIPLY:
                temp = accumulator * memory[operand];
                if (temp > MAX_VALUE || temp < MIN_VALUE) {
                    fatalError("Accumulator overflow", memory, accumulator, programCounter, opCode, operand);
                }
                accumulator = temp;
                programCounter++;
                break;
                
            case DIVIDE:
                if (memory[operand] == 0) {
                    fatalError("Attempt to divide by zero", memory, accumulator, programCounter, opCode, operand);
                }
                accumulator = accumulator / memory[operand];
                programCounter++;
                break;
                
            case JUMP:
                programCounter = operand;
                break;
                
            case JUMPNEG:
                programCounter = (accumulator < 0) ? operand : programCounter + 1;
                break;
                
            case JUMPZERO:
                programCounter = (accumulator == 0) ? operand : programCounter + 1;
                break;
                
            case HALT:
                printf("***End LPC Execution***\n");
                return;
                
            default:
                fatalError("Illegal opCode", memory, accumulator, programCounter, opCode, operand);
        }
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

void dumpMemory(int memory[], int accumulator, int programCounter, int opCode, int operand) {
    printf("\nRegisters:\n");
    printf("accumulator     %+05d\n", accumulator);
    printf("program counter %05d\n", programCounter);
    printf("op-code        %05d\n", opCode);
    printf("operand        %05d\n\n", operand);
    
    printf("Memory:\n");
    printf("      0    1    2    3    4    5    6    7    8    9\n");
    
    for (int i = 0; i < SIZE; i += 10) {
        printf("%2d", i/10);
        for (int j = 0; j < 10; j++) {
            printf(" %04d", memory[i + j]);
        }
        printf("\n");
    }
}

void fatalError(const char* message, int memory[], int accumulator, int programCounter, int opCode, int operand) {
    printf("\n***FATAL ERROR - %s***\n", message);
    printf("***lpc execution abnormally terminated ***\n");
    dumpMemory(memory, accumulator, programCounter, opCode, operand);
    exit(0);
}

int extractOpCode(int instruction) {
    return instruction / 100;
}

int extractOperand(int instruction) {
    return instruction % 100;
}