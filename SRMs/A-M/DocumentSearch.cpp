// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have been tasked with writing a function that will scan through a given document, and determine how many times a given word or phrase appears in that document.  However, it is important that your function does not count overlapping occurrences.  For instance, if the document were "abababa", and the search keyword was "ababa", you could find the keyword starting at index 0, or at index 2, but not both, since they would overlap.

You must concatenate the elements of the given vector <string> doc into a single string.  Then, return the maximum number of non-overlapping occurrences of the string search.

To find a maximal set of non-overlapping occurrences, perform the following procedure.  Starting from the left, find the first occurrence of the search string.  Then, continuing with the character immediately following the search string, continue looking for the next occurrence.  Repeat until no new occurrences can be found.  By continuing immediately following each found occurrence, we guarantee that we will not count overlaps.



DEFINITION
Class:DocumentSearch
Method:nonIntersecting
Parameters:vector <string>, string
Returns:int
Method signature:int nonIntersecting(vector <string> doc, string search)


CONSTRAINTS
-doc will contain between 1 and 50 elements, inclusive.
-Each element of doc will contain between 1 and 50 characters, inclusive.
-Each character of each element of doc will be a lowercase letter ('a'-'z') or a space (' ').
-search will contain between 1 and 50 characters, inclusive.
-Each character of search will be a lowercase letter ('a'-'z') or a space (' ').


EXAMPLES

0)
{"ababababa"}
"ababa"

Returns: 1

The example from the problem statement.

1)
{"ababababa"}
"aba"

Returns: 2

There are multiple ways to find the string twice, but it doesn't matter how we do it.

2)
{"abcdefghijklmnop",
 "qrstuvwxyz"}
"pqrs"

Returns: 1

Be sure to concatenate the document first.

3)
{"aaa", "aa", "a", "a"}
"aa"

Returns: 3



// END CUT HERE
#line 64 "DocumentSearch.cpp"
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

class DocumentSearch {
	public:
	int nonIntersecting(vector <string> doc, string search) {
		
	}
};
