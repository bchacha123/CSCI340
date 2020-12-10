/*
  Bryan Chacha 
  file: htable.h 

 */

#include "entry.h"

#ifndef H_HASH_TABLE
#define H_HASH_TABLE

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

// class for hash table
class HT {
 public:
  HT(const unsigned& = TBL_SZ);  // constructor
  ~HT();                         // destructor

  void insert(const Entry&);   // inserts item in hash table
  void search(const string&);  // searches for item

  void hTable_print();  // prints hash table entries
  void pTable_print();  // prints hash table entries in sorted order

 private:
  unsigned hsize, psize;  // size of hash table

  vector < Entry  > hTable;  // hash table <list<Entry> >
  vector < Entry* > pTable;  // ptr table
 

  int hash(const string&);  // hash function
};

#endif
