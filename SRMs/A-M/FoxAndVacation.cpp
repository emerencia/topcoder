// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is planning to visit the Tourist Kingdom for total days.
This kingdom is full of lovely cities.
During her stay Ciel would like to visit as many different cities as possible.
She cannot visit more than one city on the same day.



Additionally, different cities may require her to stay for a different number of days.
For each i, city i only counts as visited if Ciel spends at least d[i] days in the city.



You are given the int total and the vector <int> d.
Return the maximal number of cities she can visit during her vacation.

DEFINITION
Class:FoxAndVacation
Method:maxCities
Parameters:int, vector <int>
Returns:int
Method signature:int maxCities(int total, vector <int> d)


NOTES
-When solving the task, ignore travel times. (Fox Ciel always travels at night, and she can travel between any two cities very quickly.)


CONSTRAINTS
-total will be between 1 and 50, inclusive.
-d will contain between 1 and 50 elements, inclusive.
-Each element of d will be between 1 and 50, inclusive.


EXAMPLES

0)
5
{2,2,2}

Returns: 2

Fox Ciel's vacation lasts for 5 days. She needs at least 2 days to visit each of the cities, so she can visit at most 2 of them.

1)
5
{5,6,1}

Returns: 1

She can only visit one city: either city 0, or city 2.

2)
5
{6,6,6}

Returns: 0

This time the poor Fox Ciel cannot visit any city during her summer vacation.

3)
6
{1,1,1,1,1}

Returns: 5

In this test case Ciel can visit all five cities.
Note that at the end of her trip each city either does count as visited, or it does not -- there is no way to "visit" the same city twice.

4)
10
{7,1,5,6,1,3,4}

Returns: 4



5)
50
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}

Returns: 9



6)
21
{14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14}

Returns: 6



// END CUT HERE
#line 97 "FoxAndVacation.cpp"
#include <string>
#include <vector>
class FoxAndVacation {
	public:
	int maxCities(int total, vector <int> d) {
		
	}
};
