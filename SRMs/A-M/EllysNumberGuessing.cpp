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

class EllysNumberGuessing {
 public:
  int getNumber(vector <int> guesses, vector <int> answers) {
    set<int> possibilities;
    for (int i=0;i<guesses.size();i++) {
      vector<int> valids;
      int a1 = guesses[i]+answers[i];
      if (a1 >= 1 && a1 <= 1000000000) valids.push_back(a1);
      int a2 = guesses[i]-answers[i];
      if (a2 >= 1 && a2 <= 1000000000) valids.push_back(a2);
      if (i == 0) {
        for (int j=0;j< valids.size();j++)
          possibilities.insert(valids[j]);
      } else {
        set<int> newpossibilities;
        for (set<int>::iterator j = possibilities.begin(); j !=possibilities.end(); j++) {
          bool found = false;
          for (int k=0;k< valids.size();k++)
            if (*j == valids[k]) {
              found = true;
              break;
            }
          if (found) newpossibilities.insert(*j);
        }
        possibilities = newpossibilities;
      }
    }
    if (possibilities.size() == 0) return -2;
    if (possibilities.size() > 1) return -1;
    return *possibilities.begin();
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
		cout << "Testing EllysNumberGuessing (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410264634;
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
		EllysNumberGuessing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int guesses[] = {600, 594};
				int answers[] = {6, 12};
				_expected = 606;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 1:
			{
				int guesses[] = {100, 50, 34, 40};
				int answers[] = {58, 8, 8, 2};
				_expected = 42;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 2:
			{
				int guesses[] = {500000, 600000, 700000};
				int answers[] = {120013, 220013, 79987};
				_expected = -2;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 3:
			{
				int guesses[] = {500000000};
				int answers[] = {133742666};
				_expected = -1;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 4:
			{
				int guesses[] = {76938260, 523164588, 14196746, 296286419, 535893832,
				                 41243148, 364561227, 270003278, 472017422, 367932361,
				                 395758413, 301278456, 186276934, 316343129, 336557549,
				                 52536121, 98343562, 356769915, 89249181, 335191879};
				int answers[] = {466274085, 20047757, 529015599, 246925926, 7318513,
				                 501969197, 178651118, 273209067, 71194923, 175279984,
				                 147453932, 241933889, 356935411, 226869216, 206654796,
				                 490676224, 444868783, 186442430, 453963164, 208020466};
				_expected = 543212345;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 5:
			{
				int guesses[] = {42};
				int answers[] = {42};
				_expected = 84;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			case 6:
			{
				int guesses[] = {999900000};
				int answers[] = {100001};
				_expected = 999799999;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}
			/*case 7:
			{
				int guesses[] = ;
				int answers[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int guesses[] = ;
				int answers[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int guesses[] = ;
				int answers[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(guesses, guesses+sizeof(guesses)/sizeof(int)), vector <int>(answers, answers+sizeof(answers)/sizeof(int))); break;
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
