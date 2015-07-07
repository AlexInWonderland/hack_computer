#ifndef _GLOBAL_H
#define _GLOBAL_H
#include <cstdlib>
#include <cstdio>
#include<iostream>
#include<string>
using namespace std;
enum INS_PART{DEST, COMP, JUMP};
enum INS_TYPE{A,C};
bool is_A(string);
bool is_C(string);
bool is_comment(string);
bool is_label(string);
string trim(string s);
void int_to_bin(long n, char*, int size=15);
void swap(char &, char &);
void reverse(string &a);
bool is_variable(string ins);

#endif
