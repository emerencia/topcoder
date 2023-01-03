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

class PerfectPermutationHard {
 public:
  vector<int> parent(const vector<int>& child) {
    vector<int> parent(child.size(),-1);
    for (int i=0;i<child.size();i++)
      parent[child[i]] = (i+1<child.size() ? child[i+1] : child[0]);
    return parent;
  }
  vector <int> reorder(vector <int> P) {
    int n = P.size();
    vector<int> component(n,-1);
    int c = 0;
    for (int i=0;i<n;i++) {
      if (component[i] != -1) continue;
      int j = i;
      do {
        component[j] = c;
        j = P[j];
      } while(j != i);
      c++;
    }
    if (c == 1) return P;
    vector<int> todo;
    for (int i=0;i<c;i++)
      for (int j=0;j<component.size();j++)
        if (component[j] == i) {
          if (j > 0) todo.push_back(j);
          break;
        }
    todo.push_back(P[0]);
    vector<int> child;
    child.push_back(0);
    vector<int> used(todo.size(),false);
    int extra = 0;
    for (int i=0;i-extra<todo.size();i++) {
      int curi = (todo.back() < todo.front() ? todo.size()-1 : 0);
      if (i) {
        curi = 0;
        while (used[curi]) curi++;
      }
      used[curi] = true;
      int ncuri = todo[curi];
      if (ncuri) {
        child.push_back(ncuri);
        if (child.size() == P.size()) break;
      }
      while (P[ncuri] != todo[curi]) {
        if (P[ncuri]) {
          if (i == 0 && curi == todo.size()-1 && todo.front() < P[ncuri]) {
            used[curi] = false;
            todo[curi] = P[ncuri];
            extra = 1;
            break;
          }
          child.push_back(P[ncuri]);
          if (child.size() == P.size()) break;
        }
        ncuri = P[ncuri];
      }
    }
    return parent(child);
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
		cout << "Testing PerfectPermutationHard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395544595;
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
		PerfectPermutationHard _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P[] = {2, 0, 1};
				int __expected[] = {2, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 1:
			{
				int P[] = {4, 0, 5, 2, 1, 3};
				int __expected[] = {2, 0, 5, 4, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 2:
			{
				int P[] = {2, 7, 3, 0, 6, 4, 5, 1};
				int __expected[] = {1, 7, 3, 0, 6, 2, 5, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 3:
			{
				int P[] = {11, 8, 10, 1, 5, 4, 0, 7, 3, 9, 12, 6, 2};
				int __expected[] = {1, 8, 10, 2, 5, 7, 0, 9, 3, 11, 12, 6, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 4:
			{
				int P[] = {0, 1, 4, 2, 3, 5};
				int __expected[] = {1, 2, 4, 5, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 5:
			{
				int P[] = {0, 2, 6, 5, 7, 3, 1, 4};
				int __expected[] = {1, 2, 6, 5, 7, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 6:
			{
				int P[] = {1, 0, 7, 19, 10, 9, 23, 14, 21, 8, 13, 11, 6, 5, 18, 17, 3, 22, 2, 15, 20, 4, 16, 12};
				int __expected[] = {1, 2, 7, 19, 10, 9, 23, 14, 21, 8, 13, 20, 11, 5, 18, 17, 4, 22, 3, 15, 0, 6, 16, 12};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 7:
			{
				int P[] = {1, 3, 9, 6, 4, 7, 8, 5, 2, 0};
				int __expected[] = {1, 3, 9, 4, 5, 7, 8, 6, 2, 0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			/*case 8:
			{
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reorder(vector <int>(P, P+sizeof(P)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
