// BEGIN CUT HERE
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Cat Taro has the following building blocks:

cubes[0] red unit cubes,
cubes[1] yellow unit cubes,
cubes[2] blue unit cubes,
B black rectangular prisms with dimensions 2x1x1.


Cat Taro is using the blocks to build w adjacent towers of blocks (some possibly empty), as shown on the right side of the picture below. Taro will always place the rectangular prisms vertically. In other words, each prism will look like two black unit cubes placed one on top of the other. Taro is not required to use all of the blocks when building the towers. (In fact, he may even decide not to use any blocks at all.)

 

Rabbit Hanako is looking at Taro's towers from the left side of the room. To him, the towers seem as a single tower which we will call a view, as shown on the left side of the picture above. More precisely, at each height i Hanako sees the color of the block at height i in the leftmost tower that has such a block. Hanako's view can be described as a string of characters, giving the colors of each 1x1 square seen by Hanako in the order from bottom to top.
Black squares will be denoted 'b', and colored squares will be denoted '0', '1', and '2' (in the same order used in cubes).

You are given the vector <int> cubes, the int B, the int w, and a vector <string> views.
Each element of views specifies one view Taro wants Hanako to see, in the format specified above.
Return a vector <string> with the same number of elements as views.
If Taro can build the towers in such a way that Hanako will see the view views[i], the i-th element of the return value should be "valid", otherwise it should be "invalid" (quotes for clarity).

DEFINITION
Class:SkewedPerspectives
Method:areTheyPossible
Parameters:vector <int>, int, int, vector <string>
Returns:vector <string>
Method signature:vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views)


CONSTRAINTS
-w will be between 1 and 50, inclusive.
-cubes will contain exactly 3 elements.
-Each element of cubes will be between 0 and 100, inclusive.
-B will be between 0 and 100, inclusive.
-views will contain between 1 and 50 elements, inclusive.
-Each element of views will contain between 1 and 50 characters, inclusive.
-Each character in each element of views will be one of 'b', '0', '1', and '2'.


EXAMPLES

0)
{1,1,1}
1
2
{ "012", "012bb", "bb0", "21bb", "21b", "1bb20" }

Returns: {"valid", "valid", "valid", "valid", "valid", "valid" }

The following picture shows a way to achieve each of the given views.


1)
{0,1,0}
3
2
{"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }

Returns: {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }



2)
{100,0,0}
20
3
{"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}

Returns: {"valid", "valid", "valid", "valid" }



3)
{5,6,3}
0
1
{"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}

Returns: {"valid", "valid", "valid", "invalid", "valid", "invalid" }



4)
{100,100,100}
100
50
{"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}

Returns: {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }



5)
{0,0,0}
0
1
{"0", "bb"}

Returns: {"invalid", "invalid" }

Taro has no cubes and no prisms, therefore he cannot create any non-empty view.

6)
{3,0,0}
4
3
{"00b0b", "bbbbbbbb", "000b"}

Returns: {"invalid", "valid", "valid" }



// END CUT HERE
#line 135 "SkewedPerspectives.cpp"
#include <string>
#include <vector>
class SkewedPerspectives {
	public:
	vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
		
	}
};
