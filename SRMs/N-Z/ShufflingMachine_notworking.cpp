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

class ShufflingMachine {
 public:
  double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K) {
    int N = shuffle.size();
    vector<int> component(N,-1);
    vector<int> compsizes;
    int c = 0;
    for (int i=0;i<N;i++) {
      if (component[i] != -1) continue;
      int orig = i;
      int cur = orig;
      component[cur] = c;
      int d = 1;
      while (shuffle[cur] != orig) {
        cur = shuffle[cur];
        component[cur] = c;
        ++d;
      }
      compsizes.push_back(d);
      c++;
    }
    int cardtot = 0;
    for (int i=1;i<=maxShuffles;i++) {
      int c = 0;
      for (int j=0;j<compsizes.size();j++)
        if (i%compsizes[j] == 0)
          c++;
      c = min(min((int)cardsReceived.size(),K),c);
      cardtot+=c;
    }
    return (double)cardtot/maxShuffles;
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
		cout << "Testing ShufflingMachine (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393010440;
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
		ShufflingMachine _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int shuffle[] = {1,0};
				int maxShuffles = 3;
				int cardsReceived[] = {0};
				int K = 1;
				_expected = 0.6666666666666666;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}
			case 1:
			{
				int shuffle[] = {1,2,0};
				int maxShuffles = 5;
				int cardsReceived[] = {0};
				int K = 2;
				_expected = 0.8;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}
			case 2:
			{
				int shuffle[] = {1,2,0,4,3};
				int maxShuffles = 7;
				int cardsReceived[] = {0,3};
				int K = 2;
				_expected = 1.0;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}
			case 3:
			{
				int shuffle[] = {0,4,3,5,2,6,1};
				int maxShuffles = 19;
				int cardsReceived[] = {1,3,5};
				int K = 2;
				_expected = 1.0526315789473684;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}
			case 4:
			{
				int shuffle[] = {3,4,7,2,8,5,6,1,0,9};
				int maxShuffles = 47;
				int cardsReceived[] = {6,3,5,2,8,7,4};
				int K = 8;
				_expected = 6.297872340425532;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int shuffle[] = ;
				int maxShuffles = ;
				int cardsReceived[] = ;
				int K = ;
				_expected = ;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int shuffle[] = ;
				int maxShuffles = ;
				int cardsReceived[] = ;
				int K = ;
				_expected = ;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int shuffle[] = ;
				int maxShuffles = ;
				int cardsReceived[] = ;
				int K = ;
				_expected = ;
				_received = _obj.stackDeck(vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int)), maxShuffles, vector <int>(cardsReceived, cardsReceived+sizeof(cardsReceived)/sizeof(int)), K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
