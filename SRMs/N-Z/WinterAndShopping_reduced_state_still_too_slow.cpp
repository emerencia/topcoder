#include <string>
#include <iostream>
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
const int tt = -1 ;
// 
// END CUT HERE
const int kMod = 1e9+7;
int add[2][501];
const int kSize = 303;
int fact[kSize];
int inv[kSize];
long long pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % kMod;
    if (step & b) x = (long long)x * a % kMod;
    step >>= 1;
  }
  return x;
}
long long bico(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  int x = fact[n];
  int y = inv[k];
  int z = inv[n - k];
  return (long long)x * y % kMod * z % kMod;
}

class WinterAndShopping {
 public:
  int nl;
  int nr;
  vector<int> left;
  vector<int> right;
  vector<int> red;
  vector<int> green;
  vector<int> blue;
  vector<int> cl;
  vector<int> cr;
  vector<int> first;
  LL rec(int idx, int lr, int lg, int rr, int rg) {
    /*
    cout << idx << " "  <<
        lr << " "  <<
        lg << " "  <<
        lb << " "  <<
        rr << " "  <<
        rg << " "  <<
        rb << " "  << endl;
    */
    if (idx == 501) {
      return 1;
    }
    int lb = 0;
    if (add[0][idx] == -1 && cl[idx] != -1)
      lb = blue[cl[idx]]-(idx-first[cl[idx]]-(red[cl[idx]]-lr)-(green[cl[idx]]-lg));
    int rb = 0;
    if (add[1][idx] == -1 && cr[idx] != -1)
      rb = blue[cr[idx]]-(idx-first[cr[idx]]-(red[cr[idx]]-rr)-(green[cr[idx]]-rg));
    if (add[0][idx] != -1) {
      if (lr || lg || lb) return 0;
      lr += red[add[0][idx]];
      lg += green[add[0][idx]];
      lb += blue[add[0][idx]];
    }
    if (add[1][idx] != -1) {
      if (rr || rg || rb) return 0;
      rr += red[add[1][idx]];
      rg += green[add[1][idx]];
      rb += blue[add[1][idx]];
    }
    LL t = 0;
    if (cl[idx] != -1 && cr[idx] != -1) {
      if (lr && rr) (t+= rec(idx+1,lr-1,lg,rr-1,rg))%=kMod;
      if (lg && rg) (t+= rec(idx+1,lr,lg-1,rr,rg-1))%=kMod;
      if (lb && rb) (t+= rec(idx+1,lr,lg,rr,rg))%=kMod;
    } else if (cl[idx] != -1) {
      if (lr) (t+= rec(idx+1,lr-1,lg,rr,rg))%=kMod;
      if (lg) (t+= rec(idx+1,lr,lg-1,rr,rg))%=kMod;
      if (lb) (t+= rec(idx+1,lr,lg,rr,rg))%=kMod;
    } else if (cr[idx] != -1) {
      if (rr) (t+= rec(idx+1,lr,lg,rr-1,rg))%=kMod;
      if (rg) (t+= rec(idx+1,lr,lg,rr,rg-1))%=kMod;
      if (rb) (t+= rec(idx+1,lr,lg,rr,rg))%=kMod;
    } else {
      (t+=rec(idx+1,lr,lg,rr,rg))%=kMod;
    }
    return t;
  }
  int getNumber(vector <int> first, vector <int> red, vector <int> green, vector <int> blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->first = first;
    fact[0] = 1;
    for (int i = 1; i < kSize; i++) fact[i] = (long long)fact[i - 1] * i % kMod;
    inv[0] = 1;
    for (int i = 1; i < kSize; i++) inv[i] = pw(fact[i], kMod - 2);
    int n = first.size();
    vector<int> last;
    for (int i=0;i<n;i++)
      last.push_back(first[i]+red[i]+green[i]+blue[i]-1);
    left = vector<int>();
    right = vector<int>();
    int l = -1;
    int r = -1;
    memset(add,-1,sizeof(add));
    for (int i=0;i<=500;i++)
      for (int j=0;j<n;j++) {
        if (i < first[j] || i > last[j]) continue;
        if (l == j || r == j) continue;
        if (l == -1 || (i < first[l] || i > last[l])) {
          l = j;
          add[0][i] = j;
          left.push_back(j);
        } else {
          r = j;
          add[1][i] = j;
          right.push_back(j);
        }
      }
    cl = vector<int>(501,-1);
    for (int i=0;i<left.size();i++)
      for (int j=first[left[i]];j<=last[left[i]];j++)
        cl[j]=left[i];
    cr = vector<int>(501,-1);
    for (int i=0;i<right.size();i++)
      for (int j=first[right[i]];j<=last[right[i]];j++)
        cr[j]=right[i];
    return rec(0,0,0,0,0);
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
		cout << "Testing WinterAndShopping (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391303205;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WinterAndShopping _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int first[] = {1};
				int red[] = {1};
				int green[] = {1};
				int blue[] = {1};
				_expected = 6;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int first[] = {1};
				int red[] = {3};
				int green[] = {0};
				int blue[] = {0};
				_expected = 1;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int first[] = {1, 2};
				int red[] = {1, 1};
				int green[] = {1, 1};
				int blue[] = {1, 1};
				_expected = 6;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int first[] = {47, 47};
				int red[] = {1, 0};
				int green[] = {0, 1};
				int blue[] = {0, 0};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int first[] = {1, 100, 200};
				int red[] = {100, 1, 0};
				int green[] = {100, 3, 7};
				int blue[] = {100, 2, 4};
				_expected = 79290907;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 5:
			{
				int first[] = {1, 3};
				int red[] = {3, 4};
				int green[] = {4, 4};
				int blue[] = {2, 1};
				_expected = 840;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 6:
			{
				int first[] = {2, 1};
				int red[] = {100, 100};
				int green[] = {100, 100};
				int blue[] = {99, 100};
				_expected = 412784747;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 7:
			{ 
				int first[] = {1, 220, 150};
				int red[] = {70, 70, 50};
				int green[] = {70, 70, 50};
				int blue[] = {70, 70, 50};
				_expected = 291495139;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 8:
			{
				int first[] = {2, 2, 70, 159};
				int red[] = {100, 20, 21, 52};
				int green[] = {100, 20, 29, 45};
				int blue[] = {100, 22, 39, 30};
				_expected = 139586270;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 9:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 11:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
