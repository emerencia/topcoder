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

class TheBlackJackDivOne {
 public:
  vector<int> deckcnt;
  int value(string card) {
    if (card[0] == 'A') return 11;
    if (card[0] == 'J' || card[0] == 'Q' || card[0] == 'K' || card[0] == 'T') return 10;
    return card[0]-'0';
  }
  string getcard(int idx) {
    char suits[] = {'C','D','H','S'};
    int suit = idx%4;
    string r(1,suits[suit]);
    int val = idx/4;
    if (val == 0) return 'A'+r;
    if (val == 9) return 'T'+r;
    if (val == 10) return 'J'+r;
    if (val == 11) return 'Q'+r;
    if (val == 12) return 'K'+r;
    return char('1'+val)+r;
  }
  double rec(int togo, int totdeckcnt) {
    if (togo <= 0) return 0;
    double r = 0;
    for (int i=0;i<12;i++) {
      if (!deckcnt[i]) continue;
      deckcnt[i]--;
      r+=(double(deckcnt[i]+1)/totdeckcnt)*(1+rec(togo-i,totdeckcnt-1));
      deckcnt[i]++;
    }
    return r;
  }
  double expected(vector <string> cards) {
    int curval = 0;
    int totdeckcnt = 0;
    deckcnt = vector<int>(12,0);
    for (int i=0;i<52;i++) {
      string card = getcard(i);
      bool foundcard = false;
      for (int i=0;i<cards.size();i++)
        if (cards[i] == card) {
          foundcard = true;
          break;
        }
      if (foundcard) {
        curval += value(card);
      } else {
        deckcnt[value(card)]++;
        totdeckcnt++;
      }
    }
    if (curval >= 21) return 0;
    return rec(21-curval, totdeckcnt);
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
		cout << "Testing TheBlackJackDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396661538;
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
		TheBlackJackDivOne _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cards[] = {"JS"};
				_expected = 2.105854341736695;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 1:
			{
				string cards[] = {"KD", "8S"};
				_expected = 1.08;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 2:
			{
				string cards[] = {"KD", "2S", "2C", "2D", "2H"};
				_expected = 1.0;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 3:
			{
				string cards[] = {"AS", "KS", "9S", "JC", "2D"};
				_expected = 0.0;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			/*case 4:
			{
				string cards[] = ;
				_expected = ;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string cards[] = ;
				_expected = ;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cards[] = ;
				_expected = ;
				_received = _obj.expected(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
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
