// BEGIN CUT HERE
// PROBLEM STATEMENT
// Cat Taro and Rabbit Hanako invented a new variation of "Game Of Life".


N cells are arranged around a circle. The cells are numbered from 0 to N-1. For each i between 0 and N-2, inclusive, the i-th cell and the (i+1)-th cell are adjacent to each other. The (N-1)-th cell and the 0-th cell are adjacent to each other. Each cell has exactly two adjacent cells. Each cell has a state: "live" or "die".


Taro and Hanako can decide the states of the cells at time 0. For time t > 0, the states are determined as follows:

Consider three cells: the i-th cell and the two cells that are adjacent to the i-th cell.
If at least two of the three cells are "live" at time t-1, the state of the i-th cell at time t will be "live".
If at least two of the three cells are "die" at time t-1, the state of the i-th cell at time t will be "die".

You are given a string init. The number of cells in the game (N) is equal to the number of characters in init. The i-th character of init represents the state they assign to the i-th cell at time 0. '1' means "live" and '0' means "die". Return a string that describes the states at time T using the same encoding.


DEFINITION
Class:GameOfLifeDivTwo
Method:theSimulation
Parameters:string, int
Returns:string
Method signature:string theSimulation(string init, int T)


CONSTRAINTS
-init will contain between 3 and 50 characters, inclusive.
-Each character in init will be '0' (zero) or '1' (one).
-T will be between 0 and 1,000, inclusive.


EXAMPLES

0)
"01010"
2

Returns: "00000"

At time 0, Taro and Hanako set the state to "01010".

At time 1, the state becomes "00100".

At time 2, the state becomes "00000".

1)
"010101"
5

Returns: "101010"

The state alternates between "010101" and "101010" repeatedly.

2)
"111010"
58

Returns: "111111"



3)
"111111111"
511

Returns: "111111111"

The state never changes.

4)
"110010000010111110010100001001"
1000

Returns: "110000000001111110000000000001"



5)
"00101110011"
0

Returns: "00101110011"



// END CUT HERE
#line 88 "GameOfLifeDivTwo.cpp"
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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		
	}
};
