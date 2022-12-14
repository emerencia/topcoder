// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You have just been hired to be a judge in the Thought Challenge Olympics.  Your task is to calculate an overall score for a competitor based on his performance in a series of events.  For each event, you have given him a raw score.  The overall score is the sum of the adjusted scores for each event.

To calculate the adjusted score for an event, divide the raw score by the conversion factor for that event, and round the result to the nearest integer (.5 rounds up).  You are given vector <int>s rawScores and conversionFactors.  Element i of rawScores is the raw score you have given for the i-th event, and element i of conversionFactors is the conversion factor for the i-th event.  Return the competitor's overall score.


DEFINITION
Class:TournamentJudging
Method:getPoints
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getPoints(vector <int> rawScores, vector <int> conversionFactor)


CONSTRAINTS
-rawScores will contain between 1 and 50 elements, inclusive.
-Each element of rawScores will be between 0 and 1,000,000, inclusive.
-conversionFactor will contain the same number of elements as rawScores.
-Each element of conversionFactors will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{10, 20, 30}
{10, 10, 5}

Returns: 9

The competitor receives 1, 2, and 6 points, respectively.

1)
{8, 16, 32}
{10, 10, 5}

Returns: 9

Due to rounding, the competitor again gets 1, 2, and 6 points.

2)
{60, 59}
{24, 24}

Returns: 5

Be careful to correctly round to the nearest integer (0.5 rounds up).

3)
{47, 42, 37, 30, 27, 21, 18}
{1, 2, 3, 4, 5, 6, 7}

Returns: 100



4)
{0, 1000000, 5000, 1000000}
{1, 2, 1000000, 4}

Returns: 750000



// END CUT HERE
#line 68 "TournamentJudging.cpp"
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

class TournamentJudging {
	public:
	int getPoints(vector <int> rawScores, vector <int> conversionFactor) {
		
	}
};
