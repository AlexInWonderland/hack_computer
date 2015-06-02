// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

(INFINITE)
@KBD
D=M
@BLACK
D;JNE

@CLEAR
D;JEQ
@INFINITE
0;JMP

(CLEAR)
@SCREEN
D=A
@addr
M=D  //addr=SCREEN

@i
M=0   //i=0
(LOOP)
@8192
D=A
@i
D=M-D   //i-8192

@END
D;JEQ

@addr
A=M
M=0

@addr
M=M+1  //addr=addr+1

@i
M=M+1

@LOOP
0;JMP

(END)
@INFINITE
0;JMP

(BLACK)
@SCREEN
D=A
@addr
M=D  //addr=SCREEN

@i
M=0    //i=0

(LOOP1)
@8192
D=A
@i
D=M-D   //i-8192

@BACK
D;JGE

@addr
A=M
M=-1

@addr
M=M+1  //addr=addr+16

@i
M=M+1
@LOOP1
0;JMP

(BACK)
@INFINITE
0;JMP