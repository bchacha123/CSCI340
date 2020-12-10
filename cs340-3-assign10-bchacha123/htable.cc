/*
  Brayan Chacha 
  Assignment10 

  file name: htable.cc  

*/
#include "htable.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator> 

#ifndef H_TABLE
#define H_TABLE


#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters


// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
// constructor, setting the htable size
HT::HT(const unsigned &hs)
{
	// Hash table resizing
	hTable.resize(hs);

	// Pointer pTable from H
	pTable.resize(hs);

	psize = 0;

	hsize = TBL_SZ;

	for (unsigned int i = 0; i != hs; i++)
	{
		hTable[i].key = FREE;
	}
} 

// Desctructor -> clearing free memory
// 		  hTable and pTbale 
HT::~HT()
{
	hTable.clear();
	pTable.clear();
}

// insert -> inserting items to the hash table using the private hash func
void HT::insert(const Entry& e){
	int index = hash(e.key);
	unsigned int i;
	for (i = 0; i < hsize; i++)
	{
		// Inserting to the hash loop
		if(hTable[(index + i) % hsize].key == FREE)
		{
			cout << " Entry = " << (index + i ) % hsize << endl;
			hTable[(index + i) % hsize] = e;
			pTable[psize] = &hTable[(index + i) % hsize];
			psize++;
			break;
		}

		// No duplicate keys, display message 
		if (hTable[(index + i) & hsize].key == e.key)
		{
			cout << " Not inserted = duplicate key! " << endl;
			break;
		}


	}

	// Message displayed when table is full
	if ( i == hsize )
		cout << " NOt inserted - Table is full" << endl;

}

// Search -> searching the hash table using the same function
void HT::search(const string &s){
	int index = hash(s);
	unsigned int i;

	// loop that will do serch for a key
	for (i = 0; i < hsize; i++)
	{
		if (hTable[(index + i) % hsize].key == s)
		{
			cout << "==> number: " << setw(6) << hTable[(index + i) % hsize].num 
				<< " - item: " << hTable[(index + 1) % hsize].desc << endl;
			break;
		}
	}

	// message no key found! 
	if (hTable[(index + i) % hsize].key != s)
		cout << " Not in the Table! " << endl;
}

// print -> displays the hash table 
void HT::hTable_print(){
	bool lastEmpty = false;
	for (unsigned int i = 0; i < hsize; i++)
	{
		if (hTable[i].key != FREE)
		{
			if (lastEmpty) cout << endl;
			cout << setw(4) << i << ": " << hTable[i].key << " - "
			       	<< setw(5) << hTable[i].num << "   - " << hTable[i].desc << endl;
			lastEmpty = false;
		}
		else lastEmpty = true;
	}

	cout << endl;
}

// pTable_print() -> prints all the content in pTable 
void HT::pTable_print(){

	// sort ->  sort them alphabetical
	sort(pTable.begin(), pTable.end(), [](Entry* a, Entry* b) {return (a->key < b->key); });
	for (long unsigned int i = 0; i < pTable.size(); i++)
	{
		cout << setw(6) << right << pTable[i]->key << "  -";
		cout << setw(6) << right << pTable[i]->num << "  - ";
		cout << pTable[i]->desc << endl;
	}
}
#endif
