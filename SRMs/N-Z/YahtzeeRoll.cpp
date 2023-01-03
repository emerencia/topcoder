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

class YahtzeeRoll {
 public:
  double valueof(vector<int>& dice) {
    int score = 0;
    vector<int> frequencies(7,0);
    for (int i=0;i<dice.size();i++)
      frequencies[dice[i]]++;
    bool two = false, three = false;
    for (int i=0;i<frequencies.size();i++) {
      if (frequencies[i] == 2) two = true;
      else if (frequencies[i] == 3) three = true;
    }
    if (two && three) score = max(score,25);
    if ((frequencies[1] && frequencies[2] && frequencies[3] && frequencies[4]) ||
        (frequencies[2] && frequencies[3] && frequencies[4] && frequencies[5]) ||
        (frequencies[3] && frequencies[4] && frequencies[5] && frequencies[6]))
      score = max(score,30);
    if ((frequencies[1] && frequencies[2] && frequencies[3] && frequencies[4] && frequencies[5]) ||
        (frequencies[2] && frequencies[3] && frequencies[4] && frequencies[5] && frequencies[6]))
      score = max(score,40);
    bool allfivesame = false;
    for (int i=0;i<frequencies.size();i++)
      if (frequencies[i] == 5)
        allfivesame = true;
    if (allfivesame) score = max(score,50);
    return score;
  }
  double rec(vector<int>& dice, int togo) {
    if (!togo) return valueof(dice);
    double r = 0;
    for (int i=1;i<=6;i++) {
      vector<int> ndice = dice;
      ndice.push_back(i);
      r+=1.0/6*rec(ndice,togo-1);
    }
    return r;
  }
  double reroll(vector<int> dice, int mask) {
    vector<int> ndice;
    for (int i=0;i<dice.size();i++) {
      if (!(mask&(1<<i))) continue;
      ndice.push_back(dice[i]);
    }
    int depth = 5-ndice.size();
    return rec(ndice,depth);
  }
  double bestChoice(vector <int> dice) {
    double mx = 0;
    for (int i=0;i<(1<<5);i++) {
      mx = max(mx,reroll(dice,i));
    }
    return mx;
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
		cout << "Testing YahtzeeRoll (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398195386;
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
		YahtzeeRoll _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dice[] = { 1, 1, 1, 1, 2 };
				_expected = 8.333333333333334;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 1:
			{
				int dice[] = { 1, 1, 1, 2, 2 };
				_expected = 25.0;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 2:
			{
				int dice[] = { 2, 3, 4, 5, 5 };
				_expected = 33.333333333333336;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 3:
			{
				int dice[] = { 2, 2, 3, 4, 4 };
				_expected = 17.77777777777778;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 4:
			{
				int dice[] = { 6, 1, 3, 5, 5 };
				_expected = 9.722222222222221;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			/*case 5:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.bestChoice(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
