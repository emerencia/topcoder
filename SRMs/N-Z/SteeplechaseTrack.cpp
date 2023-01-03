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
int mem[101][51];

class SteeplechaseTrack {
 public:
  vector<string> fences,tracks;
  int N;
  int rec(int num, int last) {
    int& r = mem[num][last];
    if (r != -2) return r;
    if (num == N) return r = fences[last][2] == '0' ? -1 : (fences[last][2]-'0');
    int t = -1;
    if (fences[last][2] != '0') t = fences[last][2]-'0';
    for (int i=0;i<fences.size();i++) {
      if (tracks[last][i] == '0') continue;
      int tt = rec(num+1,i);
      if (tt == -1) continue;
      t = max(t,tracks[last][i]-'0'+fences[i][0]-'0'+tt);
    }
    return r = t;
  }
  int maxComplexity(vector <string> fences, vector <string> tracks, int N) {
    this->fences = fences;
    this->tracks = tracks;
    this->N = N;
    fill(&mem[0][0],&mem[101][0],-2);
    int r = -1;
    for (int i=0;i<fences.size();i++) {
      if (fences[i][1] == '0') continue;
      int t = rec(1,i);
      if (t == -1) continue;
      r = max(r,fences[i][1]-'0'+fences[i][0]-'0'+t);
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
		cout << "Testing SteeplechaseTrack (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401214490;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SteeplechaseTrack _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string fences[] = {"310",
				                   "300",
				                   "301"};
				string tracks[] = {"010",
				                   "001",
				                   "000"};
				int N = 4;
				_expected = 13;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}
			case 1:
			{
				string fences[] = {"923"};
				string tracks[] = {"1"};
				int N = 100;
				_expected = 1004;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}
			case 2:
			{
				string fences[] = {"111",
				                   "222",
				                   "333"};
				string tracks[] = {"743",
				                   "985",
				                   "380"};
				int N = 1;
				_expected = 9;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}
			case 3:
			{
				string fences[] = {"101",
				                   "202",
				                   "303"};
				string tracks[] = {"659",
				                   "431",
				                   "770"};
				int N = 5;
				_expected = -1;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}
			case 4:
			{
				string fences[] = {"693",
				                   "982",
				                   "236"};
				string tracks[] = {"603",
				                   "986",
				                   "780"};
				int N = 10;
				_expected = 172;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}
			/*case 5:
			{
				string fences[] = ;
				string tracks[] = ;
				int N = ;
				_expected = ;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}*/
			/*case 6:
			{
				string fences[] = ;
				string tracks[] = ;
				int N = ;
				_expected = ;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
			}*/
			/*case 7:
			{
				string fences[] = ;
				string tracks[] = ;
				int N = ;
				_expected = ;
				_received = _obj.maxComplexity(vector <string>(fences, fences+sizeof(fences)/sizeof(string)), vector <string>(tracks, tracks+sizeof(tracks)/sizeof(string)), N); break;
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
