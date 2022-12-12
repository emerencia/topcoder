// BEGIN CUT HERE
// PROBLEM STATEMENT
// Manao has a bitmap H pixels high and W pixels wide. Initially, each of the pixels is white. Manao draws several (possibly zero) horizontal and/or vertical strokes. A stroke is a line segment 1 pixel thick and 1 or more pixels long. Manao only draws horizontal strokes with red color and vertical strokes with blue. He can paint a one pixel long stroke with either red or blue color, and the stroke will be considered horizontal if red and vertical if blue. Manao never draws two horizontal or two vertical strokes that overlap. If a horizontal stroke and a vertical stroke cross, the pixel at their intersection becomes green.

You're given a vector <string> picture denoting the bitmap after Manao's drawing experiments. The x-th character of the y-th element of picture describes the color of the pixel at coordinates (x, y) of the bitmap, where (0, 0) is the pixel at the top left corner and (W-1, H-1) is the pixel at the bottom right corner.  'R' is red, 'G' is green, 'B' is blue and '.' is white. Return the least possible number of strokes needed to obtain the given picture.

DEFINITION
Class:ColoredStrokes
Method:getLeast
Parameters:vector <string>
Returns:int
Method signature:int getLeast(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will be between 1 and 50 characters long, inclusive.
-All elements of picture will have equal length.
-Each character in picture will be 'R', 'G', 'B' or '.'.


EXAMPLES

0)
{"...",
 "..."}

Returns: 0

The picture is blank, Manao made no strokes.

1)
{"..B.",
 "..B."}

Returns: 1

A single vertical stroke is enough.

2)
{".BB."}

Returns: 2

Since only vertical strokes are painted with blue color, this picture needs two strokes.

3)
{"...B..",
 ".BRGRR",
 ".B.B.."}

Returns: 3

One horizontal and two vertical strokes are necessary for this masterpiece.

4)
{"...B..",
 ".BRBRR",
 ".B.B.."}

Returns: 4

This is the same picture as in the previous case with pixel (3,1) colored blue instead of green. Therefore, a single horizontal stroke won't help.

5)
{"GR",
 "BG"}

Returns: 4



// END CUT HERE
#line 75 "ColoredStrokes.cpp"
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

class ColoredStrokes {
	public:
	int getLeast(vector <string> picture) {
		
	}
};
