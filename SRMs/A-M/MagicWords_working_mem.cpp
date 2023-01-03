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

class MagicWords {
 public:
  int K;
  map<string,bool> mem;
  bool ismagic(const string& s) {
    if (mem.count(s)) return mem[s];
    int r = 0;
    for (int i=0;i<s.size();i++) {
      bool good = true;
      for (int j=0;j<s.size();j++)
        if (s[j] != s[(j+i)%s.size()]) {
          good = false;
          break;
        }
      r+=good;
    }
    return mem[s]= (r == K);
  }
  int count(vector <string> S, int K) {
    vector<int> p;
    this->K = K;
    mem.clear();
    for (int i=0;i<S.size();i++)
      p.push_back(i);
    int r = 0;
    do {
      string s;
      for (int i=0;i<p.size();i++)
        s+=S[p[i]];
      r+=ismagic(s);
    } while (next_permutation(p.begin(),p.end()));
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing MagicWords (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393861087;
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
		MagicWords _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S[] = {"CAD","ABRA","ABRA"};
				int K = 1;
				_expected = 6;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 1:
			{
				string S[] = {"AB","RAAB","RA"};
				int K = 2;
				_expected = 3;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 2:
			{
				string S[] = {"AA","AA","AAA","A"};
				int K = 1;
				_expected = 0;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 3:
			{
				string S[] = {"AA","AA","AAA","A","AAA","AAAA"};
				int K = 15;
				_expected = 720;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 4:
			{
				string S[] = {"ABC","AB","ABC","CA"};
				int K = 3;
				_expected = 0;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 5:
			{
				string S[] = {"A","B","C","A","B","C"};
				int K = 1;
				_expected = 672;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			case 6:
			{
				string S[] = {"AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAA",
				              "AAAAAAAAAAAAAAAAAAAB"};
				int K = 1;
				_expected = 40320;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}
			/*case 7:
			{
				string S[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}*/
			/*case 8:
			{
				string S[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
			}*/
			/*case 9:
			{
				string S[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(S, S+sizeof(S)/sizeof(string)), K); break;
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
