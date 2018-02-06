#include <iostream>      											 					
#include <string>        																 

using namespace std;

int main()
{

	string word ="";  													//each word the user types
	string inputString =""; 											//all the words the user types
	string searchWord= ""; 												//keyword to search for and count up
	size_t found=0; 													//use for find function call to get indexes of words in a string
																		//int numWords; //total number of words entered
	int matches=0;  													//total number of matches/occurences

				//PART 1: Save the words entered
	cout << "Please enter words, *end* (with the asterisks) to stop: "; //prompt

		while(word!="*end*")
		{ 																//while loop don't terminate till enter *end*
			cin >> word; 												//save the entered word into word
			inputString+=word+" "; 										//save a copy of the word into the inputString follow by a space
		}
	
	cout <<"\n" ; 														//prints a new line to make it easier to read during execution
				//PART 2: Get the search word
	cout<< "Please enter the search word you want to use: ";			//prompt
	cin >> searchWord; 													//save word entered into searchWord															
	cout<< "The search word entered is: " << searchWord;
				//PART 3: Count the number of occurences
	found = inputString.find(searchWord,found);							//find first occurence
		while (found!=string::npos)
		{																
			string inputCopy = inputString; 							//make copy of inputString to mess with the copy and not the original
			string checkString; 										//substring to create and check
    
				if(found==0)
				{
					checkString = inputCopy.substr(found, searchWord.length()+1);
				}
				else
				{
					checkString = inputCopy.substr(found-1, searchWord.length()+2);
				}
				
				if(checkString[checkString.length()-1]==' '&&(checkString[0]==' ')||found==0)
				{
					matches++;
				}
    found =inputString.find(searchWord, found+1);
		}																//increment number of occurences

cout<<"\nThe total number of times "<< searchWord << " was found = " << matches;

return 0;
}


