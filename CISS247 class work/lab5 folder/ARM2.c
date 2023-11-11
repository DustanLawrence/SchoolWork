/*
 * ARM.c
 * CSCI 247, Lab4, Fall, 2022
 * 10/28/2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define values for memomyArray
#define INSTRUCTION_LINES 50
#define ROWS 6
#define COLUMNS 5
#define STACK_SIZE 100
#define STACK_BASE 8000 // High memory area for the stack base
#define STACK_TOP (STACK_BASE + STACK_SIZE * sizeof(int))

// global variables for my arrays and program counter.
int registerArray[32];
char memoryArray[INSTRUCTION_LINES][ROWS][COLUMNS];
int pc = 200;
int stack[STACK_SIZE]; // Stack array
int SP = STACK_TOP; // Stack Pointer initialized to the top of the stack

void push(int value) {
    if (SP - 8 < STACK_BASE) {
        printf("Ran out of Stack Space/Stack Overflow\n");
        exit(EXIT_FAILURE); // Halt the program
    }
    SP -= 8; // Decrement stack pointer by 8 to grow down
    int stackIndex = (SP - STACK_BASE) / sizeof(int);
    stack[stackIndex] = value; // Store the value at the new stack pointer location
}

int pop() {
    if (SP >= STACK_TOP) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE); // Halt the program
    }
    int stackIndex = (SP - STACK_BASE) / sizeof(int);
    int value = stack[stackIndex]; // Retrieve the value at the current stack pointer location
    SP += 8; // Increment stack pointer by 8 to shrink down
    return value;
}
// function Ins2Mem()
// parse values in a text file and store them in the memory array.
// paramter:
//  file: the file in this case should be "code.txt"
//  counter: counting lines in code.txt. 

void ins2Mem(char *file, int *counter);
void ins2Mem(char *file, int *counter){
    char d[] = " ,"; //delimiter character for strtok function.
    char line[128]; //a temp array 
    registerArray[31]= 0 ;
    while (fgets(line, 128, stdin)){ //fgets to read text file line-by-line

        char *memoryAddress = strtok(line, d); //the first value is stored in var token1
        int memoryAddressInt = atoi(memoryAddress);
        //printf("%d\n", memoryAddressInt);
        if(memoryAddressInt >= 200){
        int index = (memoryAddressInt - 200)/4;
        strcpy(memoryArray[index][0], memoryAddress); //copy string to memory array
        //printf("%s ", token1);

        char *command = strtok(NULL, d); //the second value is stored in var token2
        strcpy(memoryArray[index][1], command); //copy string to memory array
        //printf("%s ", token2);

        char *dest = strtok(NULL, d); //the third value is stored in var token3
        strcpy(memoryArray[index][2], dest); //copy string to memory array
        //printf("%s ", token3);

        char *src1 = strtok(NULL, d); //the fourth value is stored in var token4
        strcpy(memoryArray[index][3], src1); //copy string to memory array
        //printf("%s ", token4);

        char *src2 = strtok(NULL, d); //the fith value is stored in var token5
        strcpy(memoryArray[index][4], src2); //copy string to memory array
        //printf("%s \n", token5);
        //printf("%d\t", i);
        *counter = index + 1;
        }
    }
}

// function trimmer3rd
// trimming out unnecessary character and turn value into int
// parameter:
//     value: a char that needs its value trimmed

int trimmer3rd(char *value);
int trimmer3rd(char *value){
    char tempChar[5]; //temp array to store value for sscanf 
    char *ptr; //temp char pointer 
    sscanf(value,"X%[^,]",tempChar); // to format out the X and ,
    //printf("%s\t", tempChar);
    return strtol(tempChar, &ptr, 10); // return value as an int
}

// function trimmer4th
// trimming out unnecessary character and turn value into int
// parameter:
//     value: a char that needs its value trimmed

int trimmer4th(char *value);
int trimmer4th(char *value){
    char tempChar[5]; //temp array to store value for sscanf 
    char *ptr; //temp char pointer 
    sscanf(value,"%*[[X]%[^,]",tempChar); // to format out the anything that is not an int
    return strtol(tempChar, &ptr, 10); // return value as an int
}

// function trimmer5th
// trimming out unnecessary character and turn value into int
// parameter:
//     value: a char that needs its value trimmed

int trimmer5th(char *value);
int trimmer5th(char *value){ 
    char tempChar[5]; //temp array to store value for sscanf 
    char *ptr; //temp char pointer 
    sscanf(value,"#%[^]]",tempChar); // to format out the anything that is not an int
    return strtol(tempChar, &ptr, 10); // return value as an int
}

// function ADD
// adding 2 values in register arrays
// parameter:
//     char *dest: the destination  
//     char *src1: rm
//     char *src2: rn


void ADD(char *dest, char *src1, char *src2);
void ADD(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest); //passing dest into trimmer function and store in an int temp
    int src1Int = (strcmp(src1, "XZR") == 0) ? 31 : trimmer3rd(src1);
    int src2Int = (strcmp(src2, "XZR") == 0) ? 31 : trimmer3rd(src2);
    registerArray[destInt] = registerArray[src1Int] + registerArray[src2Int];
    //store each variable into its respective place in registerArray
}

// function ADDI
// adding a value in the register with a immediate. 
// parameter:
//     char *dest: the destination  
//     char *src1: rm
//     char *src2: rn

void ADDI(char *dest, char *src1, char *src2);
void ADDI(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest); //passing dest into trimmer function and store in an int temp
    int src1Int = (strcmp(src1, "XZR") == 0) ? 0 : trimmer3rd(src1);
    int src2Int = trimmer5th(src2);
    
    if (strcmp(dest, "SP") == 0 && strcmp(src1, "SP") == 0) {
        // Special case: both destination and source are SP
        SP += src2Int;
    } else {
        // Normal ADDI operation
        registerArray[destInt] = registerArray[src1Int] + src2Int;
    }
}


// function SUB
// subtracting 2 values in the register.
// parameter:
//     char *dest: the destination  
//     char *src1: rm
//     char *src2: rn

void SUB(char *dest, char *src1, char *src2);
void SUB(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest); //passing dest into trimmer function and store in an int temp
    int src1Int = (strcmp(src1, "XZR") == 0) ? 0 : trimmer3rd(src1);
    int src2Int = (strcmp(src2, "XZR") == 0) ? 0 : trimmer3rd(src2);
    registerArray[destInt] = registerArray[src1Int] - registerArray[src2Int];
    //store each variable into its respective place in registerArray
}
void SUBI(char *dest, char *src1, char *src2);
void SUBI(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest); //passing dest into trimmer function and store in an int temp
    int src1Int = (strcmp(src1, "XZR") == 0) ? 31 : trimmer3rd(src1);
    int src2Int = trimmer5th(src2); //passing src2 into trimmer function and store in an int temp
 
    if (strcmp(dest, "SP") == 0 && strcmp(src1, "SP") == 0) {
       
       SP -= src2Int;
    } else {
        // Normal SUBI operation
        registerArray[destInt] = registerArray[src1Int] - src2Int;
   }
    
    //store each variable into its respective place in registerArray
}
// function LDUR
// loading the values store in memory to register
// parameter:
//     char *dest: the destination  
//     char *src1: rm
//     char *src2: rn

void LDUR(char *dest, char *src1, char *src2);
void LDUR(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest);
    int src1Int = trimmer4th(src1);
    int src2Int = trimmer5th(src2);
    int effectiveAddress = registerArray[src1Int] + src2Int;

    // Check if the address is within the stack range
    if (effectiveAddress >= STACK_BASE && effectiveAddress < STACK_TOP) {
        int stackIndex = (effectiveAddress - STACK_BASE) / sizeof(int);
        registerArray[destInt] = stack[stackIndex];
    } else {
        registerArray[destInt] = registerArray[src1Int] + src2Int;
    }
}

// Modify STUR to handle stack operations
void STUR(char *dest, char *src1, char *src2){
    int destInt = trimmer3rd(dest);
    int src1Int = trimmer4th(src1);
    int src2Int = trimmer5th(src2);
     int effectiveAddress = registerArray[src1Int] + src2Int; // Compute the effective address
	
    // Perform the store operation using the effective address
    if (effectiveAddress >= STACK_BASE && effectiveAddress < STACK_TOP) {
        int stackIndex = (effectiveAddress - STACK_BASE) / sizeof(int);
        stack[stackIndex] = registerArray[destInt];
    } else {
        registerArray[effectiveAddress] = registerArray[destInt];
    }
}
// function B
// Branch to a specified location
// parameter:
//     char *dest: the destination  

void B(char *dest);
void B(char *dest){
    if (dest[0] == 'X') { // Register addressing
        int regIndex = trimmer3rd(dest);
        pc = registerArray[regIndex];
    } else { // Immediate addressing
        pc = atoi(dest);
    }  
}

// function CBZ
// Branch to a specified location on condition == 0
// parameter:
//     char *dest: the destination 
//     char *src1: the condition

void CBZ(char *dest, char *src1);
void CBZ(char *dest, char *src1){
     int src1Int = trimmer3rd(src1);
    if(registerArray[src1Int] == 0){
        if (dest[0] == 'X') { // Register addressing
            int regIndex = trimmer3rd(dest);
            pc = registerArray[regIndex];
        } else { // Immediate addressing
            pc = atoi(dest);
        }
    }       
}
// Modify BL to handle the link register and stack
void BL(char *dest){
    push(registerArray[30]); // Save return address in LR (X30) on the stack
    if (dest[0] == 'X') { // Register addressing
        int regIndex = trimmer3rd(dest);
        pc = registerArray[regIndex];
    } else { // Immediate addressing
        pc = atoi(dest);
    }
}

// Modify BR to handle the link register and stack
void BR(char *src1){
    int src1Int = trimmer3rd(src1);
    if (src1Int == 30) { // Check if it's a return from subroutine
        pc = pop(); // Retrieve LR from the stack
        SP += sizeof(int); // Increment stack pointer after retrieving LR
    } else {
        pc = registerArray[src1Int];
    }
}

// Function to print the stack and the stack pointer
void printStack() {
    printf("Stack:\n");
    for (int i = STACK_TOP; i >= STACK_BASE; i -= 8) {
        int stackIndex = (i - STACK_BASE) / sizeof(int);
        if (i >= SP) { // Only print stack entries above the stack pointer
            printf("       %d: %d", i, stack[stackIndex]);
            if (i == SP) {
                printf(" ***\n\n"); // Mark the stack pointer position
            } else {
                printf("\n");
            }
        }
    }
}



// function main()
// expect command-line argument: "code.txt"
int main(int argc, char* argv[]){

    int counter = 0; // line counter 
    int i = 0; // int for first for loop
    

    // check for the correct number of command-line arguments
    if (argc != 1) {
        printf("Usage: ./ARM < code.txt\n");
        return 0;
    }
    //passing code.txt to be parsed and stored
    ins2Mem(argv[1], &counter);

    //Program runs till the according to how many lines of text in code.txt
    while (pc < ((4 * counter) + 200)){

       for (i = 0; i < counter; i++ ){
            if (strcmp(memoryArray[i][1], "ADDI") == 0){ //compare two strings
                ADDI(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]); //execute if strings matched.
                pc += 4; // program counter +4
            }
            else if (strcmp(memoryArray[i][1], "ADD") == 0){ //compare two strings
                ADD(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]); //execute if strings matched.
                pc += 4; // program counter +4
            }
            else if (strcmp(memoryArray[i][1], "LDUR") == 0){
       		LDUR(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]);
        	pc += 4;
            }
            else if (strcmp(memoryArray[i][1], "STUR") == 0){
                STUR(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]);
                pc += 4;
            } 
            else if (strcmp(memoryArray[i][1], "SUB") == 0){
                SUB(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]);
                pc += 4;
            }
            else if (strcmp(memoryArray[i][1], "SUBI") == 0){
                SUBI(memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]);
                pc += 4;
            }
            else if (strcmp(memoryArray[i][1], "B") == 0){
                B(memoryArray[i][2]);
                pc += 4;
            }
            else if (strcmp(memoryArray[i][1], "CBZ") == 0){
                CBZ(memoryArray[i][2],memoryArray[i][3]);
                pc += 4;
            }
             else if (strcmp(memoryArray[i][1], "BL") == 0){
                BL(memoryArray[i][2]);
                pc += 4;
            }
            else if (strcmp(memoryArray[i][1], "BR") == 0){
                BR(memoryArray[i][2]);
                if (strcmp(memoryArray[i][2], "XZR") == 0) {
                printf("Halting program.\n");
                break; // Exit the loop, effectively halting the program
            }
                pc += 4;
            }
           
        
            // Print the instruction executed
        printf("Instruction executed: %s %s, %s, %s",memoryArray[i][1], memoryArray[i][2], memoryArray[i][3], memoryArray[i][4]);

        // Print the relevant registers
        printf("Registers: X0 = %d, SP=%d, PC=%d*\n", registerArray[0], SP, pc);

        // Print the stack
        
        printStack();
             
             // print out values stored in the registers that is not 0
		for (int j = 0; j < 32; j++){
		if (registerArray[j] != 0){
		printf("\tRegisters: X%d = %d\n", j, registerArray[j]);
		}
	      }
            }
           
        }
    return 0;
    }  

