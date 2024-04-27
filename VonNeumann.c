#include <stdio.h>

int cycle =0;
struct Memory{
    int rows[2048];
};
struct Registers{
    int GPR[31];
    int zero;
    int pc;
} registers; // Declare registers as a global variable
struct decodedInstruction{
    int opcode;          // Opcode specifying the operation to be performed - [31:28]
    int r1;              // Index of the first source/destination register - [27:23]
    int r2;              // Index of the second source register - [22:18]
    int r3;              // Index of the third source/destination register (for some instructions) - [17:12]
    int shamt;           // Shift amount (for shift instructions) - [12:0]
    int immediate;       // Immediate value (for immediate arithmetic/logic operations) - [15:0]
    int address;         // Memory address (for load/store instructions) - [27:0]
};
int fetch(){
    //acess pc, get instruction, increment pc
}
struct decodedInstruction decode(int instruction){
    //read Instruction from fetch, decode it, return operation number and operand indices
}
void execute(struct decodedInstruction instruction){
    // Add
    if (instruction.opcode == 0) {
        int result = registers.GPR[instruction.r2] + registers.GPR[instruction.r3];
        writeBack(instruction.r1, result);
    }

    // Subtract
    if (instruction.opcode == 1) {
        int result = registers.GPR[instruction.r2] - registers.GPR[instruction.r3];
        writeBack(instruction.r1, result);
    }

    // Multiply
    if (instruction.opcode == 2) {
        int result = registers.GPR[instruction.r2] * registers.GPR[instruction.r3];
        writeBack(instruction.r1, result);
    }

    // Move Immediate
    if (instruction.opcode == 3) {
        int result = instruction.immediate;
        writeBack(instruction.r1, result);
    }

    // Jump If Equal
    if (instruction.opcode == 4) {
        if (registers.GPR[instruction.r1] == registers.GPR[instruction.r2]) {
            registers.pc = instruction.address;
        }
    }

    // And
    if (instruction.opcode == 5) {
        int result = registers.GPR[instruction.r2] & registers.GPR[instruction.r3];
        writeBack(instruction.r1, result);
    }

    // Exclusive Or Immediate
    if (instruction.opcode == 6) {
        int result = registers.GPR[instruction.r2] ^ instruction.immediate;
        writeBack(instruction.r1, result);
    }

    // Jump
    if (instruction.opcode == 7) {
        registers.pc = instruction.address;
    }

    // Logical Shift Left
    if (instruction.opcode == 8) {
        int result = registers.GPR[instruction.r2] << instruction.shamt;
        writeBack(instruction.r1, result);
    }

    // Logical Shift Right
    if (instruction.opcode == 9) {
        int result = registers.GPR[instruction.r2] >> instruction.shamt;
        writeBack(instruction.r1, result);
    }

    // Move to Register
    if (instruction.opcode == 10) {
        int result = registers.GPR[instruction.r2];
        writeBack(instruction.r1, result);
    }

    // Move to Memory
    if (instruction.opcode == 11) {
        int result = registers.GPR[instruction.r1];
        memoryStore(instruction.address, result);
    }
}
int memoryLoad(int rowIndex){
    //returns value in this address
}
void memoryStore(int rowIndex, int operand){
    //stores operand in rowIndex
}
void writeBack(int GPRIndex, int operand){
    //write result(operand) back to GPR defined by the GPRIndex
}
