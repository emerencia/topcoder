// BEGIN CUT HERE
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We had a rectangular grid that consisted of W x H square cells.
We placed a robot on one of the cells.
The robot then followed the rules given below.


Initially, the robot is facing east.
The robot moves in steps. In each step it moves to the adjacent cell in the direction it currently faces.
The robot may not leave the grid.
The robot may not visit the same cell twice. (This also means that it may not reenter the starting cell.)
If a step forward does not cause the robot to break the above rules, the robot takes the step.
Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and checks whether a step forward still breaks the above rules.
  If not, the robot takes the step and continues executing this program (still rotated in the new direction).
If the rotation left did not help, the robot terminates the execution of this program.
We can also terminate the execution of the program manually, at any moment.

For example, the following seven images show a series of moves made by the robot in a 12 x 11 board:


We forgot the dimensions of the grid and the original (x,y) coordinates of the cell on which the robot was originally placed, but we do remember its movement. You are given a vector <int> moves. This sequence of positive integers shall be interpreted as follows:
The robot performed moves[0] steps eastwards, turned left, performed moves[1] steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it detected that it should terminate, or we stopped it manually.) We are not sure if the sequence of moves is valid. If the sequence of moves is impossible, return -1. Else, return the minimum area of a grid in which the sequence of moves is possible.
(I.e., the return value is the smallest possible value of the product of W and H.).

DEFINITION
Class:RotatingBot
Method:minArea
Parameters:vector <int>
Returns:int
Method signature:int minArea(vector <int> moves)


CONSTRAINTS
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and 50, inclusive.


EXAMPLES

0)
{15}

Returns: 16

The smallest valid board is a 16x1 board, with the robot starting on the west end of the board.

1)
{3,10}

Returns: 44

The smallest solution is to place the robot into the southwest corner of a 4 x 11 board.

2)
{1,1,1,1}

Returns: -1

This sequence of moves is not possible because the robot would return to its initial location which is forbidden.

3)
{9,5,11,10,11,4,10}

Returns: 132

These moves match the image from the problem statement.

4)
{12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

Returns: 420

5)
{8,6,6,1}

Returns: -1



6)
{8,6,6}

Returns: 63



7)
{5,4,5,3,3}

Returns: 30



// END CUT HERE
#line 99 "RotatingBot.cpp"
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

class RotatingBot {
	public:
	int minArea(vector <int> moves) {
		
	}
};
