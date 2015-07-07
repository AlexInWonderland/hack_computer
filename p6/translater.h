#ifndef _TRANSLATER_H
#define _TRANSLATER_H
#include"global.h"
#include"coder.h"
#include"parser.h"
#include "SymbolTable.h"

class translater
{
private:
   string result;
   parser p;
   coder c;
   SymbolTable st;
public:
   translater();
   void translate(char*);

};
#endif
