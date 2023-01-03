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

class QuizShow {
 public:
  int wager(vector <int> scores, int wager1, int wager2) {
    int mw = 0;
    int mc = -1;
    for (int l=0;l<=scores[0];l++) {
      int wc = 0;
      for (int i=0;i<2;i++) {
        int score1 = scores[1]+(2*i-1)*wager1;
        for (int j=0;j<2;j++) {
          int score2 = scores[2]+(2*j-1)*wager2;
          for (int k=0;k<2;k++) {
            int myscore = scores[0]+(2*k-1)*l;
            if (myscore > score1 && myscore > score2)
              wc++;
          }
        }
      }
      if (wc > mc) {
        mc = wc;
        mw = l;
      }
    }
    return mw;
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
		cout << "Testing QuizShow (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397246932;
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
		QuizShow _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = { 100, 100, 100 };
				int wager1 = 25;
				int wager2 = 75;
				_expected = 76;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 1:
			{
				int scores[] = { 10, 50, 60 };
				int wager1 = 30;
				int wager2 = 41;
				_expected = 0;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 2:
			{
				int scores[] = { 10, 50, 60 };
				int wager1 = 31;
				int wager2 = 41;
				_expected = 10;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 3:
			{
				int scores[] = { 2, 2, 12 };
				int wager1 = 0;
				int wager2 = 10;
				_expected = 1;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 4:
			{
				int scores[] = { 10000, 10000, 10000 };
				int wager1 = 9998;
				int wager2 = 9997;
				_expected = 9999;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			case 5:
			{
				int scores[] = { 5824, 4952, 6230 };
				int wager1 = 364;
				int wager2 = 287;
				_expected = 694;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}
			/*case 6:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}*/
			/*case 7:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
			}*/
			/*case 8:
			{
				int scores[] = ;
				int wager1 = ;
				int wager2 = ;
				_expected = ;
				_received = _obj.wager(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), wager1, wager2); break;
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
