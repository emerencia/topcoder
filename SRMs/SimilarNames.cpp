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
typedef pair<int,vector<int> > PIV;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int kMod = 1e9+7;
int parent[51];
int comb[51][51];
map<PIV,LL> mem;

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

class SimilarNames {
 public:
  int n;
  vector<int> remembered;
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  long long rec(int idx, vector<int>& current) {
    if (idx == remembered.size())
      return 1;
    if (mem.count(PIV(idx,current))) return mem[PIV(idx,current)];
    long long r = 0;
    for (int i=0;i<current.size();i++)
      if (current[i] >= remembered[idx]) {
        LL fac = comb[current[i]][remembered[idx]];
        current[i]-=remembered[idx];
        (r+=(fac*rec(idx+1,current))%kMod)%=kMod;
        current[i]+=remembered[idx];
      }
    return mem[PIV(idx,current)] = r;
  }
  vector<int> componentinfo(set<int> connected) {
    vector<int> counts(n,0);
    vector<int> components;
    for (set<int>::iterator i=connected.begin();i!=connected.end();i++)
      counts[find(*i)]++;
    for (int i=0;i<counts.size();i++)
      if (counts[i])
        components.push_back(counts[i]);
    sort(components.begin(),components.end());
    return components;
  }
  int count(vector <string> names, vector <int> info1, vector <int> info2) {
    mem.clear();
    for (int i=0;i<=50;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%kMod;
    }
    n = names.size();
    
    // remembered components
    reset(n);
    set<int> connected;
    for (int i=0;i<info1.size();i++) {
      merge(info1[i],info2[i]);
      connected.insert(info1[i]);
      connected.insert(info2[i]);
    }
    vector<int> remembered = componentinfo(connected);
    
    // names
    sort(names.begin(),names.end());
    reset(n);
    connected.clear();
    for (int i=0;i<names.size();i++)
      for (int j=i+1;j<names.size();j++)
        if (names[j].substr(0,names[i].size()) == names[i]) {
          merge(i,j);
          connected.insert(i);
          connected.insert(j);
        }
    vector<int> current = componentinfo(connected);
    
    cout << endl << "remembered components: " << remembered.size() << endl;
    for (int i=0;i<remembered.size();i++)
      cout << remembered[i] << endl;
    cout << "found components: " << current.size() << endl;
    for (int i=0;i<current.size();i++)
      cout << current[i] << endl;
    
    int currentcons = accumulate(current.begin(),current.end(),0);
    int rememberedcons = accumulate(remembered.begin(),remembered.end(),0);
    if (currentcons < rememberedcons)
      return 0; // more connections
    
    if (remembered.size() && current.size() && current.back() < remembered.back())
      return 0; // remembering larger component than there actually is
    
    this->remembered = remembered;
    long long r = rec(0,current);
    cout << "unconnected: " << n-rememberedcons << endl;
    if (n-rememberedcons > 0)
      (r*=factorial(n-rememberedcons))%=kMod;
    
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
		cout << "Testing SimilarNames (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390682815;
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
		SimilarNames _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = {"kenta", "kentaro", "ken"};
				int info1[] = {0};
				int info2[] = {1};
				_expected = 3;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 1:
			{
				string names[] = {"hideo", "hideto", "hideki", "hide"};
				int info1[] = {0, 0};
				int info2[] = {1, 2};
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 2:
			{
				string names[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
				int info1[] = {0, 1, 3, 5};
				int info2[] = {1, 2, 4, 6};
				_expected = 2;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 3:
			{
				string names[] = {"taro", "jiro", "hanako"};
				int info1[] = {0, 1};
				int info2[] = {1, 0};
				_expected = 0;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 4:
			{
				string names[] = {"alice", "bob", "charlie"};
				int info1[] = {};
				int info2[] = {};
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 5:
			{
				string names[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
				                  "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
				int info1[] = {17, 5, 6, 13, 5};
				int info2[] = {9, 2, 14, 17, 14};
				_expected = 994456648;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			/*case 6:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
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
