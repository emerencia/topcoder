// BEGIN CUT HERE
// PROBLEM STATEMENT
// We are playing a game with a pair of coins on a rectangular board.
The board is divided into unit square cells.
Each cell is either empty, or it contains an obstacle.
The board is given to you as a vector <string> board.
The character '#' represents an obstacle, '.' is an empty cell, and 'o' is an empty cell with a coin.
You may assume that there are exactly two coins on the board, and that initially they lie in different cells.



Next to the board, there are 4 buttons labeled "Left", "Right", "Up", and "Down".
The game is played by pushing these buttons.
When you push a button, all coins will try to move one cell in the corresponding direction.
For each coin, there can be three different outcomes:

If the next cell in the chosen direction contains an obstacle, the coin remains in its current cell.
If there is no next cell in the chosen direction (i.e., if the coin is already on the corresponding edge of the board), the coin falls off the board.
In all other cases, the coin moves one cell in the chosen direction. Note that this includes the case when the destination cell currently contains another coin.




The goal of the game is to make exactly one coin fall off the board.
If that is impossible, or if you need to push more than 10 buttons in order to achieve the goal, return -1.
Otherwise, return the smallest number of times you need to push a button in order to achieve the goal.

DEFINITION
Class:CoinsGameEasy
Method:minimalSteps
Parameters:vector <string>
Returns:int
Method signature:int minimalSteps(vector <string> board)


NOTES
-There may be some sequences of moves that will cause both coins to end in the same cell. Note that when trying to win the game such moves should be avoided.


CONSTRAINTS
-board will contain between 1 and 20 elements, inclusive.
-Every element of board will have the same length, and this length will be between 1 and 20, inclusive.
-Each character in each element of board will be one of '#', 'o' and '.'.
-There will be exactly 2 'o' in board.


EXAMPLES

0)
{"oo"}

Returns: 1

Push the Left button. The left coin will fall, the right one will move one step left and it will still be on the board.

1)
{".#", 
 ".#", 
 ".#",
 "o#",
 "o#",
 "##"}

Returns: 4

You need to push the Up button 4 times in a row.

2)
{"..",
 "..",
 "..",
 "o#",
 "o#",
 "##"}

Returns: 3

As in Example 1, this game can be won by pushing the Up button 4 times. However, there is also a shorter solution: push Up, Right, and Right, in this order.

3)
{"###",
 ".o.",
 "###",
 ".o.",
 "###"}

Returns: -1



4)
{"###",
 ".o.",
 "#.#",
 ".o.",
 "###"}

Returns: 3



5)
{"###########",
 "........#o#",
 "###########",
 ".........o#",
 "###########"}

Returns: 10



6)
{"############",
 ".........#o#",
 "############",
 "..........o#",
 "############"}

Returns: -1

You need at least 11 steps to win the game, so you should return -1.

// END CUT HERE
#line 126 "CoinsGameEasy.cpp"
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

class CoinsGameEasy {
	public:
	int minimalSteps(vector <string> board) {
		
	}
};
