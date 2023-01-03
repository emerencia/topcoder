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
typedef pair<string,int> PSI;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
bool seen[51][51];

class MergeStrings {
 public:
  string S,A,B;
  vector<vector<PSI> > mem;
  PSI rec(int aidx, int bidx) {
    int sidx = aidx+bidx;
    if (seen[aidx][bidx]) {
      return mem[aidx][bidx];
    }
    seen[aidx][bidx] = 1;
    if (sidx == S.size()) {
      return mem[aidx][bidx] = PSI("",1);
    }
    PSI ares = PSI("",0);
    PSI bres = PSI("",0);
    if (aidx < A.size() && (A[aidx] == S[sidx] || S[sidx] == '?'))
      ares = rec(aidx + 1, bidx);
    if (bidx < B.size() && (B[bidx] == S[sidx] || S[sidx] == '?'))
      bres = rec(aidx, bidx + 1);
    string aress = string(1,A[aidx])+ares.first;
    string bress = string(1,B[bidx])+bres.first;
    if (ares.second && bres.second) {
      return mem[aidx][bidx] = PSI(min(aress,bress),1);
    } else if (ares.second) {
      return mem[aidx][bidx] = PSI(aress,1);
    } else if (bres.second) {
      return mem[aidx][bidx] = PSI(bress,1);
    } else {
      return mem[aidx][bidx] = PSI("",0);
    }
  }
  string getmin(string S, string A, string B) {
    this->S = S;
    this->A = A;
    this->B = B;
    memset(seen,0,sizeof(seen));
    mem = vector<vector<PSI> >(51,vector<PSI>(51));
    string a;
    PSI result = rec(0,0);
    if (result.second) return result.first;
    return "";
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
		cout << "Testing MergeStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425933623;
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
		MergeStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "??CC??";
				string A = "ABC";
				string B = "BCC";
				_expected = "ABCCBC";
				_received = _obj.getmin(S, A, B); break;
			}
			case 1:
			{
				string S = "WHAT?";
				string A = "THE";
				string B = "WA";
				_expected = "";
				_received = _obj.getmin(S, A, B); break;
			}
			case 2:
			{
				string S = "PARROT";
				string A = "PARROT";
				string B = "";
				_expected = "PARROT";
				_received = _obj.getmin(S, A, B); break;
			}
			case 3:
			{
				string S = "???????????";
				string A = "AZZAA";
				string B = "AZAZZA";
				_expected = "AAZAZZAAZZA";
				_received = _obj.getmin(S, A, B); break;
			}
			case 4:
			{
				string S = "????K??????????????D???K???K????????K?????K???????";
				string A = "KKKKKDKKKDKKDDKDDDKDKK";
				string B = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD";
				_expected = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK";
				_received = _obj.getmin(S, A, B); break;
			}
			/*case 5:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 6:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 7:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
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
