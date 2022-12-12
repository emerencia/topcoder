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

class TextCompressor {
 public:
  string longestRepeat(string sourceText) {
    int mx = 0;
    string mxs;
    for (int i=0;i<sourceText.size();i++)
      for (int j=0;i+j<=sourceText.size();j++)
        for (int k=i+j;k+j<=sourceText.size();k++)
          if (sourceText.substr(i,j) == sourceText.substr(k,j) && 
              sourceText.substr(i,j).size() > mx) {
            mx = sourceText.substr(i,j).size();
            mxs = sourceText.substr(i,j);
          }
    return mxs;
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
		cout << "Testing TextCompressor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398194764;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TextCompressor _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string sourceText = "ABCDABCFG";
				_expected = "ABC";
				_received = _obj.longestRepeat(sourceText); break;
			}
			case 1:
			{
				string sourceText = "ABABA";
				_expected = "AB";
				_received = _obj.longestRepeat(sourceText); break;
			}
			case 2:
			{
				string sourceText = "This is a test.";
				_expected = "is ";
				_received = _obj.longestRepeat(sourceText); break;
			}
			case 3:
			{
				string sourceText = "Testing testing 1 2 3.";
				_expected = "esting ";
				_received = _obj.longestRepeat(sourceText); break;
			}
			case 4:
			{
				string sourceText = "The quick brown fox jumps over the lazy dog.";
				_expected = "he ";
				_received = _obj.longestRepeat(sourceText); break;
			}
			/*case 5:
			{
				string sourceText = ;
				_expected = ;
				_received = _obj.longestRepeat(sourceText); break;
			}*/
			/*case 6:
			{
				string sourceText = ;
				_expected = ;
				_received = _obj.longestRepeat(sourceText); break;
			}*/
			/*case 7:
			{
				string sourceText = ;
				_expected = ;
				_received = _obj.longestRepeat(sourceText); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
