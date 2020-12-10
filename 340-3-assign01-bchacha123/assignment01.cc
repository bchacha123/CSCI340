
/* 	Brayan Chacha
	z1861700
	CSCI 340 Data Structures
	& Algorithms in C++

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<random>
#include<time.h>

using std::cout;
using std::endl;
using std::sort;
using std::cin;
using std::vector;
using std::swap;
using std::ostream;


int MAX = 10000;
int MIN = 1;

int InitiateNum(std::vector<int>& v) {
	int a = v.size();

	//gnd a rand number 
	srand(time(NULL));

	//ranging 1 to 10000
	//int i = rand() % 10 + 1;
	int i = rand() % a;

	// rand from the v
	int number = v[i];

	// remove num from v
	swap(v[i], v[a - 1]);
	v.pop_back();

	return number;
}


void GenRandNums(int num) {

	// declaring my vec
	std::vector<int> v(num);

	// fill my v with nums
	for (int i = 0; i < num; i++)
		v[i] = i + 1;

	// print the nums 
	while (v.size())
	{
		cout << InitiateNum(v) << " ";
	}
}


int
main() {
	int number = 250;
	GenRandNums(number);

	return 1;
}