#include"global.h"

bool is_A(string ins)
{
    if (ins[0]=='@'){
    	return true;
    }
    return false;
}

void swap(char &a, char &b)
{
    char tmp=a;
    a=b;
    b=tmp;
}

void reverse(string &a)
{
   int i=0, j=a.length()-1;  
   for(;i<j;i++,j--)
   {
       swap(a[i], a[j]);
   }
}

void int_to_bin(long n, char *result, int size)
{
    for(int itr=0;itr<size;itr++)
    {
        //result[i]=0;
        sprintf(&result[itr],"%d", 0);
    }
    long tmp=n;
    int i=0;
    while(tmp!=0)
    {
       sprintf(&result[i], "%d", (int)(tmp%2));
       tmp/=2;
       i++;
    }
}

bool is_C(string ins)
{
    if(ins[0]=='@')
	return false;
    if(ins[0]=='(')
	return false;
    if(ins.substr(0,2)=="//")   //comments
        return false;
    if(ins[0]=='\n' || ins[0]=='\r' || ins[0]=='\0')
        return false; 
    return true;
}

bool is_comment(string s)
{
    if(s.substr(0,2)=="//")
        return true;
    return false;
}

bool is_variable(string s)
{
    string tmp=s.substr(1);   //get rest of @xxx
    size_t found=tmp.find_first_not_of("0123456789");
    if(found==string::npos)
           return false;
    return true;     
   
}

bool is_label(string s)
{
    if(s[0]=='(')
         return true;
    return false;
}

string trim(string s)
{
   string trim_result="";
   for(string::iterator it=s.begin();it!=s.end();it++)
   {
      if(*it!=' ' && *it!='\t' && *it!='\r')
         trim_result.append(it,it+1);           
   }
   if(trim_result.substr(0,2)=="//")
       return "";
   size_t f=trim_result.find_first_of('/');
   if(f!=string::npos)    //some case like @123 //how are you?
   {
     if(trim_result[f+1]=='/')
         return trim_result.substr(0, f-0); 
   }
   return trim_result;
}
