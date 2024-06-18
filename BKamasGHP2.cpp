/*
	The purpose of this program is to show how bad global variables are to use in this
	particular way of sorting.

	Written by Betsy Kamas
	Based on the flow chart for CS431 GHP2
	Language c++
	Compiler g++
	October 2022
*/

#include<iostream>

using namespace std;

int n; // Global variable for total elements in array
int a[16] = {0}; // Global variable for array

int main(void)
{
/*
	This main function takes in input from the user and places it into an array.
	It then calls a function to do the sort. Upon return it prints out the results.

	Written by Betsy Kamas
	Based on the flow chart for CS431 GHP2
	Language c++
	Compiler g++
	October 2022
*/

	void sort(); // Function prototype to sort elements

	cout<<"Enter an integer <= 15 for the total number of integers to sort"<<endl;
	cin >> n; // Getting input for total elements

	cout<<"Enter " << n << " integers"<<endl;

	for(int i = 1; i <= n; i++) // Getting numbers for array
	{
		cin >> a[i];
	}

	sort(); // Calling sort

	cout << "Sorted: "; // Printing results

	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}


	return 0;
}

int j; // Global variable for location in array

void sort(void)
{
/*
	Sort is a function that checks the value of two array locations right next to each other.
	If the number in the current spot is greater than the number in the next location, it calls
	on move to swap the numbers.

	Written by Betsy Kamas
	Based on the flow chart for CS431 GHP2
	Language c++
	Compiler g++
	October 2022
*/
	void move(void); // Function prototype for moving the numbers

	for(j = 1; j <= n - 1; j++) // Looping through array
	{
		if(a[j] > a[j+1]) // Checking is next element above is larger than current
		{
			move(); // Calling move because number is larger
		}
	}

	return;

}

int k; // Global variable for location of smaller number
int temp; // Global variable for the smaller number that is being moved

void move(void)
{
/*
	The purpose of move is to assign the larger value to the new location after making
	a copy of the smaller value. It then calls on Findkay to find the location of the
	value that was overwritten. And then assign the smaller value to the correct location

	Written by Betsy Kamas
	Based on the flow chart for CS431 GHP2
	Language c++
	Compiler g++
	October 2022
*/

	void Findkay(void); // Function prototype for finding location

	temp = a[j+1]; // Setting the smaller number
	a[j+1] = a[j]; // Overwriting with larger number
	Findkay(); // Calling function to find location for temp
	a[k] = temp; // Setting the new location with the small value

	return;

}


void Findkay(void)
{
/*
	The purpose of Findkay is to find the location for the smaller value. After finding the value,
	it is assigned to a global variable which can be used above to place value in the correct location.

	Written by Betsy Kamas
	Based on the flow chart for CS431 GHP2
	Language c++
	Compiler g++
	October 2022
*/
	k = j; // Setting the location to the current spot
	int sw = 0; // Setting to 0 to allow while loop to work

	while(k > 1 && sw == 0) // Making sure k is not the first spot or the location has been found
	{
		if(a[k-1] > temp) // Checking if the value of current location is greater than the number being moved
		{
			a[k] = a[k-1]; // Moving bigger number
			k = k - 1; // Setting to check the next location
		}

		else
			sw = 1; // Location found, end loop
	}

	return;

}
