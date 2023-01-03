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
// start thinking at 20:12
// start coding at 20:35
// end coding at 20:57
// END CUT HERE
const int kMod = 1e9+7;

class FoxConnection2 {
 public:
  int N;
  vector<int> A;
  vector<int> B;
  struct State {
    LL dontuse;
    int node, disttogo;
    State(LL dontuse, int node, int disttogo) :
      dontuse(dontuse), node(node), disttogo(disttogo) {}
    bool operator<(const State& o) const {
      if (dontuse != o.dontuse) return dontuse < o.dontuse;
      if (node != o.node) return node < o.node;
      return disttogo < o.disttogo;
    }
  };
  map<State,LL> mem;
  LL dfs(LL dontuse, int node, int disttogo) {
    State s(dontuse,node,disttogo);
    if (mem.count(s)) return mem[s];
    if (disttogo == 0) return mem[s] = 1;
    LL t = 0;
    for (int i=0;i<A.size();i++) {
      if (dontuse&(1LL<<i)) continue;
      if (A[i]-1 != node && B[i]-1 != node) continue;
      int other = (A[i]-1 == node ? B[i]-1 : A[i]-1);
      dontuse |= (1LL<<i);
      for (int usedhere=0;usedhere<disttogo;usedhere++) {
        (t+=(dfs(dontuse,node,usedhere)*
             dfs(dontuse,other,disttogo-usedhere-1))%kMod)%=kMod;
      }
    }
    return mem[s] = t;
  }
  int ways(vector <int> A, vector <int> B, int k) {
    N = A.size()+1;
    this->A = A;
    this->B = B;
    mem.clear();
    LL r = 0;
    LL dontuse = 0;
    if (k == 1) return N;
    for (int i=0;i<A.size();i++) {
      // exclude this edge
      dontuse |= (1LL<<i);
      for (int j=0;j+1<k;j++)
        (r+=(dfs(dontuse,A[i]-1,j)*dfs(dontuse,B[i]-1,k-j-2))%kMod)%=kMod;
    }
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing FoxConnection2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394219520;
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
		FoxConnection2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3};
				int B[] = {2,3,4};
				int k = 2;
				_expected = 3;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 1:
			{
				int A[] = {1,1,1,1};
				int B[] = {2,3,4,5};
				int k = 3;
				_expected = 6;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 2:
			{
				int A[] = {1,2,3,4};
				int B[] = {2,3,4,5};
				int k = 3;
				_expected = 3;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 3:
			{
				int A[] = {1,2,2,4,4};
				int B[] = {2,3,4,5,6};
				int k = 3;
				_expected = 6;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 4:
			{
				int A[] = {1,2,2,4,4};
				int B[] = {2,3,4,5,6};
				int k = 5;
				_expected = 4;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 5:
			{
				int A[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int B[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
				int k = 20;
				_expected = 923263934;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			case 6:
			{
				int A[] = {2};
				int B[] = {1};
				int k = 1;
				_expected = 2;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int k = ;
				_expected = ;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int k = ;
				_expected = ;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				int B[] = ;
				int k = ;
				_expected = ;
				_received = _obj.ways(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), k); break;
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
