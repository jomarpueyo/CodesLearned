
#include <iostream>      											// for input, output
#include <string>        											// for strings

using namespace std;
string getInputString(string inputString);
string getSearchWord(string searchWord);
int findNumMatches(string inputString, string searchWord, int matches);

int main(){

string inputString =""; 											//all the words the user types
string searchWord= ""; 												//keyword to search for and count up
int matches=0; 														//total number of matches/occurences

																	//PART 1: Save the words entered
cout << "Please enter words, *end* (with the asterisks) to stop: "; //prompt
inputString = getInputString(inputString);
cout <<"\n" ; 														//prints a new line to make it easier to read during execution

																	//PART 2: Get the search word
searchWord = getSearchWord(searchWord);
cout<< "The search word entered is: " << searchWord;

																	//PART 3: Count the number of occurences
matches = findNumMatches(inputString, searchWord, matches);
cout<<"\nThe total number of times "<< searchWord << " was found = " << matches;


return 0;
}

string getInputString(string inputString){
	string word ="";  												//each word the user types
	while(word!="*end*"){ 											//while loop don't terminate till enter *end*
		cin >> word; 												//save the entered word into word
		inputString += word + " "; 									//save a copy of the word into the inputString follow by a space
	}
	return inputString;
}

string getSearchWord(string searchWord){
cout<< "Please enter the search word you want to use: ";			//prompt
cin >> searchWord;
	return searchWord;
																	//save word entered into searchWord
}

int findNumMatches(string inputString, string searchWord, int matches){
	size_t found=0; 												//use for find function call to get indexes of words in a string
	
	found = inputString.find(searchWord,found);						//find first occurence
	while (found !=string::npos){									//basically if the searchWord is found in the inputString
		string inputCopy = inputString; 							//make copy of inputString to mess with the copy and not the original
		string checkString;											//substring to create and check
    
		if(found==0) checkString = inputCopy.substr(found, searchWord.length()+1);
		else checkString = inputCopy.substr(found-1, searchWord.length()+2);
    
		if(checkString[checkString.length()-1] == ' ' && (checkString[0] == ' ') || found==0) matches++; //increment number of occurences
		found =inputString.find(searchWord, found+1);
	}
	return matches;
}