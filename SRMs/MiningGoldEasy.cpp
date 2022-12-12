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
// start 21:08
// END CUT HERE
int mem[51][51][51];

class MiningGoldEasy {
 public:
	vector<int> xs, ys, event_i, event_j;
	int amount;
	int rec(int idx, int xi, int yi) {
		int& r = mem[idx][xi][yi];
		if (r != -1) return r;
		if (idx == event_i.size()) return r = 0;
		int extra = amount-abs(event_i[idx]-xs[xi])-abs(event_j[idx]-ys[yi]);
		int t = 0;
		for (int i=0;i<xs.size();i++)
			t = max(t,rec(idx+1,i,yi));
		for (int i=0;i<ys.size();i++)
			t = max(t,rec(idx+1,xi,i));
		return r = t+extra;
	}
  int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j) {
		this->event_i = event_i;
		this->event_j = event_j;
		amount = N+M;
		set<int> xset, yset;
		for (int i=0;i<event_i.size();i++) {
			xset.insert(event_i[i]);
			yset.insert(event_j[i]);
		}
		xs.clear();
		for (set<int>::iterator i=xset.begin();i!=xset.end();i++)
			xs.push_back(*i);
		ys.clear();
		for (set<int>::iterator i=yset.begin();i!=yset.end();i++)
			ys.push_back(*i);
		int r = 0;
		memset(mem,-1,sizeof(mem));
		for (int i=0;i<xs.size();i++)
			for (int j=0;j<ys.size();j++)
				r = max(r,rec(0,i,j));
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
		cout << "Testing MiningGoldEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417547377;
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
		MiningGoldEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				int event_i[] = {0};
				int event_j[] = {0};
				_expected = 4;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int M = 2;
				int event_i[] = {0, 2};
				int event_j[] = {0, 1};
				_expected = 7;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int M = 3;
				int event_i[] = {0, 3, 3};
				int event_j[] = {0, 3, 0};
				_expected = 15;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 3;
				int M = 4;
				int event_i[] = {0, 3};
				int event_j[] = {4, 1};
				_expected = 11;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 5;
				int M = 6;
				int event_i[] = {0, 4, 2, 5, 0};
				int event_j[] = {3, 4, 5, 6, 0};
				_expected = 48;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 557;
				int M = 919;
				int event_i[] = {81, 509, 428, 6, 448, 149, 77, 142, 40, 405, 109, 247};
				int event_j[] = {653, 887, 770, 477, 53, 637, 201, 863, 576, 393, 512, 243};
				_expected = 16255;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int M = ;
				int event_i[] = ;
				int event_j[] = ;
				_expected = ;
				_received = _obj.GetMaximumGold(N, M, vector <int>(event_i, event_i+sizeof(event_i)/sizeof(int)), vector <int>(event_j, event_j+sizeof(event_j)/sizeof(int))); break;
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
