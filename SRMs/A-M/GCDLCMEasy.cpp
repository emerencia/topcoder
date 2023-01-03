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
// start at 13:49
// done first at 14:30
// END CUT HERE

int parent[501];
void reset(int n) {
  for (int i=0;i<=n;i++)
    parent[i]=i;
}
int find(int u) {
  if (u==parent[u])
    return u;
  else
    return parent[u]=find(parent[u]);
}
void merge(int a,int b) {
  int pa=find(a);
  int pb=find(b);
  if (pa != pb)
    parent[pa]=pb;
}
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b,a%b);
}
int lcm(int a, int b) {
  return a/gcd(a,b)*b;
}

int mem[501];

class GCDLCMEasy {
 public:
  vector<int> G,L;
  map<int,vector<int> > components;
  map<PII,int> neighboridx;
  vector<set<int> > neighbors;
  bool dfs(int node, int value) {
    if (mem[node] == -1) {
      mem[node] = value;
      bool r = true;
      for (set<int>::iterator i = neighbors[node].begin();i!=neighbors[node].end();i++) {
        int neighbornode = *i;
        int neighbori = neighboridx[PII(node,neighbornode)];
        int otherval = L[neighbori]*G[neighbori]/value;
        if (otherval == 0 || gcd(value,otherval) != G[neighbori] ||
            lcm(value,otherval) != L[neighbori]) return false;
        r &= dfs(neighbornode,otherval);
      }
      return r;
    }
    return mem[node] == value;
  }
  string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
    this->G = G;
    this->L = L;
    // determine sets of neighbors
    neighbors = vector<set<int> >(n,set<int>());
    neighboridx.clear();
    for (int i=0;i<A.size();i++) {
      neighbors[A[i]].insert(B[i]);
      neighbors[B[i]].insert(A[i]);
      if (L[i]%G[i]) return "Solution does not exist";
      if (neighboridx.count(PII(A[i],B[i])) &&
          (G[neighboridx[PII(A[i],B[i])]] != G[i] || L[neighboridx[PII(A[i],B[i])]] != L[i]))
        return "Solution does not exist";
      neighboridx[PII(A[i],B[i])] = i;
      if (neighboridx.count(PII(B[i],A[i])) &&
          (G[neighboridx[PII(B[i],A[i])]] != G[i] || L[neighboridx[PII(B[i],A[i])]] != L[i]))
        return "Solution does not exist";
      neighboridx[PII(B[i],A[i])] = i;
    }
    // disjoint set forests to determine connected components
    reset(n);
    for (int i=0;i<A.size();i++)
      merge(A[i],B[i]);
    components.clear();
    for (int i=0;i<n;i++) {
      int component = find(i);
      if (!components.count(component))
        components[component] = vector<int>();
      components[component].push_back(i);
    }
    // iterate over components, for each component try for one index all possible values
    // from 0 to 10000, see if we can find one that works
    bool invalid = false;
    for (map<int,vector<int> >::iterator i = components.begin();i!=components.end();i++) {
      int node = (i->second)[0];
      bool found = false;
      for (int j=1;j<=10000;j++) {
        memset(mem,-1,sizeof(mem));
        found = dfs(node,j);
        if (found) break;
      }
      if (!found) {
        invalid = true;
        break;
      }
    }
    return invalid ? "Solution does not exist" : "Solution exists";
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
		cout << "Testing GCDLCMEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1422121125;
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
		GCDLCMEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int A[] = {0,1,2,3};
				int B[] = {1,2,3,0};
				int G[] = {6,6,6,6};
				int L[] = {12,12,12,12};
				_expected = "Solution exists";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int A[] = {0,1,2,3,4};
				int B[] = {1,2,3,4,0};
				int G[] = {6,6,6,6,6};
				int L[] = {12,12,12,12,12};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int A[] = {0,0};
				int B[] = {1,1};
				int G[] = {123,123};
				int L[] = {456,789};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 2;
				int A[] = {0};
				int B[] = {1};
				int G[] = {1234};
				int L[] = {5678};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 6;
				int A[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
				int B[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
				int G[] = {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7};
				int L[] = {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105};
				_expected = "Solution exists";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 500;
				int A[] = {0};
				int B[] = {1};
				int G[] = {10000};
				int L[] = {10000};
				_expected = "Solution exists";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 331;
				int A[] = {194, 148, 6, 196, 231, 153, 196, 50, 120, 122, 119, 84, 258, 72, 29, 276, 179, 45, 322, 145, 184, 330, 262, 202, 138, 169, 145, 209, 32, 206, 270, 213, 115, 37, 43, 229, 312, 152, 270, 66, 151, 317, 296, 248, 228, 29, 214, 39, 158, 154, 148, 207, 128, 6, 43, 164, 254, 163, 244, 181, 64, 125, 210, 101, 86, 53, 4, 151, 261, 329, 252, 226, 118, 237, 234, 296, 83, 85, 79, 265, 257, 137, 99, 292, 308, 2, 253, 243, 154, 130, 64, 260, 108, 129, 307, 120, 148, 179, 201, 65, 316, 253, 13, 72, 233, 126, 142, 268, 75, 177, 8, 122, 14, 313, 33, 95, 110, 23, 104, 97, 330, 211, 161, 50, 34, 179, 229, 253, 222, 41, 253, 211, 295, 273, 60, 235, 211, 68, 95, 194, 147, 118, 308, 34, 263, 224, 151, 105, 261, 6, 23, 272, 83, 74, 198, 161, 32, 5, 196, 176, 66, 95, 281, 328, 181, 245, 81, 187, 265, 308, 7, 271, 77, 217, 124, 261, 12, 242, 157, 307, 3, 55, 274, 157, 201, 216, 3, 45, 127, 164, 268, 66, 263, 296, 235, 325, 125, 188, 254, 226, 109, 268, 283, 197, 138, 287, 91, 230};
				int B[] = {42, 92, 234, 190, 227, 309, 171, 60, 113, 91, 279, 244, 252, 312, 125, 138, 294, 236, 300, 302, 13, 154, 273, 103, 290, 2, 197, 286, 92, 249, 2, 205, 107, 115, 309, 188, 326, 159, 288, 62, 317, 234, 147, 226, 214, 203, 253, 139, 229, 231, 17, 162, 306, 311, 171, 222, 63, 67, 42, 98, 17, 176, 81, 326, 119, 110, 46, 80, 232, 128, 121, 308, 242, 267, 9, 218, 119, 264, 306, 321, 275, 111, 185, 155, 229, 239, 5, 268, 189, 325, 242, 178, 307, 55, 41, 270, 197, 175, 41, 17, 78, 185, 174, 118, 224, 295, 95, 301, 30, 39, 213, 62, 29, 148, 40, 26, 217, 78, 141, 277, 324, 143, 75, 323, 50, 281, 246, 320, 244, 109, 101, 283, 77, 269, 239, 247, 126, 73, 175, 53, 123, 91, 52, 81, 305, 52, 300, 302, 73, 19, 288, 262, 248, 189, 220, 30, 328, 8, 29, 115, 0, 203, 204, 330, 277, 153, 269, 296, 306, 180, 184, 210, 72, 150, 68, 265, 95, 35, 199, 25, 92, 82, 316, 67, 237, 297, 199, 283, 74, 211, 216, 122, 29, 251, 161, 110, 231, 111, 56, 27, 297, 41, 221, 19, 50, 118, 10, 7};
				int G[] = {2, 1, 8, 1, 1, 1, 1, 4, 3, 2, 1, 6, 4, 1, 3, 76, 1, 1, 3, 10, 1, 1, 1, 9, 4, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1, 2, 1, 5, 10, 6, 1, 7, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 11, 1, 1, 1, 1, 1, 6, 2, 1, 2, 6, 2, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 6, 1, 20, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 3, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 4, 2, 1, 1, 2, 1, 26, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 6, 2, 1, 3, 1, 1, 1, 5, 1, 1, 2, 1, 18, 50, 2, 1, 1, 3, 1, 1, 7, 4, 5, 1, 8, 1, 1, 3, 1, 1, 1, 1, 1, 4, 6, 2, 2, 6, 1, 20, 3, 2, 1, 1, 1, 3, 1, 31, 2, 2, 6, 1, 3, 4, 1, 2, 1, 1, 1, 1, 3, 1, 1, 3, 76, 2, 2, 1};
				int L[] = {2660, 252, 280, 1890, 42, 270, 280, 76, 18, 492, 3403, 96, 280, 979, 234, 76, 2343, 3100, 135, 2640, 3894, 2030, 5621, 90, 1824, 462, 66, 5369, 207, 744, 4774, 2581, 3995, 940, 2646, 1131, 55, 365, 620, 77, 350, 280, 1092, 90, 84, 468, 1533, 3904, 3666, 406, 1876, 94, 4410, 3416, 392, 8118, 5460, 639, 3360, 3416, 2010, 1248, 156, 220, 5229, 3038, 3515, 2475, 336, 1260, 1512, 77, 174, 72, 440, 252, 5976, 792, 637, 8170, 45, 4180, 4902, 76, 3003, 6314, 1533, 264, 2900, 20, 30, 962, 40, 1462, 20, 558, 84, 7029, 73, 1608, 24, 4161, 3234, 5162, 24, 266, 1136, 30, 4085, 1464, 2262, 902, 18, 308, 511, 272, 4900, 62, 312, 416, 1295, 78, 2709, 2660, 2052, 7100, 780, 5913, 3168, 33, 3212, 2418, 210, 3577, 164, 185, 1482, 7470, 1584, 2356, 1092, 348, 5467, 108, 1947, 213, 675, 1360, 3984, 840, 620, 1386, 360, 100, 92, 5985, 2139, 546, 630, 1504, 35, 208, 1100, 3255, 224, 165, 588, 1596, 4214, 4928, 3127, 780, 2670, 400, 1260, 2064, 432, 30, 255, 20, 117, 680, 1464, 1065, 1752, 198, 663, 31, 1050, 3198, 66, 574, 198, 1092, 315, 490, 273, 2755, 2860, 94, 99, 6, 1426, 30, 76, 2494, 12, 848};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			/*case 7:
			{
				int n = ;
				int A[] = ;
				int B[] = ;
				int G[] = ;
				int L[] = ;
				_expected = ;
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int A[] = ;
				int B[] = ;
				int G[] = ;
				int L[] = ;
				_expected = ;
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(G, G+sizeof(G)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
