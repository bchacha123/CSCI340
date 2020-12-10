/*
   Name: Bryan Chacha 
   Couse: CSCI340 Data Structures 
   Date: 4/22/20
   Profe: Mr.Papka 

 */

// include header heap file! 
#include "heap.h"

// ***************************************************************************************
// *******************  T E M P L A T E  P R O T O T Y P E S *****************************
// ***************************************************************************************

// void get_list -> open the input file to read, read items 
// and insert them in a vector then close input file 
template <typename T>
void get_list(vector<T> &v, const char *path) {

	// Clear the vector 
	v.clear();

	// initializing tempo
	T tempo;

	// input stream file
	ifstream in_file;

	// Opening the file -> path name ofinput file 
	in_file.open(path);

	// if file isn't open, display error message 
	if (!in_file)
	{
		// User error message 
		std::cout << "Error! can open file, try again\n" << std::endl;

		// exit 
		exit(1);
	}

	// Read entry 
	in_file >> tempo;

	// read at the End-of-File 
	while (!in_file.eof())
	{
		// insert into the vector -> v
		v.push_back(tempo);
		
		// Read whats next 
		in_file >> tempo;
	}

	// close in_file 
	in_file.close();
}

// Constructing the heap using pred to compare the items being built 
template <typename T, typename P>
void construct_heap(vector<T> &v, P pred) {
 
	// Contructing the heap -> call make_heap using STL
	make_heap(v.begin(), v.end(), pred);
	
	// Sort the heap -> call sort_heap using STL
	sort_heap(v.begin(), v.end(), pred);
}

// Constructing binary predicated using greater<>() and less<>()
template<typename T>
// Boolean funtion calling routine input x and y
bool abs_less<T>::operator ( ) (const T& x, const T& y) const 
{
	//  Arguments x and y
	//  x greater than y 
	if(abs(x) < abs(y))
		return true;

	// x ISN'T greater than y -> false 
	else 
		return false;
}

// Constructing the print_funciton W - > min number printout
// 				   L - > max number of items print in line
template<typename T, const int W, const int L>
void print_list<T,W,L>::operator( )(const T& x)
{
	// count is less than or equal too size 
	if ( cnt <= sz )
	{
		// default = 0
		if (cnt % L == 0)
		{
			// Print a new line 
			cout << endl;
		}

		// diplaying the width passing W
		cout.width(W);

		// Spaces 
		cout << x << " ";

		// Deciaml numbers - > 1.00
		cout.precision(2);

		cout << fixed << showpoint;

		// incrementing count 
		cnt++;
	}

	if (cnt == sz)
		cout << endl << endl;
}

// print list printout
template< typename T, const int W, const int L>
print_list< T, W, L >::print_list( const int & s, const int& c)
{

	// heap size 
	sz = s;

	// counter 
	cnt = c;	
}

// *******************************************************************************
// ****************   M  A  I   N       F   U   C   T   I   O   N    *************
// *******************************************************************************

int 
main() {
  vector<int>    v1;  // heap of integers
  vector<float>  v2;  // heap of floating-pt nums
  vector<string> v3;  // heap of strings

  // print header message
  cout << "\t\t\t*** CSCI 340: Program 9 - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list< int, INT_SZ, INT_LN > print1 ( v1.size( ));
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float, FLT_SZ, FLT_LN > print2 ( v2.size( ));
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list < string, STR_SZ, STR_LN > print3 ( v3.size( ));
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "\t\t\t*** end of program execution ***\n\n";
  return 0;
}
