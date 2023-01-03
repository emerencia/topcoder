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

class WordsGame {
 public:
  int distance(string a, const string& word) {
    int r = 0;
    for (int i=0;i<word.size();i++) {
      if (a[i] != word[i]) {
        for (int j=i+1;j<word.size();j++)
          if (a[j] == word[i]) {
            ++r;
            swap(a[i],a[j]);
            break;
          }
      }
    }
    return r;
  }
  bool samechars(const string& a, const string& b) {
    string aa = a;
    sort(aa.begin(),aa.end());
    string bb = b;
    sort(bb.begin(),bb.end());
    return aa == bb;
  }
  int minimumSwaps(vector <string> grid, string word) {
    int r = INT_MAX;
    int n = grid.size();
    for (int i=0;i<n;i++) {
      string rword = grid[i];
      if (samechars(word,rword))
        r = min(r,distance(word,rword));
      string cword;
      for (int j=0;j<n;j++)
        cword+=grid[j][i];
      if (samechars(word,cword))
        r = min(r,distance(word,cword));
    }
    return r == INT_MAX ? -1 : r;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing WordsGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398858905;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WordsGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"Mu",
				                 "uM"};
				string word = "Mu";
				_expected = 0;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			case 1:
			{
				string grid[] = {"sdf",
				                 "bca",
				                 "hgf"};
				string word = "abc";
				_expected = 2;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			case 2:
			{
				string grid[] = {"cdf",
				                 "bca",
				                 "agf"};
				string word = "abc";
				_expected = 1;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			case 3:
			{
				string grid[] = {"xSZB",
				                 "gbHk",
				                 "kbgH",
				                 "WFSg"};
				string word = "bkHg";
				_expected = 2;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			case 4:
			{
				string grid[] = {"eKUNGHktLB",
				                 "EtBFDndTlG",
				                 "RRFHmjwrDs",
				                 "eKYsHlYhlu",
				                 "ljxyJSwTds",
				                 "dUQToyWHvl",
				                 "azDPWRwioE",
				                 "EARdktoDBh",
				                 "dmIqcGSvCE",
				                 "wXypNQEMxz"};
				string word = "oDmWcJHGNk";
				_expected = 6;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			case 5:
			{
				string grid[] = {"ab",
				                 "bA"};
				string word = "aB";
				_expected = -1;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}
			/*case 6:
			{
				string grid[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
			}*/
			/*case 8:
			{
				string grid[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumSwaps(vector <string>(grid, grid+sizeof(grid)/sizeof(string)), word); break;
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
