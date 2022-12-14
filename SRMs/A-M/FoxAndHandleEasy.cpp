// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel has a new favorite string operation that works as follows:
She takes two copies of some string X, and inserts one copy somewhere into the other copy of the same string.
(She can also insert it at the beginning or, equivalently, at the end.)
This operation is called expansion of the string X.
For example, if X = "Ciel", she can expand it to "CielCiel", "CCieliel", "CiCielel", or "CieCiell".



You are given two strings: S and T.
Return "Yes" (quotes for clarity) if T can be obtained by expanding S exactly once.
Otherwise, return "No".

DEFINITION
Class:FoxAndHandleEasy
Method:isPossible
Parameters:string, string
Returns:string
Method signature:string isPossible(string S, string T)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-T will contain between 1 and 50 characters, inclusive.
-Both S and T will contain uppercase and lowercase letters only ('A'-'Z' and 'a'-'z').


EXAMPLES

0)
"Ciel"
"CieCiell"

Returns: "Yes"

She can insert "Ciel" between "Cie" and "l".

1)
"Ciel"
"FoxCiel"

Returns: "No"

Each string obtained by expanding S="Ciel" has exactly 8 letters.

2)
"FoxCiel"
"FoxFoxCielCiel"

Returns: "Yes"



3)
"FoxCiel"
"FoxCielCielFox"

Returns: "No"



4)
"Ha"
"HaHaHaHa"

Returns: "No"



5)
"TheHandleCanBeVeryLong"
"TheHandleCanBeVeryLong"

Returns: "No"



6)
"Long"
"LongLong"

Returns: "Yes"



// END CUT HERE
#line 89 "FoxAndHandleEasy.cpp"
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

class FoxAndHandleEasy {
	public:
	string isPossible(string S, string T) {
		
	}
};
