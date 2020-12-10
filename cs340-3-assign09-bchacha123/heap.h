#include <assert.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef HEAP_H_
#define HEAP_H_

// data files

#define D1 "heap.d1"
#define D2 "heap.d2"
#define D3 "heap.d3"

#define INT_SZ 4   // width of integer
#define FLT_SZ 7   // width of floating-pt number
#define STR_SZ 12  // width of string

#define INT_LN 15  // no of integers in single line
#define FLT_LN 9   // no of floating-pt nums in single line
#define STR_LN 5   // no of strings in single line

// function and class prototypes

// stores items from input file into vector
template <typename T>
void get_list(vector<T>&, const char*);

// construct heap from items in vector
template <typename T, typename P>
void construct_heap(vector<T>&, P);

// class to compate values 
template<typename T> class abs_less
{
	public:
	// initialiazing the boolean 
	bool operator ( ) (const T&, const T& ) const;
};

// function and class prototype
template<typename T, const int W, const int L>
struct print_list
{
	// heap size, counter for printout
	int sz, cnt;

	public:
	// max number of items printed single line, 0 default new line 
	print_list(const int&, const int& = 0);

	void operator()(const T&);
};

#endif  // HEAP_H_
