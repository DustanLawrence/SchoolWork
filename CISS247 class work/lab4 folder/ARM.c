#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pc = 200;
int registers[11] = {0};
char memory[] [1024] = {0};

void execute_ADD(int dest, int src1, int src2) {
    registers[dest] = registers[src1] + registers[src2];
    
    printf("Registers:X%i = %i\n", dest, registers[dest]);
}

void execute_ADDI(int dest, int src1, int imm) {
    registers[dest] = registers[src1] + imm;
    printf("Registers:X%i = %i\n", dest, registers[dest]);
}

void execute_LDUR(int dest, int src1, int offset) {
    // Simulated data read from memory
    registers[dest] = memory[registers[src1] + offset];
    printf("Registers:X%i = %i\n", dest, registers[dest]);
}

void execute_STUR(int src1, int src2, int offset) {
    // Simulate the storing of data to memory.
    //memory[registers[src2] + offset] = registers[src1];
     //printf("Registers:X%i = %i\n", dest, registers[dest]);
}

void execute_B(int target) {
    pc = target;
}
void load(int addr, int sOpcode){
	
}

int main() {
    char line[100];
 
   while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \t\n");
        if (token == NULL) {
            continue;  // Skip empty lines.
        }

        char addr[10], opcode[10], dest[10], src1[10], src2[10];
        int sOpcode;

	strcpy(addr, token);
        token = strtok(NULL, " ,X#[]\t\n");
        strcpy(opcode, token);
        token = strtok(NULL, " ,X#[]\t\n");
        strcpy(dest, token);
        token = strtok(NULL, " ,X#[]\t\n");
        strcpy(src1, token);
        token = strtok(NULL, " ,X#[]\t\n");
        strcpy(src2, token);
        
        if (strcmp(opcode, "ADD") == 0) {
            sOpcode = 1;
        } else if (strcmp(opcode, "ADDI") == 0) {
            sOpcode = 2;
        } else if (strcmp(opcode, "LDUR") == 0) {
            sOpcode = 3;
        } else if (strcmp(opcode, "STUR") == 0) {
            sOpcode = 4;
        } else if (strcmp(opcode, "B") == 0) {
            sOpcode = 5;
        }else{sOpcode=512;}

        printf("PC = %d, Instruction: %s X%d, X%d, X%d\n", pc, opcode, atoi(dest), atoi(src1), atoi(src2));

        switch (sOpcode) {
            case 1:
                pc += 4;
                execute_ADD(atoi(dest), atoi(src1), atoi(src2));
                break;
            case 2:
                pc += 4;
                execute_ADDI(atoi(dest), atoi(src1), atoi(src2));
                break;
            case 3:
                pc += 4;
                execute_LDUR(atoi(dest), atoi(src1), atoi(src2));
                break;
            case 4:
                pc += 4;
                execute_STUR(atoi(src1), atoi(dest), atoi(src2));
                break;
            case 5:
                pc += 4;
                execute_B(atoi(dest));
                break;
            default:
                 if (sOpcode != 0) {
                   /* int addr_val, value1, value2, value3, value4;
                    sscanf(line, "[%d %d %d %d %d", &addr_val, &value1, &value2, &value3, &value4);
                    memory[addr_val] = value1;
                    memory[addr_val + 1] = value2;
                    memory[addr_val + 2] = value3;
                    memory[addr_val + 3] = value4;*/
                }
        }
    }

    printf("Final Register Values:\n");
    for (int i = 0; i <= 11; i++) {
        printf("X%d = %d\n", i, registers[i]);
    }

    return 0;
}

