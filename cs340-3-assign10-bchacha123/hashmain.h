#pragma once 
#include "entry.h"
#include "htable.h"

#include<iostream>
#include<iomanip>

using namespace std;
#define BUF_SZ 256  // input buffer size

// routines to read records
void read_rec1(Entry&);
void read_rec2(Entry&);

// routine to print records
void prnt_rec1(const Entry&);

//#endif
