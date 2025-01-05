#ifndef LPC_H
#define LPC_H

// Constants for LPC operations
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define JUMP 40
#define JUMPNEG 41
#define JUMPZERO 42
#define HALT 43

// Additional constants
#define TRUE 1
#define FALSE 0
#define SIZE 100
#define SENTINEL -99999
#define MAX_VALUE 9999
#define MIN_VALUE -9999

// Function declarations
void loadProgram(int memory[]);
int getValidatedInput(void);

#endif