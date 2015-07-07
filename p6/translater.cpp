#include<fstream>
#include "translater.h"


translater::translater()
{
   result="";
}

void translater::translate(char *filename)
{
     string ins;
     st.scan_and_add(filename);
     ifstream myfile(filename); 
     string out_filename="";
     char *tmp=filename;
     while(*tmp!='.')
     {
        out_filename.append(1, *tmp);
        tmp++;
     }
     //cout<<out_filename<<endl;
     out_filename+=".hack";
     ofstream  my_out_file;
     my_out_file.open(out_filename.c_str());   
     if(myfile.is_open() && my_out_file.is_open())
     {  
	   while(getline(myfile,ins))   //read a line from a file
           {
              string bin_result; 
              ins=trim(ins);   //remove all spaces
              if(is_A(ins))
              {
                  p.parse_a(ins);
                  bin_result.append(1,'0');
                  char bin[15];
                  int addr=-1;
                  if(is_variable(ins))
                  {
                     string symbol=ins.substr(1);
                     addr=st.find_addr_in_table(symbol);
                    // cout<<"symbol: "<<symbol<<" addr: "<<addr<<endl; 
                  }   
                  else
                  {
                     addr=p.get_number();
                  }    
                  int_to_bin(addr, bin);
                  string tmp(bin);              
                  int length=tmp.length();
                  if(tmp.length()<15)
                  {
                      for(int i=0;i<(15-length);i++)
                          tmp.append(1,'0');
                  }
                  reverse(tmp);
                  /*for(int i=15;i>=0;i--){   //don't why doesn't work  
                      bin_result.append(1,bin[i]);
                  }*/
                  bin_result.append(tmp);
                  my_out_file << bin_result<<endl;
              }
              else if(is_C(ins))
              {
                  p.parse_c(ins);
                  bin_result.append("111");   //start of c instruction
                  string comp=c.find_mapping(p.get_comp(), COMP);
                  bin_result.append(comp);
                  string dest=c.find_mapping(p.get_dest(), DEST);
                  bin_result.append(dest);
                  string jump=c.find_mapping(p.get_jump(), JUMP);
                  bin_result.append(jump);
                  my_out_file<<bin_result<<endl;
              } 
           }
           myfile.close();
           my_out_file.close();
     }
     else
     {
         cout<<"file opoen error!"<<endl; 
     }
}
