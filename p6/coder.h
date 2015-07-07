#ifndef _CODER_H
#define _CODER_H
#include<map>
#include "global.h"
/*enum Type{DEST, COMP, JUMP};*/
class coder
{
private:
    map<string, string> jmpmap;
    map<string, string> destmap;
    map<string, string> compmap;
public:
    coder();
    string find_mapping(string, INS_PART);
};

#endif
