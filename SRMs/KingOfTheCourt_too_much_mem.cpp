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
// start: 16:15
// done: 17:01
// END CUT HERE
const int MAX_STEPS = 300;
double mem[5041][7][MAX_STEPS+1];
bool seen[5041][7][MAX_STEPS+1];

class KingOfTheCourt {
 public:
  vector<int> ability;
  int factor;
  double chancewin;
  map<int,int> permut_to_num;
  vector<int> num_to_permut;
  double rec(int state, int consecwins, int steps) {
    double& r = mem[state][consecwins][steps];
    if (seen[state][consecwins][steps]) return r;
    
    int permut = num_to_permut[state];
    int king  = permut%10;
    if (steps == MAX_STEPS) {
      return r = chancewin;
      seen[state][consecwins][steps] = 1;
      for (int step = 0;step < steps;step++)
        if (seen[state][consecwins][step]) {
          return r = mem[state][consecwins][step];
        }
      return r = chancewin;
    }
    
    if (consecwins == ability.size()-1) {
      seen[state][consecwins][steps] = 1;
      return r = king == 0;
    }
    int nextplayer = (permut/10)%10;
    // king wins
    int nextpermut = king + (permut/10 - (permut/10)%10) + factor*nextplayer;
    int nextstate = permut_to_num[nextpermut];
    double problose = double(ability[nextplayer])/(ability[king]+ability[nextplayer]);
    problose = problose*problose;
    
    r = 0;
    r += (1-problose)*rec(nextstate,consecwins+1,steps+1);
    // king loses
    nextpermut = nextplayer + (permut/10 - (permut/10)%10) + factor*king;
    nextstate = permut_to_num[nextpermut];
    r += problose*rec(nextstate,0,steps+1);
    seen[state][consecwins][steps] = 1;
    return r;
  }
  int to_permutation(const vector<int>& p) {
    int state = 0;
    int base = 1;
    for (int i=0;i<p.size();i++) {
      state += p[i]*base;
      base *= 10;
    }
    return state;
  }
  double chancesOfWinning(vector <int> ability) {
    this->ability = ability;
    memset(seen,0,sizeof(seen));
    chancewin = double(ability[0])/accumulate(ability.begin(),ability.end(),0);
    factor = pow(10,ability.size()-1);
    num_to_permut.clear();
    permut_to_num.clear();
    vector<int> p;
    for (int i=0;i<ability.size();i++)
      p.push_back(i);
    int c = 0;
    do {
      int permut = to_permutation(p);
      num_to_permut.push_back(permut);
      permut_to_num[permut] = c;
      ++c;
    } while (next_permutation(p.begin(),p.end()));
    return rec(0,0,0);
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
		cout << "Testing KingOfTheCourt (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400681724;
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
		KingOfTheCourt _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ability[] = { 1, 1 };
				_expected = 0.8;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 1:
			{
				int ability[] = { 2, 1 };
				_expected = 0.9350649350649349;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 2:
			{
				int ability[] = { 1, 2 };
				_expected = 0.5844155844155844;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 3:
			{
				int ability[] = { 1, 1, 1, 1 };
				_expected = 0.5065812082824602;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 4:
			{
				int ability[] = { 47, 82, 65, 99, 2, 14, 9 };
				_expected = 0.22734781036506918;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 5:
			{
				int ability[] = {65, 49, 85, 99, 82, 75};
				_expected = 0.2258693317308275;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			case 6:
			{
				int ability[] = {72, 89, 91, 93, 94, 96, 99};
				_expected = 0.1403814777824161;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
			}
			/*case 7:
			{
				int ability[] = ;
				_expected = ;
				_received = _obj.chancesOfWinning(vector <int>(ability, ability+sizeof(ability)/sizeof(int))); break;
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
