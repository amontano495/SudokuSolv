//Precompiler Directives//

#ifndef CELLTYPE_H
#define CELLTYPE_H

//Header Files//
#include <ostream>
#include <iostream>
#include <cstdio>
#include <stdexcept>

using namespace std;

struct cellType
	{
		int row;
		int col;
		char block;
		int val;
		bool user; 

		cellType();
	};

//Terminating precomp directs//
#endif
