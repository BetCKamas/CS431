#include <iostream>
#include <string>
using namespace std;

struct word{
// Modified Nov 5 22 to change char line[100] = {" "};
// to char line[100] = {' '};

	string word;	// holder for the full word that is referenced
	int start,	// location to reference the starting char
	    end,	// location to reference the ending char
	    total,	// location to reference the total width of the square to be printed that changes
	    mid,	// location to reference when the middle line has been met
	    len;	// location to reference the total width of square that doesn't change
	char line[100] = {' '}; // used to place the chars to be displayed to the user
};

int main(void){
/*
	This function is used to get a user chosen word, place it in a struct that also contains data to
	be used for the function printIt later. The data fields of the struct are set for later use.

	Written by Betsy Kamas
	For CS431 GHP3
	Language: c++
	Compiler: g++
	October 2022

*/
	void printIt(struct word curLine); // prototype

	struct word W1; // creating structure for the data

	cout<<"Enter a word: "; // prompting for user input
	getline(cin, W1.word);  // getting string

	W1.start = 0; // Setting start position for where chars are placed
	W1.end = W1.word.length()-1; // setting end position for where chars are placed
	W1.total = ((W1.word.length() * 2)-1); // getting total length for square will be changed
	W1.mid = (W1.end + 1); // setting the location for where recursion stops
	W1.len = W1.total; // setting length that is unchanged for printing purposes

	printIt(W1); // calling function passing struct

	return 0;
}

void printIt(struct word curLine){
/*
	This function is called recursively to continuously loop through the letters of a word and print them out
	so that it appears as a square with the outside is the last letter moving inwards until reaching the
	starting character of the word.

	Written by Betsy Kamas
	For CS431 GHP3
	Language: c++
	Compiler: g++
	October 2022

*/
	// setting all the characters to the current char of the word that will be placed in the array
	// in the positions that require change for the square to form correctly
	for(int i = curLine.start; i < curLine.total; i++){
		curLine.line[i] = curLine.word[curLine.end];
	}

	// printing out the line to start/continue the squares
	for(int i = 0; i < curLine.len; i++){
		cout<<curLine.line[i];
	}

	cout<<endl; // so squares form with correct letter
	curLine.total--; // changing the last spot that needs changing for the square
	curLine.end--; // changing location of the letter of word to be used
	curLine.start++; // changing start position for char

	// this checks if we are in the middle of the square and word has been fully looped through
	if(curLine.start != curLine.mid){
		printIt(curLine); // calling again passing the current info to be changed

		// printing out the current line of the square
		for(int i = 0; i < curLine.len; i++){
			cout<<curLine.line[i];
		}
			cout<<endl;

	}


}
