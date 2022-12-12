#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int mem[101][101];

class TheMatrix {
 public:
	vector<string> newboard;
	int starti, startj;
	char cur;
	int rec(int di, int dj) {
    int& r = mem[di][dj];
		if (r != -1) return r;
		// call stuff with the maximum of increasing i or j
		// prerequisites:
		// - the calling position is valid
		// - we only return what was added
		// - we only add, never remove
		int t = 0;
		if (starti+di+1 < newboard.size()) {
			// try adding a row
			bool good = true;
			for (int j=0;j<=dj;j++)
				if (newboard[starti+di+1][startj+j] != cur)
					good = false;
			if (good) t = max(t,dj+1+rec(di+1,dj));
		}
		if (startj+dj+1 < newboard[0].size()) {
			// try adding a column
			bool good = true;
			for (int i=0;i<=di;i++)
				if (newboard[starti+i][startj+dj+1] != cur)
					good = false;
			if (good) t = max(t,di+1+rec(di,dj+1));
		}
		return r = t;
	}
  int MaxArea(vector <string> board) {
    newboard = vector<string>(board.size(),string(board[0].size(),'?'));
		for (int i=0;i<board.size();i++)
			for (int j=0;j<board[0].size();j++) {
				int pos = abs(i-j);
				if (pos%2 == board[i][j]-'0') newboard[i][j] = '.';
				else newboard[i][j] = 'X';
			}
    /*
		for (int i=0;i<board.size();i++) {
			for (int j = 0; j < board[0].size(); j++)
				cout << newboard[i][j];
			cout << endl;
		}
    */
		// here we do need consistent caching
		int r = 0;
		for (int i=0;i<board.size();i++)
			for (int j=0;j<board[0].size();j++) {
				starti = i;
				startj = j;
				cur = newboard[i][j];
				memset(mem,-1,sizeof(mem));
				r = max(r,1+rec(0,0));
			}
		return r;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing TheMatrix (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417463392;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMatrix _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"1", 
				                  "0"};
				_expected = 2;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"0000"};
				_expected = 1;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"01"};
				_expected = 2;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"001",
				                  "000",
				                  "100"};
				_expected = 2;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"0"};
				_expected = 1;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"101", 
				                  "010"};
				_expected = 6;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"101", 
				                  "011", 
				                  "101", 
				                  "010"};
				_expected = 8;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"11001110011000110001111001001110110011010110001011", 
				                  "10100100010111111011111001011110101111010011100001", 
				                  "11101111001110100110010101101100011100101000010001", 
				                  "01000010001010101100010011111000100100110111111000", 
				                  "10110100000101100000111000100001011101111101010010", 
				                  "00111010000011100001110110010011010110010011100100", 
				                  "01100001111101001101001101100001111000111001101010", 
				                  "11010000000011011010100010000000111011001001100101", 
				                  "10100000000100010100100011010100110110110001000001", 
				                  "01101010101100001100000110100110100000010100100010", 
				                  "11010000001110111111011010011110001101100011100010", 
				                  "11101111000000011010011100100001100011111111110111", 
				                  "11000001101100100011000110111010011001010100000001", 
				                  "00100001111001010000101101100010000001100100001000", 
				                  "01001110110111101011010000111111101011000110010111", 
				                  "01001010000111111001100000100010101100100101010100", 
				                  "11111101001101110011011011011000111001101100011011", 
				                  "10000100110111000001110110010000000000111100101101", 
				                  "01010011101101101110000011000110011111001111011100", 
				                  "01101010011111010000011001111101011010011100001101", 
				                  "11011000011000110010101111100000101011011111101100", 
				                  "11100001001000110010100011001010101101001010001100", 
				                  "11011011001100111101001100111100000101011101101011", 
				                  "11110111100100101011100101111101000111001111110111", 
				                  "00011001100110111100111100001100101001111100001111", 
				                  "10001111100101110111001111100000000011110000100111", 
				                  "10101010110110100110010001001010000111100110100011", 
				                  "01100110100000001110101001101011001010001101110101", 
				                  "10110101110100110110101001100111110000101111100110", 
				                  "01011000001001101110100001101001110011001001110001", 
				                  "00100101010001100110110101001010010100001011000011", 
				                  "00011101100100001010100000000011000010100110011100", 
				                  "11001001011000000101111111000000110010001101101110", 
				                  "10101010110110010000010011001100110101110100111011", 
				                  "01101001010111010001101000100011101001110101000110", 
				                  "00110101101110110001110101110010100100110000101101", 
				                  "11010101000111010011110011000001101111010011110011", 
				                  "10010000010001110011011101001110110010001100011100", 
				                  "00111101110001001100101001110100110010100110110000", 
				                  "00010011011000101000100001101110111100100000010100", 
				                  "01101110001101000001001000001011101010011101011110", 
				                  "00000100110011001011101011110011011101100001110111", 
				                  "00110011110000011001011100001110101010100110010110", 
				                  "00111001010011011111010100000100100000101101110001", 
				                  "10101101101110111110000011111011001011100011110001", 
				                  "00101110010101111000001010110100001110111011100011", 
				                  "01111110010100111010110001111000111101110100111011"};
				_expected = 12;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010100000001010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010000010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010100000001010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010000010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010100000001010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101", "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010", "0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"};
				_expected = 4800;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.MaxArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
