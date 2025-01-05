# Introduction

The Little Man Computer (LMC) is an instructional model of a computer, created by Dr. Stuart Madnick in 1965. 
The LMC models a simple von Neumann architecture computer—which has all of the basic features of a modern computer.

This project was made for the CSCI 2122 Computer Systems class in my degree.

The lpc has a 100-word memory. The memory locations are referred to by their memory address, which are 2-digit location numbers: 00, 01 ...... 99.
The first instruction of any lpc program must be at location 00. Each instruction is a 4-digit word. The sign of a lpc instruction is always positive while a data word can be positive or negative. Each location in the lpc memory contains an instruction or a data value or is unused. The first two digits of a lpc instruction are its op-code, which specifies the operation to be performed. The op-codes are given below. The last two digits of an instruction word are the operand, which is the memory location of the word to which the instruction applies.

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