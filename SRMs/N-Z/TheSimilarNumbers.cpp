// BEGIN CUT HERE
// PROBLEM STATEMENT
// Two positive integers A and B are called similar if A <= 10*B and B <= 10*A. For example, 1 and 10 are similar, but 1 and 11 are not.

You are given ints lower and upper. You must select as many integers as possible so that:

each selected integer is between lower and upper, inclusive;
no two selected integers are similar.

Return the maximum number of selected integers.

DEFINITION
Class:TheSimilarNumbers
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int lower, int upper)


CONSTRAINTS
-upper will be between 1 and 1,000,000, inclusive.
-lower will be between 1 and upper, inclusive.


EXAMPLES

0)
1
10

Returns: 1

Any two integers between 1 and 10 are similar. Therefore you may select only 1 number.

1)
5
511

Returns: 3

You can select 51, 5, and 511.

2)
5
4747

Returns: 3



3)
1
1000000

Returns: 6



4)
10
10110

Returns: 3



// END CUT HERE
#line 69 "TheSimilarNumbers.cpp"
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

class TheSimilarNumbers {
	public:
	int find(int lower, int upper) {
		
	}
};
