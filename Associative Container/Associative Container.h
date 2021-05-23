// Associative Container.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <cmath>

void print_num(int* myNum) {
	assert(myNum != NULL);
	std::cout << "my num \t:[ " << *myNum << "]" << std::endl;
}

void debug(double a) {
	assert(a >= 0);
	std::cout << " square root is \t:[" << sqrt(a) << "]" << std::endl;
}
// TODO: Reference additional headers your program requires here.
