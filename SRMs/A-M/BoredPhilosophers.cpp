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

class BoredPhilosophers {
 public:
  vector <int> simulate(vector <string> text, int N) {
    string s = accumulate(text.begin(),text.end(),string(""));
    stringstream a(s);
    vector<string> words;
    while (!a.eof()) {
      string b;
      a >> b;
      words.push_back(b);
    }
    vector<int> r;
    for (int i=0;i<N;i++) {
      set<string> combs;
      for (int j=0;j+i<words.size();j++) {
        string comb = "";
        for (int k=0;k<i+1;k++)
          comb += words[j+k] + " ";
        combs.insert(comb);
      }
      r.push_back(combs.size());
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing BoredPhilosophers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397743627;
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
		BoredPhilosophers _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text[] = {"hello world"};
				int N = 2;
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}
			case 1:
			{
				string text[] = {"aaa bbb aaa bbb aaa aaa"};
				int N = 4;
				int __expected[] = {2, 3, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}
			case 2:
			{
				string text[] = {"remember"," t","o concatenate ","the"," ","text"};
				int N = 1;
				int __expected[] = {5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}
			case 3:
			{
				string text[] = {"a a a a a a a b a a b a a a b b a b a a a b a b"};
				int N = 6;
				int __expected[] = {2, 4, 7, 11, 14, 17 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}
			case 4:
			{
				string text[] = {"aa ababaa c cbbcbc cabcbcb ba bccc ababb",
				                 "c cabcba caa ababaa c cbbcbc cabcbcb ba ",
				                 "bccc ababbc cabcba c bbcbab",
				                 "b aaaa cbccaaa bccc ababbc cabcba c bbcb",
				                 "ab cbcaca"};
				int N = 7;
				int __expected[] = {15, 17, 18, 19, 20, 20, 20 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}
			/*case 5:
			{
				string text[] = ;
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}*/
			/*case 6:
			{
				string text[] = ;
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
			}*/
			/*case 7:
			{
				string text[] = ;
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.simulate(vector <string>(text, text+sizeof(text)/sizeof(string)), N); break;
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
