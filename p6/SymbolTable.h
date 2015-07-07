#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__
#include "global.h"
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class SymbolTable
{
private:
  map<string, int> mymap;
public:
  SymbolTable();
  void scan_and_add(char*);
  int find_addr_in_table(string sym);

};
#endif
