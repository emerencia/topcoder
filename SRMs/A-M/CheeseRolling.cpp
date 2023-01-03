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
LL mem[16][16][1<<16];

int bitcount(int n) {
  int r = 0;
  for (int i = n;i;i&=i-1) ++r;
  return r;
}

class CheeseRolling {
 public:
  vector<string> wins;
  int pwr;
  LL rec(int idx, int round, int mask) {
    LL& r = mem[idx][round][mask];
    if (r != -1) return r;
    if (round == 1) {
      LL t = 0;
      for (int i=0;i<wins.size();i++) {
        if (mask&(1<<i)) continue;
        if (wins[idx][i] == 'Y')
          t++;
      }
      return r = 2*t;
    }
    LL t = 0;
    // iterate over all submasks
    // that are of equal size
    for (int i = 0;i<wins.size();i++) {
      if (mask&(1<<i)) continue;
      if (wins[idx][i] == 'Y') {
        int oldmask = mask | (1<<i);
        int submask = ((1<<wins.size())-1)^oldmask;
        for (int u = submask; u >= 0; u = (u? ((u - 1)&submask) : -1) ) {
          int newmask = oldmask | u;
          if ((newmask & oldmask) == oldmask && bitcount(newmask) > bitcount(oldmask)) {
            int flipnewmask = ((1<<wins.size())-1)&(~(newmask^oldmask));
            if (bitcount(flipnewmask) == bitcount(newmask)) {
              t += 2LL * rec(idx, round - 1, newmask) * rec(i, round - 1, flipnewmask);
            }
          }
        }
      }
    }
    return r = t;
  }
  vector<long long> waysToWin(vector <string> wins) {
    this->wins = wins;
    memset(mem,-1,sizeof(mem));
    vector<LL> r;
    pwr = 0;
    int t = wins.size();
    while (t != 1) {
      pwr++;
      t/=2;
    }
    for (int i =0;i<wins.size();i++)
      r.push_back(rec(i,pwr,1<<i));
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
		cout << "Testing CheeseRolling (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438444047;
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
		CheeseRolling _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string wins[] = {"NN",
				                 "YN"};
				long long __expected[] = {0LL, 2LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}
			case 1:
			{
				string wins[] = {"NYNY",
				                 "NNYN",
				                 "YNNY",
				                 "NYNN"};
				long long __expected[] = {8LL, 0LL, 16LL, 0LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}
			case 2:
			{
				string wins[] = {"NYNYNYNY",
				                 "NNYNYNYY",
				                 "YNNNNNNN",
				                 "NYYNNYNY",
				                 "YNYYNYYY",
				                 "NYYNNNNN",
				                 "YNYYNYNN",
				                 "NNYNNYYN"};
				long long __expected[] = {4096LL, 8960LL, 0LL, 2048LL, 23808LL, 0LL, 1408LL, 0LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}
			case 3:
			{
				string wins[] = {"NYNNNNYYNYYNNYNN",
				                 "NNNNNNNNNYYNYYNY",
				                 "YYNYYNNNNYYYYYYN",
				                 "YYNNYYYNYNNYYYNY",
				                 "YYNNNYYNYYNNNNYY",
				                 "YYYNNNNYYNNYYNYN",
				                 "NYYNNYNYNYNYYYYN",
				                 "NYYYYNNNYYNYNYYY",
				                 "YYYNNNYNNYYYYNNN",
				                 "NNNYNYNNNNNNYYNY",
				                 "NNNYYYYYNYNYYYNN",
				                 "YYNNYNNNNYNNYNNY",
				                 "YNNNYNNYNNNNNYNN",
				                 "NNNNYYNNYNNYNNYY",
				                 "YYNYNNNNYYYYYNNN",
				                 "YNYNNYYNYNYNYNYN"};
				long long __expected[] = {331616878592LL, 37267079168LL, 2426798866432LL, 2606831599616LL, 994941665280LL, 1162501849088LL, 1888166674432LL, 4632734203904LL, 832881524736LL, 84707409920LL, 3007127748608LL, 55490052096LL, 17818550272LL, 254672666624LL, 629921447936LL, 1959311671296LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}
			case 4:
			{
				string wins[] = {"NYYYYYYYYYYYYYYY",
				                 "NNYYYYYYYYYYYYYY",
				                 "NNNYYYYYYYYYYYYY",
				                 "NNNNYYYYYYYYYYYY",
				                 "NNNNNYYYYYYYYYYY",
				                 "NNNNNNYYYYYYYYYY",
				                 "NNNNNNNYYYYYYYYY",
				                 "NNNNNNNNYYYYYYYY",
				                 "NNNNNNNNNYYYYYYY",
				                 "NNNNNNNNNNYYYYYY",
				                 "NNNNNNNNNNNYYYYY",
				                 "NNNNNNNNNNNNYYYY",
				                 "NNNNNNNNNNNNNYYY",
				                 "NNNNNNNNNNNNNNYY",
				                 "NNNNNNNNNNNNNNNY",
				                 "NNNNNNNNNNNNNNNN"};
				long long __expected[] = {20922789888000LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}
			/*case 5:
			{
				string wins[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string wins[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string wins[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.waysToWin(vector <string>(wins, wins+sizeof(wins)/sizeof(string))); break;
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
