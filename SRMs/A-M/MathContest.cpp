#include <string>
#include <iostream>
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

class MathContest {
 public:
  int countBlack(string ballSequence, int repetitions) {
    string s;
    for (int i=0;i<repetitions;i++)
      s+=ballSequence;
    bool reversed = false;
    bool inverted = false;
    int bcount = 0;
    while (s.size()) {
      int j = 0;
      if (reversed) j = s.size()-1;
      char c = s[j];
      if (inverted) c = (c == 'W' ? 'B' : 'W');
      if (reversed) s = s.substr(0,s.size()-1);
      else s=s.substr(1);
      if (c == 'W') {
         reversed = !reversed;
      } else {
        bcount++;
        inverted = !inverted;
      }
    }
    return bcount;
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing MathContest (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390299449;
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
		MathContest _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string ballSequence = "BBWWB";
				int repetitions = 1;
				_expected = 2;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}
			case 1:
			{
				string ballSequence = "BBB";
				int repetitions = 10;
				_expected = 1;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}
			case 2:
			{
				string ballSequence = "BW";
				int repetitions = 10;
				_expected = 20;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}
			case 3:
			{
				string ballSequence = "WWWWWWWBWWWWWWWWWWWWWW";
				int repetitions = 1;
				_expected = 2;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}
			/*case 4:
			{
				string ballSequence = ;
				int repetitions = ;
				_expected = ;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}*/
			/*case 5:
			{
				string ballSequence = ;
				int repetitions = ;
				_expected = ;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}*/
			/*case 6:
			{
				string ballSequence = ;
				int repetitions = ;
				_expected = ;
				_received = _obj.countBlack(ballSequence, repetitions); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
