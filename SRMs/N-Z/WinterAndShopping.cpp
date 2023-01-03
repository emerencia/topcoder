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
const int tt = -1;
// 
// END CUT HERE
const int kMod = 1e9+7;
const int kSize = 303;

int fact[kSize];
int inv[kSize];
LL mem[502][101][101];

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
  vector<int> red;
  vector<int> green;
  vector<int> blue;
  vector<int> cl;
  vector<int> cr;
  vector<int> first;
  vector<int> last;
  LL rec(int idx, int lru, int lgu) {
    LL& r = mem[idx][lru][lgu];
    if (r != -1) return r;
    if (idx == 501) {
      return r=1;
    }
    if (cl[idx] == -1) return r=rec(idx+1,0,0);
    // we have at least the left store open
    // calc current values how many of each ball we have
    int lr = red[cl[idx]]-lru;
    int lg = green[cl[idx]]-lgu;
    int lb = blue[cl[idx]]-(idx-first[cl[idx]]-lru-lgu);
    LL t = 0;
    if (cr[idx] == -1) {
      // we only have the left store open
      // try all possibilities
      if (lr + lg + lb == 1) return r = rec(idx+1,0,0); // important! reset counts
      if (lr) (t+= rec(idx+1,lru+1,lgu))%=kMod;
      if (lg) (t+= rec(idx+1,lru,lgu+1))%=kMod;
      if (lb) (t+= rec(idx+1,lru,lgu))%=kMod;
    } else {
      // two stores open:
      // we know we haven't used anything from right store yet
      // (because we skip all those steps)
      int rr = red[cr[idx]];
      int rg = green[cr[idx]];
      int rb = blue[cr[idx]];
      if (last[cl[idx]] == last[cr[idx]]) {
        // if they close at the same time, all balls should be equal
        if (lr != rr || lg != rg || lb != rb) return r = 0;
        (t += (((bico(rr+rg+rb,rr)*bico(rg+rb,rg))%kMod)*
                 rec(last[cl[idx]]+1,0,0))%kMod)%=kMod;
      } else if (last[cl[idx]] < last[cr[idx]]) {
        // left store closes before right store
        // right store must have at least as many balls as left store
        if (rr < lr || rg < lg || rb < lb) return r = 0;
        (t += (((bico(lr+lg+lb,lr)*bico(lg+lb,lg))%kMod)*
                 rec(last[cl[idx]]+1,lr,lg))%kMod)%=kMod;
      } else {
        // right store closes before left store
        // left store must have at least as many balls as right store
        if (lr < rr || lg < rg || lb < rb) return r = 0;
        (t += (((bico(rr+rg+rb,rr)*bico(rg+rb,rg))%kMod)*
                 rec(last[cr[idx]]+1,lru+rr,lgu+rg))%kMod)%=kMod;
      }
    }
    return r = t;
  }
  int getNumber(vector <int> first, vector <int> red, vector <int> green, vector <int> blue) {
    memset(mem,-1,sizeof(mem));
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->first = first;
    fact[0] = 1;
    for (int i = 1; i < kSize; i++) fact[i] = (long long)fact[i - 1] * i % kMod;
    inv[0] = 1;
    for (int i = 1; i < kSize; i++) inv[i] = pw(fact[i], kMod - 2);
    int n = first.size();
    last.clear();
    for (int i=0;i<n;i++)
      last.push_back(first[i]+red[i]+green[i]+blue[i]-1);
    vector<int> left;
    vector<int> right;
    int l = -1;
    int r = -1;
    for (int i=0;i<=500;i++)
      for (int j=0;j<n;j++) {
        if (i < first[j] || i > last[j]) continue;
        if (l == j || r == j) continue;
        if (l == -1 || (i < first[l] || i > last[l])) {
          l = j;
          left.push_back(j);
        } else {
          r = j;
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
    // sort it so that store cl always opened before (or at the same time as) cr
    // so that when we are in rec, we know that
    // cl is the one that the lru and lgu counts belong to
    for (int i=0;i<501;i++) {
      if (cr[i] == -1) continue;
      if (cl[i] == -1) {
        swap(cl[i],cr[i]);
        continue;
      }
      if (first[cl[i]] > first[cr[i]])
        swap(cl[i],cr[i]);
    }
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
			case 9:
			{
				int first[] = {1, 50, 211, 270};
				int red[] = {70, 40, 70, 40};
				int green[] = {70, 40, 70, 50};
				int blue[] = {70, 40, 69, 67};
				_expected = 690498127;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
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
