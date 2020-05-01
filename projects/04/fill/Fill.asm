// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// Pseduo code:
// n=8192
// a=0
//
// LOOP:
//      if KBD != 0 then goto BLACK
//      else goto WHITE
//
// BLACK:
//      if a==-1 goto LOOP
//      a=-1
//      addr=SCREEN
//      i=0
//      goto COLOR
//
// WHITE:
//      if a==0 goto LOOP
//      a=0
//      addr=SCREEN
//      i=0
//      goto COLOR
//
// COLOR:
//      if i-n>0 goto LOOP
//      RAM[SCREEN+i]=a
//      i++
//      goto COLOR

    @8192
    D=A

    @n
    M=D

    @a
    M=0

    @SCREEN
    D=A

    @addr
    M=D

(LOOP)
    @KBD
    D=M

    @BLACK
    D;JNE

    @WHITE
    D;JEQ

(BLACK)
    @a
    D=M

    @LOOP
    D;JNE

    @a
    M=-1

    @SCREEN
    D=A

    @addr
    M=D

    @i
    M=0

    @COLOR
    0;JMP

(WHITE)
    @a
    D=M

    @LOOP
    D;JEQ

    @a
    M=0

    @SCREEN
    D=A

    @addr
    M=D

    @i
    M=0

    @COLOR
    0;JMP


(COLOR)
    @i
    D=M

    @n
    D=D-M

    @LOOP
    D;JGT

    @a
    D=M

    @addr
    A=M
    M=D

    @i
    M=M+1

    @addr
    M=M+1

    @COLOR
    0;JMP
