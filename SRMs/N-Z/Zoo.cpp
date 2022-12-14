// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are N animals numbered 0 to N-1 in a zoo. Each animal is a rabbit or a cat. Their heights are pairwise distinct.


Fox Jiro can't distinguish between rabbits and cats, so he asked the following question to each animal: "How many animals of the same kind as you are taller than you?" Each rabbit tells the number of rabbits taller than him, and each cat tells the number of cats taller than her. The differences of heights are slight, so Fox Jiro can't tell which animals are taller than other animals. However, each animal is able to determine which animals are taller that him and which ones are shorter.


The answer given by the i-th animal is answers[i]. Given these numbers, return the number of configurations resulting in exactly those numbers, assuming everyone tells the truth. Two configurations are different if there exists an i such that the i-th animal is a rabbit in one configuration and cat in the other configuration.


DEFINITION
Class:Zoo
Method:theCount
Parameters:vector <int>
Returns:long long
Method signature:long long theCount(vector <int> answers)


CONSTRAINTS
-answers will contain between 1 and 40 elements, inclusive.
-Each element of answers will be between 0 and 40, inclusive.


EXAMPLES

0)
{0, 1, 2, 3, 4}

Returns: 2

There are two possible configurations: all animals are rabbits or all animals are cats.

1)
{5, 8}

Returns: 0

There are only two animals. These animals are definitely lying.

2)
{0, 0, 0, 0, 0, 0}

Returns: 0



3)
{1, 0, 2, 0, 1}

Returns: 8



4)
{1, 0, 1}

Returns: 0



// END CUT HERE
#line 64 "Zoo.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

class Zoo {
	public:
	long long theCount(vector <int> answers) {
		
	}
};
