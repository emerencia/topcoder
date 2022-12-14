// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao works at a laboratory on a highly classified project. From time to time, he is given a special device and has to determine its exact structure. Every such device operates on special plates. There are M bits written on each of the plates from left to right. The device has two inputs and a screen. Each input requires a plate. When two plates are connected to the device, M bits of output appear on the screen. Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates. Manao's task is to determine what operation is carried out for each of the bits.

Manao has N plates. He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen. It might be that the plates Manao has are not enough to uniquely identify every possible device. You are given vector <string> plates, where each element describes a plate Manao has. If these plates are certainly sufficient to determine the structure of the device completely, return "YES". Otherwise, return "NO".

DEFINITION
Class:TheDeviceDiv2
Method:identify
Parameters:vector <string>
Returns:string
Method signature:string identify(vector <string> plates)


CONSTRAINTS
-plates will contain between 1 and 50 elements, inclusive.
-Each element of plates will be between 1 and 50 characters long, inclusive.
-All elements of plates will be of equal length.
-Each element of plates will contain characters from the set {'0', '1'} only.


EXAMPLES

0)
{"010",
 "011",
 "000"}

Returns: "NO"

With these plates we cannot determine anything about the operation done on the first bit, because all of them give the same result. Also, we cannot be sure that we can determine the operation done on the third bit: if it is the AND operation, we can find this out (for example by using the first two plates), but we cannot distinguish between OR and XOR using the given plates.


1)
{"1",
 "0",
 "1",
 "0"}

Returns: "YES"

Manao will see the result for every possible combination of bits, which is enough to distinguish between AND, OR and XOR.

2)
{"11111"}


Returns: "NO"

A single plate is not enough for even one test.

3)
{"0110011",
 "0101001",
 "1111010",
 "1010010"}

Returns: "NO"

The operation done on the fifth bit from the left (1-based index) cannot be determined.

4)
{"101001011",
 "011011010",
 "010110010",
 "111010100",
 "111111111"}

Returns: "YES"



// END CUT HERE
#line 75 "TheDeviceDiv2.cpp"
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

class TheDeviceDiv2 {
	public:
	string identify(vector <string> plates) {
		
	}
};
