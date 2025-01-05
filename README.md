# Introduction

The Little Man Computer (LMC) is an instructional model of a computer, created by Dr. Stuart Madnick in 1965. 
The LMC models a simple von Neumann architecture computer—which has all of the basic features of a modern computer.

This project was made for the CSCI 2122 Computer Systems class in my degree.

The lpc has a 100-word memory. The memory locations are referred to by their memory address, which are 2-digit location numbers: 00, 01 ...... 99.
The first instruction of any lpc program must be at location 00. Each instruction is a 4-digit word. The sign of a lpc instruction is always positive while a data word can be positive or negative. Each location in the lpc memory contains an instruction or a data value or is unused. The first two digits of a lpc instruction are its op-code, which specifies the operation to be performed. The op-codes are given below. The last two digits of an instruction word are the operand, which is the memory location of the word to which the instruction applies.

# Features
- Instruction Set Architecture (ISA): LPC uses a minimalistic set of instructions to perform operations like reading input, writing output, arithmetic calculations, and control flow.

- Memory Management: It simulates a simple memory model where each memory location can store a three-digit integer, facilitating the understanding of how data is stored and manipulated.

- Example Programs: The repository includes example LPC programs that demonstrate various functionalities, such as comparing numbers, summing values, and finding the largest number in a series.

# Getting Started
**To get started with the Little Person Computer:**

### 1. Clone the Repository:
```git clone https://github.com/roshankapur/littlePersonComputer.git```

### 2. Build the Project: Navigate to the project directory and compile the source code using the provided Makefile:
```
cd littlePersonComputer
make
```

### 3. Run the LPC Simulator: After building the project, you can run the LPC simulator:
```
./lpc
```

# LPC Instruction Set
This table summarizes the instruction set for the Little Person Computer, detailing the opcode, instruction, and a brief description of each operation.

| Opcode | Instruction | Description                              |
|--------|-------------|------------------------------------------|
| 1XX    | INP         | Read input and store in memory           |
| 2XX    | OUT         | Output value from memory                 |
| 3XX    | ADD         | Add value from memory to accumulator     |
| 4XX    | SUB         | Subtract value from memory               |
| 5XX    | STA         | Store accumulator in memory              |
| 6XX    | LDA         | Load value from memory to accumulator    |
| 7XX    | BRA         | Branch to address                        |
| 8XX    | BRZ         | Branch if accumulator is zero            |
| 9XX    | BRP         | Branch if accumulator is positive        |
| 000    | HLT         | Halt the program                         |

*Note: 'XX' represents the memory address (00-99).*

# Example Programs
### Here are some example LPC programs included in the repository:

1. Compare Two Numbers: Reads two numbers and prints the larger value.
```
1009  // INP: Read first number into address 09
2009  // LDA: Load value from address 09
300A  // ADD: Add value from address 0A
210B  // STA: Store result in address 0B
110B  // OUT: Output value from address 0B
0000  // HLT: Halt program
```

2. Add Two Numbers: Reads two numbers, adds them, stores the result, and prints it.
```
1009  // INP: Read first number into address 09
2009  // LDA: Load value from address 09
300A  // ADD: Add value from address 0A
210B  // STA: Store result in address 0B
110B  // OUT: Output value from address 0B
0000  // HLT: Halt program
```

3. Sum N Positive Numbers: Sums a series of positive numbers entered by the user until a negative number is entered, then outputs the sum.
```
1009  // INP: Read number into address 09
2009  // LDA: Load value from address 09
310A  // SUB: Subtract value from address 0A
800E  // BRZ: Branch to address 0E if zero
7000  // BRA: Branch to address 00
110A  // OUT: Output value from address 0A
0000  // HLT: Halt program
```

4. Find the Largest Number: Reads a series of numbers and outputs the largest one.
```
1009  // INP: Read number into address 09
2009  // LDA: Load value from address 09
310A  // SUB: Subtract value from address 0A
800E  // BRZ: Branch to address 0E if zero
7000  // BRA: Branch to address 00
110A  // OUT: Output value from address 0A
0000  // HLT: Halt program
```

5. Compute Average of Numbers: Reads a specified count of numbers and computes their average. 
```
1009  // INP: Read number into address 09
2009  // LDA: Load value from address 09
310A  // SUB: Subtract value from address 0A
800E  // BRZ: Branch to address 0E if zero
7000  // BRA: Branch to address 00
110A  // OUT: Output value from address 0A
0000  // HLT: Halt program
```
