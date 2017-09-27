// File: a1.cpp
// Author: Frederick Ho fho2

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

int base4tobase10(std::string str,int k)
{
  int base = 4;
  int sum = 0;
  std::string s;
  int n;
    //  std::cout << str.length();
  for(int i = str.length()-1; i>=0; i--)
    {
      s = str[i];
      n=std::stoi(s);
      sum += (pow(base,k-i-1)*(n));
    }
  return sum;
}

std::string base10tobase4(int z,int k)
{
  int base = 4;
  int quotient = z; // ex:82/4 = quotient = 20
  std::string s = "";
  do
    {
     int temp = quotient%base;
      if(temp== 3)
	{
	  s= 'T' + s;
	}else if(temp == 2)
	{
	  s = 'G' + s;
	}else if(temp == 1)
	{
	s = 'C' + s;
	}else if(temp== 0)
       {
	 s = 'A' + s;
       }
      quotient=quotient/base;
    }while(quotient >= 1);
  if(s.length()<(unsigned)k)
    {
      while(s.length()<(unsigned)k)
	{
	  s='A'+s;
	}
    }
  return s;
}

int main(int argc, char* argv[])
{
 if (argc < 2)
    {
    std::cout << "error: no input file" << std::endl;
    return -1;
    }
      std::string in = argv[1];
      std::ifstream f(in);
      int k;
      int n;
      f >> k;
      f >> n;
      // std::cout << k << " " << n << std::endl;
      std::string s = "";
      std::string s1 = "";
      bool containsN = false;
      int* array = new int[(int)pow(4,k)];
      for(int i = 0; i<(pow(4,k)); ++i)
	{
	  array[i] = 0;
	}
      int z;
      std::string s2 = "";
      
      
      //test number of lines outside of the while loop
      int numlines = 0;

      while(!f.eof())
	{
	  //  f>>s;
	  if(f)
	    {
	      while(getline(f,s))
		{
		  s1 += s;
		  numlines++;
		}
	        numlines--;
		// std::cout << numlines;
	    }
	  //  std::cout << s1[30] << std::endl; // good testing point
	  if((k>=3 && k<=10) && numlines>=n && n>1 && (unsigned)k<=s1.length())
	  	{
	    
		  //  std::cout << numlines << " " << n;
		  for(int i = 0; (unsigned) i<s1.length()-k+1; ++i)
		    {
		      std::string str = s1.substr(i,k);
		      //   fullstring.push_back(str);
		      containsN = false;//need to reset value of containsN every time you make a new substring
		      for(int i = 0;(unsigned) i<str.length(); ++i)
			{
			  if(str[i] == 'N')
			    {
			      containsN = true;//searches through string, if str has 'N' then set containsN to true 
			    }
			}
		      if(!containsN)
			{
			  //    std::cout << str << " ";
			  for(int i = 0;(unsigned) i<str.length();++i)
			    {
			      if(str[i] == 'A')
				{
				  str[i] = '0';
				} else if(str[i] == 'C')
				{
				  str[i] = '1';
				} else if(str[i] == 'G')
				{
				  str[i] = '2';
				} else if(str[i] == 'T')
				{
				  str[i] = '3';
				}
			    }
			  //  std::cout << str;
			  z = base4tobase10(str,k); // 18 92
			  array[z] = array[z] + 1;
			  //  = base10tobase4(z,k);//comment this out
			  // std::cout << base10tobase4(z,k);
			  //  std::cout << z << " ";
			 
			  
			}
				  
		    }
		}else{
	    std::cout << "error" << std::endl;
	  }
		  for(int i = 0; i<(int)pow(4,k); ++i)
		    {
		      
		      if(array[i] !=0)
			{
			  std::cout << base10tobase4(i,k)  << " " << array[i] << std::endl;
			}
		    }
	}
      delete [] array;
	  return 0;
}
