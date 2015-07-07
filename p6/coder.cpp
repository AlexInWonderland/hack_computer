#include "coder.h"

coder::coder()
{
   jmpmap.insert(pair<string, string>("","000"));
   //jmpmap[""]="000";
   jmpmap.insert(pair<string, string>("JGT","001"));
   jmpmap.insert(pair<string, string>("JEQ","010"));
   jmpmap.insert(pair<string, string>("JGE","011"));
   jmpmap.insert(pair<string, string>("JLT","100"));
   jmpmap.insert(pair<string, string>("JNE","101"));
   jmpmap.insert(pair<string, string>("JLE","110"));
   jmpmap.insert(pair<string, string>("JMP","111"));
   
   destmap[""]="000";
   destmap["M"]="001";
   destmap["D"]="010";
   destmap["MD"]="011";
   destmap["A"]="100";
   destmap["AM"]="101";
   destmap["AD"]="110";
   destmap["AMD"]="111";
   
   compmap["0"]="0101010";
   compmap["1"]="0111111";
   compmap["-1"]="0111010";
   compmap["D"]="0001100";
   compmap["A"]="0110000";
   compmap["!D"]="0001010";
   compmap["!A"]="0110001";
   compmap["-D"]="0001111";
   compmap["-A"]="0110011";
   compmap["D+1"]="0011111";
   compmap["A+1"]="0110111";
   compmap["D-1"]="0001110";
   compmap["A-1"]="0110010";
   compmap["D+A"]="0000010";
   compmap["D-A"]="0010011";
   compmap["A-D"]="0000111";
   compmap["D&A"]="0000000";
   compmap["D|A"]="0010101";

   compmap["M"]="1110000";
   compmap["!M"]="1110001";
   compmap["-M"]="1110011";
   compmap["M+1"]="1110111";
   compmap["M-1"]="1110010";
   compmap["D+M"]="1000010";
   compmap["D-M"]="1010011";
   compmap["M-D"]="1000111";
   compmap["D&M"]="1000000";
   compmap["D|M"]="1010101";
}

string coder::find_mapping(string s, INS_PART t)
{
   switch(t)
   {
     //map<string, string>::iterator i; 
     case DEST:
     //    i=destmap.find(s);
     //    if(i!=destmap.end())
             return destmap.find(s)->second;
     case COMP:
         return compmap.find(s)->second;
     case JUMP:
         return jmpmap.find(s)->second;
   }
}
