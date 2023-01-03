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

class CandidatesSelectionEasy {
 public:
  vector <int> sort(vector <string> score, int x) {
    vector<int> r;
    for (int c = 0; c < 26; c ++)
      for (int i = 0; i < score.size();i++)
        if (score[i][x] == 'A'+c)
          r.push_back(i);
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
		cout << "Testing CandidatesSelectionEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437240315;
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
		CandidatesSelectionEasy _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string score[] = {"ACB", "BAC", "CBA"};
				int x = 1;
				int __expected[] = {1, 2, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			case 1:
			{
				string score[] = {"A", "C", "B", "C", "A"};
				int x = 0;
				int __expected[] = {0, 4, 2, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			case 2:
			{
				string score[] = {"LAX","BUR","ONT","LGB","SAN","SNA","SFO","OAK","SJC"};
				int x = 2;
				int __expected[] = {5, 3, 8, 7, 4, 6, 1, 2, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			case 3:
			{
				string score[] = {"BBCBABAC","BCBACABA","CCCBAACB","CACABABB","AABBBBCC"};
				int x = 6;
				int __expected[] = {0, 1, 3, 2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			case 4:
			{
				string score[] = {"XXYWZWWYXZ","YZZZYWYZYW","ZYZZWZYYWW","ZWZWZWZXYW","ZYXWZXWYXY","YXXXZWXWXW","XWWYZWXYXY","XYYXYWYXWY","ZZYXZYZXYY","WXZXWYZWYY"};
				int x = 3;
				int __expected[] = {0, 3, 4, 5, 7, 8, 9, 6, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			case 5:
			{
				string score[] = {"X"};
				int x = 0;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}
			/*case 6:
			{
				string score[] = ;
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}*/
			/*case 7:
			{
				string score[] = ;
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
			}*/
			/*case 8:
			{
				string score[] = ;
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(score, score+sizeof(score)/sizeof(string)), x); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
