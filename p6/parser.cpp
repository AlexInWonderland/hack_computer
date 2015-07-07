#include "parser.h"

parser::parser()
{
   number=-1;
   jump="";
   dest="";
   comp="";
   symbol="";
}

void parser::reset_all()
{
    number=-1;
    jump="";
    dest="";
    comp="";
    symbol="";
}

/*string parser::trim(string s)
{
   string trim_result="";
   for(string::iterator it=s.begin();it!=s.end();it++)
   {
      if(*it!=' '||*it!='\t')
         trim_result.append(it,it+1);
   }
   return trim_result;
}*/

void parser::parse_a(string ins)
{
     reset_all();
     string tmp=ins.substr(1);   //get rid of '@'
     size_t found = tmp.find_first_not_of("0123456789"); 
     if(found==string::npos)  //number
 	this->number = stol(tmp);      
     else  //symbols         
 	symbol=tmp;
}


void parser::parse_c(string ins)
{
      reset_all();
      size_t x=ins.find_first_of("=;");
      if(ins[x]=='=')   //if there is =(equal) part
      {
        size_t len=x-0;
	dest=ins.substr(0, len);   //in case of dest = comp ; jump
	size_t first_semi_colon=ins.find_first_of(";");
	if(first_semi_colon!=string::npos)   //we found semi colon so there is jump
	{
	   len = first_semi_colon - x -1;
	   comp=ins.substr(x+1,len);
           jump=ins.substr(first_semi_colon+1);
        }
        else    //no jump part
        {
           comp=ins.substr(x+1);
        }	   
      }
      if(ins[x]==';')  //if no equal part
      {
        size_t len=x-0;
	comp=ins.substr(0,len);
	jump=ins.substr(x+1);
      }	
}

void parser::parse_label(string ins)
{
     reset_all();
}

void parser::parse(string ins)
{
  ins=trim(ins); //remove spaces
  if(is_A(ins))
  { 
     string tmp=ins.substr(1);   //get rid of '@'
     size_t found = tmp.find_first_not_of("0123456789"); 
     if(found==string::npos)  //number
 	this->number = stol(tmp);      
     else  //symbols         
 	symbol=tmp;
  }
  else if (is_C(ins))
  {
      size_t x=ins.find_first_of("=;");
      if(ins[x]=='=')   //if there is =(equal) part
      {
        size_t len=x-0;
	dest=ins.substr(0, len);   //in case of dest = comp ; jump
	size_t first_semi_colon=ins.find_first_of(";");
	if(first_semi_colon!=string::npos)   //we found semi colon so there is jump
	{
	   len = first_semi_colon - x -1;
	   comp=ins.substr(x+1,len);
           jump=ins.substr(first_semi_colon+1);
        }
        else    //no jump part
        {
           comp=ins.substr(x+1);
        }	   
      }
      if(ins[x]==';')  //if no equal part
      {
        size_t len=x-0;
	comp=ins.substr(0,len);
	jump=ins.substr(x+1);
      }	
  }
  else   //label
  {
   
  }
}

string parser::get_dest()
{
	return dest;
}

string parser::get_comp()
{
	return comp;
}

string parser::get_jump()
{
	return jump;
}

long parser::get_number()
{
	return number;
}

string parser::get_symbol()
{
	return symbol;
}
/*bool parser::is_symbol(string ins)
{
     //size_t found = ins.find_first_not_of('@');
     string tmp=ins.substr(1);     //get rid of '@'
     size_t found = ins.find_first_not_of("0123456789");
     if(found!=) 
}*/

/*bool parser::is_A(string ins)
{
    //size_t found = ins.find_first_not_of(' ');   //get rid of spaces
    if (ins[0]=='@'){
    	return true;
    }
    return false;
}

bool parser::is_C(string ins)
{
   // size_t found = ins.find_first_not_of(' ');
    if(ins[0]=='@')
	return false;
    if(ins[0]=='(')
	return false;
    return true;
}*/

