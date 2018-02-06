/*
Jomar Pueyo UXT302
Tree Program
*/

#include <iostream>
using namespace std;

int main ()
{
//Center is Seven, Initial output is 1 character	
int center = 7;
int out=1;
int space;
int line;

//next line
	for(line=1; line<=7; line++)
		{
//space output
			for(space=1; space<=center; space++)
				{
					cout<<" ";
				}
				center--;
		
//character output
			for(space=1; space<=out; space++)
				{
//if the line is odd output *, if the row is even ^
					if(line%2==0)
						cout<<"*";
					else
						cout<<"^";	
				}
//two more characters per line
			out=out+2;
			cout<<endl;
		}
return 0;
}


/*
output:
       ^
      ***
     ^^^^^
    *******
   ^^^^^^^^^
  ***********
 ^^^^^^^^^^^^^
 /*