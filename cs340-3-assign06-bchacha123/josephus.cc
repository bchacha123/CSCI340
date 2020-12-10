/*
   Name: Brayan Chacha Gonzalez
   Date: 3/17/2020
   Course: CSCI 340 DataStructures
   Descrip: Creating a game base on Josephus

*/



#include <iostream>
#include <iomanip>
#include "josephus.h"

// Declaring STL variables 
using std::advance;
using std::endl;
using std::cin;
using std::cout;


// Number of rows that will be displayed
const int TAGS_LINE = 12;

int main(){
	// Struct has been created holding the numbers for the game
	// N = Total # of people, M = # of eliminated people, K = Frequency
	args josephusStruct;

	// Initializng myList - josephusLis
	list <string> josephusLis;

	// Counting # of passes
	unsigned count = 1;

	// Displaying the numbers to N,M,K
	cout << "Numbe of People? 41\n";
	josephusStruct.N = 41;
	
	cout << "Index for elimination? 3\n";
	josephusStruct.M = 3;
	
	cout << "Index for printing? 7\n";
	josephusStruct.K = 7;

	// Setting up my list, calling my init_vals function
	init_vals(josephusLis, josephusStruct);

	// Displaying people that are playing, calling my print_list function
	print_list(josephusLis, count);

	// Begging to eleminate by index - M
	josephusStruct.M -= 1;

	// Creating an Iterator to start the elimination
	auto indexIterator = josephusStruct.M % josephusLis.size();

	// Will continue to loop until theres only one left in the list 
	while (josephusLis.size() > 1)
	{
		// lisIterator to access my list 
		auto lisIterator = josephusLis.begin();

		// Advance - locates the M^th person in the list 
		advance(lisIterator, indexIterator);

		// Removes the element from the list 
		josephusLis.erase(lisIterator);

		// Fixing the indexIterator, setting it up to elimination
		indexIterator += josephusStruct.M;
		indexIterator %= josephusLis.size();

		// Display my list
		if ((count % josephusStruct.K == 0 && count != 0) || josephusLis.size() == 1)
			print_list(josephusLis, count);

		// Increment 
		count++;
	
	}

	cout << endl;

return 0;
}

// ********************************************************************************************
// *************      i n i t i a l i z e     v a l s    f u n c t i o n  *********************
// ********************************************************************************************

void init_vals(list <string>& lis, args& in)
{
	lis.resize(in.N);
	generate(lis.begin(), lis.end(), SEQ(in.N));
}


// ********************************************************************************************
//  ***********************  p r i n t   f u n c t i o n **************************************
//  *******************************************************************************************

void print_list(const list<string>& lis, const unsigned& cnt)
{
	// Creating my iterator what is in my list
	list <string>::const_iterator listIt;

	// Counting per line
	int itemCount = 0;

	// Displaying 1st group
	if(cnt < 2)
	{
		cout << "\nInitial group of people " << "\n______________________________\n";
		
	}
	
	//Displaying next group after elimination
	else
	{
		cout << "\nAfter eliminating " << cnt << "th person" << endl << "_____________________________\n";		

	}
	
	// For loop - Uses an iterator that will pass through my list 
	for(listIt = lis.begin(); listIt != lis.end(); listIt++)
	{
		if(itemCount % TAGS_LINE == 0 && itemCount != 0)
			cout << endl;
		cout << *listIt << " ";
		itemCount++;

	}

	cout << endl;

}








