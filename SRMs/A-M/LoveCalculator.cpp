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
typedef pair<int,string> PIS;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class LoveCalculator {
 public:
  vector<int> stringhist(const string& s) {
    vector<int> r(26,0);
    for (int i=0;i<s.size();i++)
      r[s[i]-'A']++;
    return r;
  }
  string findBoy(string girl, vector <string> boys) {
    vector<PIS> r;
    vector<int> girlhist = stringhist(girl);
    for (int i=0;i<boys.size();i++) {
      vector<int> boyhist = stringhist(boys[i]);
      int L = girlhist['L'-'A']+boyhist['L'-'A'];
      int O = girlhist['O'-'A']+boyhist['O'-'A'];
      int V = girlhist['V'-'A']+boyhist['V'-'A'];
      int E = girlhist['E'-'A']+boyhist['E'-'A'];
      int prob = -1*(((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100);
      r.push_back(PIS(prob,boys[i]));
    }
    sort(r.begin(),r.end());
    return r[0].second;
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
		cout << "Testing LoveCalculator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393267529;
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
		LoveCalculator _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string girl = "LOVE";
				string boys[] = {"JACOB","FRANK","DANO"};
				_expected = "FRANK";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			case 1:
			{
				string girl = "JANE";
				string boys[] = {"THOMAS","MICHAEL","INDY","LIU"};
				_expected = "INDY";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			case 2:
			{
				string girl = "LILLY";
				string boys[] = {"PIERRE"};
				_expected = "PIERRE";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			case 3:
			{
				string girl = "MERYLOV";
				string boys[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"};
				_expected = "DAVE";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			case 4:
			{
				string girl = "LLOL";
				string boys[] = {"BVERON","CVERON","AVERON","DVERON"};
				_expected = "AVERON";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			case 5:
			{
				string girl = "VELYLEOCEVE";
				string boys[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"};
				_expected = "VLOLUVCBLLQVESWHEEKC";
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}
			/*case 6:
			{
				string girl = ;
				string boys[] = ;
				_expected = ;
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string girl = ;
				string boys[] = ;
				_expected = ;
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string girl = ;
				string boys[] = ;
				_expected = ;
				_received = _obj.findBoy(girl, vector <string>(boys, boys+sizeof(boys)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
