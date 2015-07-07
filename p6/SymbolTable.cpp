#include "SymbolTable.h"
//#include <fstream>

SymbolTable::SymbolTable()
{
   //load predefined symbols
   mymap["SP"]=0;
   mymap["LCL"]=1;
   mymap["ARG"]=2;
   mymap["THIS"]=3;
   mymap["THAT"]=4;
   mymap["R0"]=0;
   mymap["R1"]=1;
   mymap["R2"]=2;
   mymap["R3"]=3;
   mymap["R4"]=4;
   mymap["R5"]=5;
   mymap["R6"]=6;
   mymap["R7"]=7;
   mymap["R8"]=8;
   mymap["R9"]=9;
   mymap["R10"]=10;
   mymap["R11"]=11;
   mymap["R12"]=12;
   mymap["R13"]=13;
   mymap["R14"]=14;
   mymap["R15"]=15;
   mymap["SCREEN"]=16384;
   mymap["KBD"]=24576;
  // for(map<string, int>::iterator it=mymap.begin();it!=mymap.end();it++)
  //       cout<<it->first<<"  "<<it->second<<endl;
}

int SymbolTable::find_addr_in_table(string sym)
{
      map<string, int>::iterator f=mymap.find(sym);
      if(f!=mymap.end())
	return mymap.find(sym)->second;
     // for(map<string, int>::iterator it=mymap.begin();it!=mymap.end();it++)
     //    cout<<it->first<<"  "<<it->second<<endl;
      return -1;
} 

void SymbolTable::scan_and_add(char *filename)
{
     ifstream myfile(filename);
     if(myfile.is_open())
     {
        string ins;
        int line_number=0;
        while(getline(myfile, ins))
        {
           ins=trim(ins);
           if(ins.front()=='(' && ins.back()==')')
           {
	      string label=ins.substr(1,ins.length()-2);
              //cout<<"ins:"<<ins<<" line: "<<line_number<<endl;
              mymap[label]=line_number;
           }
        /*   else if(is_A(ins))
           {
             if(is_variable(ins))
             {
                string symbol=ins.substr(1);
                //for(map<string, int>::iterator it=mymap.begin();it!=mymap.end();it++)
                //    cout<<it->first<<"  "<<it->second<<endl;
                map<string, int>::iterator i=mymap.find(symbol);
                if(i==mymap.end()) //to see if the symbol is in the table
                   mymap[symbol]=sym_address++; 
             }
           }*/
                 
           if(ins!="" && !is_comment(ins) && !is_label(ins))
           {
               line_number++;
               //cout<<"ins: "<<ins<<" line: "<<line_number<<endl;
           }
        }
       // cout<<myfile.tellg();
        myfile.clear();     //important
        myfile.seekg(0,myfile.beg);
	int sym_address=16;
        //cout<<myfile.tellg()<<endl;
        while(getline(myfile, ins))
        {
           ins=trim(ins);
          // cout<<ins<<endl;
           if(is_A(ins))
           {
             if(is_variable(ins))
             {
                string symbol=ins.substr(1);
                map<string, int>::iterator i=mymap.find(symbol);
                if(i==mymap.end()) //to see if the symbol is in the table
                   mymap[symbol]=sym_address++; 
             }
           }
        }       
        //for(map<string, int>::iterator it=mymap.begin();it!=mymap.end();it++)
        //          cout<<it->first<<"  "<<it->second<<endl;
        myfile.close();
     }
     else
     {
        cout<<"file open failed!"<<endl;
     }
}
