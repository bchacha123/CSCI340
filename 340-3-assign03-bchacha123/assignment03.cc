/* 	Brayan Chacha
	z1861700
	CSCI 340, Data-Structures NIU

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/


#include <iostream>
#include <set>
#include <iomanip>

using std::set;
using std::cin;
using std::endl;
using std::cout;
using std::setw;

//void prototypes - Siece of Eratosthenes
void sieve(set<int>& s, int n);

//void prototypes - Print the numbers
void print_primes(const set<int>& s);


void sieve(set<int>& s, int n)
{
	// Remove previous numbers in s
	s.erase(s.begin(), s.end());

	// loading my numbers staring at 2
	for (int m = 2; m < n; m++)
	{
		s.insert(m);
	}

	// using a for loop that will find the 
	// prime numbers using Siece of Eratosthenes
	for (int m = 2; m * m <= n; m++)
		if (s.find(m) != s.end())
		{
			int i = 2 * m;
			while (i <= n) {
				s.erase(i);
				i += m;
			}
		}

	// Referencing s to print_primes
	print_primes(s);
}

void print_primes(const set<int>& s)
{
	// number of lines 1 - 16
	int count = 0;
	
	//creating an iterator to use in the 
	// while loop to display 1 -16
	set<int>::iterator it;

	it = s.begin();
	while (it != s.end())
	{
		count++;
		cout << setw(5) << *it;
		if (count % 16 == 0)
			cout << endl;
		it++;
	}
}

int
main()
{
	// Max numbers the user will input
	int max_num;

	// set holding the prime numers 
	set<int> primeset;

	cout << "Upper limit for the set of primes: ";

	// User input max number
	cin >> max_num;
	cout << endl;
	cout << endl;

	// Parameters that will go in the sieve funtion
	sieve(primeset, max_num);

	return 0;
}

