//#include"parser.h"
//#include "coder.h"
#include "translater.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  translater t;
  t.translate(argv[1]); 
  //cout<<trim("  //test  ");
  return 0;
}
