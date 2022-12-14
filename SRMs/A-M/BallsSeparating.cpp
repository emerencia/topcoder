// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are N boxes numbered from 0 to N-1, inclusive. For each i, box i contains red[i] red balls, green[i] green balls, and blue[i] blue balls.


Fox Ciel wants to separate the balls by colors. In each operation, she can pick a single ball from some box and put it into another box. She considers the balls to be separated if no box contains balls of more than one color.


Return the minimal number of operations required to separate the balls. If this is impossible, return -1.


DEFINITION
Class:BallsSeparating
Method:minOperations
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minOperations(vector <int> red, vector <int> green, vector <int> blue)


CONSTRAINTS
-red, green and blue will each contain between 1 and 50 elements, inclusive.
-red, green and blue will contain the same number of elements.
-Each element of red, green and blue will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 1, 1}
{1, 1, 1}
{1, 1, 1}

Returns: 6

One way to separate the balls in six operations is as follows:

Move a red ball from box 1 to box 0.
Move a red ball from box 2 to box 0.
Move a green ball from box 0 to box 1.
Move a green ball from box 2 to box 1.
Move a blue ball from box 0 to box 2.
Move a blue ball from box 1 to box 2.

The pictures on the left and on the right show the initial and the final states of the balls, respectively.



 


1)
{5}
{6}
{8}

Returns: -1

It is impossible to separate the balls.

2)
{4, 6, 5, 7}
{7, 4, 6, 3}
{6, 5, 3, 8}

Returns: 37



3)
{7, 12, 9, 9, 7}
{7, 10, 8, 8, 9}
{8, 9, 5, 6, 13}

Returns: 77



4)
{842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}
{268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}
{662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}

Returns: 7230607



// END CUT HERE
#line 89 "BallsSeparating.cpp"
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

class BallsSeparating {
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		
	}
};
