#include<iostream> 	// For I/O
#include<fstream>	// For file
#include<cassert>	// For file
#include<list>		// For list
#include<iterator>	// To traverse list
#include<string>	// For Strings

using namespace std;

int main(void){
/*
	The purpose of this program is to take in a user defined file, read
	in the contents, and keep track of all the words starting with 'D'
	or 'd' in one list, and all other words in another. It then sorts
	the list alphabetically. It then passes these lists by reference to
	a function that removes the duplicate elements, and keeps track of
	how many times it appeared in the list and appends this value to
	the list element. It then passes the list to another function that
	prints out the elements of the list.

	Written by Betsy Kamas
	For GHP4 CS431
	November 2022
	Language: C++
	Compiler: g++ version 10.2.0
*/

	void prntLst(list<string> &k);	// Prototype for function that prints
					// out elements of a list
	void unqLst(list<string> &k);	// Prototype for function that sorts
					// list and counts the number of
					// occurances of words in list

	string fileName;		// Holds name of the file to br read
					// from
	ifstream fileIn;		// The actual file

	cout<<"Enter the name of a text file: ";
	cin>>fileName;

	fileIn.open(fileName.data());	// Opening file
	assert(fileIn.is_open());	// Asserting to program file is open

	list<string> dWrd, othWrd;	// Lists to hold words
	string x;			// string for the current word being
					// read in

	while(fileIn>>x){		// Loop to start pulling words in
					// from file
		if(x[0] == 'D' || x[0] == 'd'){ // Adding words to list if it
			dWrd.push_back(x);	// strats with 'D' or 'd'

		}
		else{				// Adding all other words to
			othWrd.push_back(x);	// a different list
		}
	}

	dWrd.sort();			// Sorts lists alphabetically
	othWrd.sort();

	unqLst(dWrd);			// Passing lists to function to get
	unqLst(othWrd);			// rid of duplicates

	prntLst(dWrd);			// Prints results to screen
	prntLst(othWrd);

	return 0;
}

void unqLst(list<string> &k){
/*
	The purpose of this function is to take in a list by reference and
	remove duplicate elements. It keeps a count of the total number of
	times a word appeared and then adds this number after the word in
	the list.

	Written by Betsy Kamas
	For GHP4 CS431
	November 2022
	Language: C++
	Compiler: g++ version 10.2.0
*/
	list<string>::iterator cur;	// Iterator to keep track of duplicate
					// occurances of words
	list<string>::iterator frst;	// Iterator to keep track of first
					// occurance of the word
	cur = k.begin();		// Setting to beginning of list
	cur++;				// Moving to next spot to check for
					// duplicate entry
	frst = k.begin();		// Keeps track of first occurance of
					// word
	int x;				// To keep track of how many times
					// the word shows up

	while(frst != k.end()){		// Looping through lists as long as
					// its not at the end
		x = 1;			// Setting to one since the word must
					// be in the list once if it exists in
					// the list
		while(*frst == *cur){	// Loops through all duplicates
			x++;		// Increase count
			k.erase(cur++);	// Get rid of duplicate and moving
					// iterator to next position
		}

		*frst += " ";		// Concatinating a space and the number
		*frst += to_string(x); 	// of times word has shown up to the
					// first time element appeared
		frst++;			// Move to next word
		cur++;			// Move to next word
	}
}

void prntLst(list<string> &k){
/*
	The purpose of this program is to print out all the elements of a list
	that was passed by reference. It prints out 23 elements at a time
	which is the size of the Cygwin window by default upon launch of the
	program.

	Written by Betsy Kamas
	For GHP4 CS431
	November 2022
	Language: C++
	Compiler: g++ version 10.2.0
*/
	list<string>::iterator it;	// Iterator to loop through all
					// positions of the list
	char junk;			// Junk char so print out pauses
	int i = 0;			// Counter for how many elements
					// have been printed
	cout<<"Words found and their frequency:"<<endl;
	for(it = k.begin(); it != k.end(); ++it){
					// Looping through List
		cout<< *it <<endl;	// Printing contents
		i++;			// Increment count
		if(i == 23){		// Checks if screen height
					// has been reached
			cout<<endl<<"Enter a character to continue...";
			cin>>junk;
			i = 0;		// Resetting height
		}
	}
	cout<<endl<<"End of list. Enter a character to continue...";
	cin>>junk;
	cout<<endl;

}
