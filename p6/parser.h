#ifndef _PARSER_H
#define _PARSER_H
#include "global.h"

class parser
{
private:
   long number;
   string dest;
   string comp;
   string jump;
   string symbol; 
  // string trim(string s);
public:
   parser();
   void reset_all();
   void parse(string ins);
   void parse_a(string ins);
   void parse_c(string ins);
   void parse_label(string ins);
  //bool is_A(string ins);
  // bool is_C(string ins);
   string get_dest();
   string get_comp();
   string get_jump();
   long get_number();
   string get_symbol();
};

#endif
