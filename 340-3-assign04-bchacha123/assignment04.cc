
/*
   Brayan Chacha G
   z1861700
   CSCI 340 Data Structures & Algo

*/

#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
#include<map>
#include<iomanip>

// STL Library 
using std::cout;
using std::map;
using std::string;
using std::cin;
using std::endl;
using std::setw;
using std::left;

// Declaring map
typedef map < string, int >::const_iterator it_map_type;

// spaces for output
const int NO_ITEMS = 3;
const int ITEM_W   = 16;

// bool to check if word is alphanumeric
// isalnum() - checking input string. will return true or false
bool is_alpha(const char& a)
{
	return isalnum(a);
}

bool Not_alpha(const char& a)
{
	return !isalnum(a);
}

// Convertion funtion using tolower to return lower case 
// tolower () - convertion of lowercase used in C 
void convert_to_low(char& a){
	a = tolower(a);
	return;
}

// Printing the final words and how many times is showed up
void print_words(const map < string, int >& m)
{
	// Rows / Colums
	int count = 0;
	int num = 0;

	// Creating iterator that will loop though the map
	for (it_map_type it = m.begin(); it != m.end(); ++it)
	{
		if ( count == NO_ITEMS)
		{
			count = 0;
			cout << endl;
		}

		num += (*it).second;
		cout << setw(ITEM_W) << left << (*it).first << " : " << setw(3) << (*it).second << "    ";
		count++;

	}
	
	// What will apear in the output
	cout << endl << endl << " No of words in input stream   : " << num << endl;
	cout << " No of words in output stream  : " <<  m.size() << endl << endl;
}

// function cleans words from punctuation marks
void clean_entry( const string& s1, string& s2)
{
	// Initialzing the values 
	int in = 0;
	int iEnd = 0;

	// could also use getopt ? 
	bool punc = false;
	bool begging = false;
	bool end = false;

	// setting a for loop that will true / false 
	// if character is alphanumeric 
	// along with any symbols in between " fish-sticks " 
	for (int counter = 0; counter < (int)s1.length(); counter++)
	{
		if(Not_alpha(s1[counter]))
		{
			punc = true;
		}

		if(is_alpha(s1[counter]) && begging == false)
		{
			begging = true;
			in = counter;
		}

		if(begging == true )
		{
			if(Not_alpha(s1[counter]))
			{
				end = true;
				iEnd = counter;

			}
		}

		if (end == true)
		{
			break;
		}

	}

	// setting s2 = to s1 with bounderies
	// substr () - copying the word from alpha until
	// the next string
	s2 = s1.substr(in, iEnd - in);

	// calling the convert to function
	for_each(s2.begin(), s2.end(), convert_to_low);

	// if it has no punc dont call substr
	if(punc == false)
	{
		s2 = s1;
		for_each(s2.begin(), s2.end(), convert_to_low);
	}
	


}

// getting the words from user input "assignment04.in"
void get_words(map <string, int>& m)
{
	string toClean, wrd;

	// while loop to retrive new upcoming words 
	while (cin)
	{
		cin >> toClean;

		// Clean up time! 
		clean_entry(toClean, wrd);

		// inserting it to the map
		if(wrd.size() > 0) m[wrd]++;
	}
}


int main() 
{

	// My map
	// key - my string - words 
	// val - is _ # of times of that word
	map<string, int> words;
	
	// calling get_words funtion
	get_words(words);

	//printing my words - map
	print_words(words);

	return 0;
}

