# Nand2Tetris Assembler
Assembler for Hack Computer's Machine Language written in C++


## Features
1. Convert the Assembly code for Software Simulated computer (Hack) into its Binary equivalent.
2. Supports Variables and Labels in the Language
3. Support Removal of Comments.

## Checklist
- [x] Instructions Commands (A_Command, C_Command, L_Command)
- [x] SymbolTable (Variables)
- [x] SymbolTable (Labels)
- [x] Comments (Single Line)
- [ ] Comments (Multi Line)

## Usage
1. Clone the master git repository:
`git clone --recursive https://github.com/iamarshsingh/nand2tetris`

2. Navigate to `./Assembler/src` directory and execute the makefile:
`./make`

3. Produce the binary executables,
`./make assembler`

4. Now you can convert the Asm files into binaries,
`./assembler fileName.asm`

Sample Assembly files along with correct outputs are provides in `./Assembler/tests`
