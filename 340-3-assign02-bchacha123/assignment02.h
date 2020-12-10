#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#ifndef H_PROG2
#define H_PROG2

// data files
#define FILE1 "assignment02a.dat"
#define FILE2 "assignment02b.dat"

#define ITEM_W 8 // no of spaces for each printed number


// to open two data files
void open_files(ifstream &is1, ifstream &is2)
{
	ifstream is1;
	is1.open(FILE1);

	//Check for an error
	if (!is1.fail()) {
		cout << "Error, Wrong File!" << endl;
		exit(1);
	}


	//closing the file
	//is1.close();

	// ************************************************************
	//               F i l e   # 2
	// ************************************************************

	//ifstream is2;
	is2.open(FILE2);

	//Check for an error
	if (!is2.fail()) {
		cerr << "Error, Wrong File!" << endl;
		exit(1);
	}
	//closing the file
	//is2.close(); ****
}

// ************************************************************
//         r e a d   d a t a   f u n c t i o n 
// ************************************************************
//			to read contents of two data files

void read_data(ifstream &is, vector <vector<int>> &m)
{
/*	// Matrix A rows and columns 
	unsigned nrowsA = 6;
	unsigned ncolsA = 8;

	// Matrix B rows and columns 
	unsigned nrowsB = 8;
	unsigned ncolsB = 6;

	// Matrix C rows and columns 
	unsigned nrowsC = 6;
	unsigned ncolsC = 6;
*/
	int i, j;
	for (i = 0; i < nrowsA; ++i)
	{
		for( j = 0; j < ncolsA; ++j)
		{
			fscanf(is, "%d", &(m[i][j]));
		}
	}
	
}
//
//// to print contents of all matrices
void print_data(const vector <vector<int> >&m)
{
	for (i = 0; i < C.size(); ++i)
	{
		for (j = o; j < C.size; ++j)
		{
			if
		}
	}
}
//
//// to generate a matrix by multiplying two input matrices
void gen_data(const vector <vector<int> >&,
const vector <vector<int> >&,
	vector <vector<int> >&);

#endif
