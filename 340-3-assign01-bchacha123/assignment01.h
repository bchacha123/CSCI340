#pragma once
#ifndef H_ASSIGNMENT01 // should not be defined any place else 
#define H_ASSIGNMENT01 // same const value as for ifndef directive

// Add needed header files here ..

// You need to implement these two functions ...
void genRndNums(vector<int> &v) {
	for (int i = 0; i <= 5000; i++) {
		srand(time(0));
		int b = rand() % 10000;
		v.push_back(b);
		cout << v[i] << endl;
	}
}

// void printVec(const vector<int> &v);

#endif





// Add needed header files here ..

// You need to implement these two functions ...
// void genRndNums(vector<int> &v);
// void printVec(const vector<int> &v);