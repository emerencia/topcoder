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
#include <tuple>
using namespace std;
typedef long long LL;
typedef tuple<int,int,int> State;
// BEGIN CUT HERE
const int tt = -1;
// start thinking at 20:12
// start coding at 20:35
// end coding at 20:57
// END CUT HERE
const int kMod = 1e9+7;
int mem[51][51][51];
int g[51][51];

class FoxConnection2 {
 public:
  int N;
  vector<int> A;
  vector<int> B;
  vector<int> degree;
  LL dfs(int node, int nodestogo, int edgeidx) {
    int& r = mem[node][nodestogo][edgeidx];
    if (r != -1) return r;
    if (nodestogo == 0) return r = 1;
    if (edgeidx == degree[node]) return r = (nodestogo == 1);
    LL t = 0;
    for (int i=0;i<nodestogo;i++)
      (t+=(dfs(g[node][edgeidx],i,0)*
           dfs(node,nodestogo-i,edgeidx+1))%kMod)%=kMod;
    return r = t;
  }
  void createdfstree(int node, int prev) {
    degree[node] = 0;
    for (int i=0;i<A.size();i++) {
      if (A[i]-1 != node && B[i]-1 != node) continue;
      int other = (A[i]-1 == node ? B[i]-1 : A[i]-1);
      if (other == prev) continue;
      g[node][degree[node]++] = other;
      createdfstree(other,node);
    }
  }
  int ways(vector <int> A, vector <int> B, int k) {
    N = A.size()+1;
    if (k == 1) return N;
    memset(mem,-1,sizeof(mem));
    degree = vector<int>(N,0);
    this->A = A;
    this->B = B;
    createdfstree(0,-1);
    LL r = 0;
    for (int i=0;i<N;i++)
      (r+=dfs(i,k,0))%=kMod;
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
