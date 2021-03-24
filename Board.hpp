#pragma once
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

//#define MAX 250
using namespace std;
using ariel::Direction;

namespace ariel{
	class Board {
		

	public: 
		void post( unsigned int row,  unsigned int column, Direction d, string str);
		string read( unsigned int row,  unsigned int column, Direction d, int length);
		void show();
	};
}