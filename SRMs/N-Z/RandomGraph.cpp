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
double mem[51][51][51][51];

class RandomGraph {
 public:
  double p;
  double rec(int idx, int a, int b, int c) {
    double& r = mem[idx][a][b][c];
    if (abs(r+1) > 1e-6) return r;
    if (idx == 0) return r = 1.0;
    double t = 0;
    t += pow(1 - p,a + 2*b + 3*c) * rec(idx - 1,a + 1, b, c);
    if (a > 0)
      t += p * a * pow(1-p,a-1 + 2*b + 3*c) * rec(idx - 1,a - 1, b + 1, c);
    if (a > 1)
      t += p*p*(a*(a-1)/2)*pow(1-p,a-2 + 2*b + 3*c) * rec(idx - 1, a - 2, b, c + 1);
    if (b > 0) {
      t += p * 2*b * pow(1-p,a + 2*b -1 + 3*c) * rec(idx - 1,a,b - 1, c + 1);
      t += p*p *b * pow(1-p,a + 2*b -2 + 3*c) * rec(idx - 1,a,b - 1, c + 1);
    }
    return r = t;
  }
  double probability(int n, int p) {
    this->p = p/1000.0;
    fill(&mem[0][0][0][0],&mem[51][0][0][0],-1);
    return 1 - rec(n,0,0,0);
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
		cout << "Testing RandomGraph (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437240956;
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
		RandomGraph _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int p = 0;
				_expected = 0.0;
				_received = _obj.probability(n, p); break;
			}
			case 1:
			{
				int n = 3;
				int p = 620;
				_expected = 0.0;
				_received = _obj.probability(n, p); break;
			}
			case 2:
			{
				int n = 4;
				int p = 500;
				_expected = 0.59375;
				_received = _obj.probability(n, p); break;
			}
			case 3:
			{
				int n = 8;
				int p = 100;
				_expected = 0.33566851611343496;
				_received = _obj.probability(n, p); break;
			}
			case 4:
			{
				int n = 15;
				int p = 50;
				_expected = 0.5686761670525845;
				_received = _obj.probability(n, p); break;
			}
			case 5:
			{
				int n = 50;
				int p = 10;
				_expected = 0.7494276522159893;
				_received = _obj.probability(n, p); break;
			}
			case 6:
			{
				int n = 50;
				int p = 1000;
				_expected = 1.0;
				_received = _obj.probability(n, p); break;
			}
			/*case 7:
			{
				int n = ;
				int p = ;
				_expected = ;
				_received = _obj.probability(n, p); break;
			}*/
			/*case 8:
			{
				int n = ;
				int p = ;
				_expected = ;
				_received = _obj.probability(n, p); break;
			}*/
			/*case 9:
			{
				int n = ;
				int p = ;
				_expected = ;
				_received = _obj.probability(n, p); break;
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
