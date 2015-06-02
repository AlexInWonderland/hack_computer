// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// for(int i=0;i<R0;i++){
//      R2=R2+R1;
// }

//  R2=0
//  i=1
//  if i-R0 > 0 jmp LOOP
//  else        jmp END
//  LOOP:
//  R2=R2+R1
//  END:
//  JMP END

@R2
M=0    //R2=0
@i
M=1    //i=1
D=M    //D=i=1

(LOOP)
@i
D=M    //D=i
@R0   //M=R0
D=M-D  //R0-i
@END
D;JLT

@R1
D=M    //D=R1
@R2
M=M+D  //R2=R2+R1 
@i
M=M+1   //i++

@LOOP
0;JMP

(END)
@END
0;JMP


