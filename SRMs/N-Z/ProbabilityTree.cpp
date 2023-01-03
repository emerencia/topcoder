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
int g[51][51];
class ProbabilityTree {
 public:
  struct Node {
    int parent;
    double pa, pna;
    Node(int parent, int pa, int pna) : parent(parent) {
      this->pa = pa/100.0;
      this->pna = pna/100.0;
    }
  };
  int n;
  int lowerBound,upperBound;
  vector<Node> nodetree;
  vector<int> inbounds;
  void dfs(int node, double pa) {
    double pna = 1-pa;
    double npa = nodetree[node].pa*pa + nodetree[node].pna*pna;
    if (100*npa > lowerBound && 100*npa < upperBound)
      inbounds.push_back(node);
    for (int i=0;i<n;i++)
      if (g[node][i])
        dfs(i,npa);
  }
  vector <int> getOdds(vector <string> tree, int lowerBound, int upperBound) {
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    n = tree.size();
    nodetree.clear();
    inbounds.clear();
    memset(g,0,sizeof(g));
    stringstream a(tree[0]);
    int p;
    a >> p;
    nodetree.push_back(Node(-1,p,100-p));
    for (int i=1;i<tree.size();i++) {
      stringstream b(tree[i]);
      int q,s,t;
      b >> q >> s >> t;
      nodetree.push_back(Node(q,s,t));
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (nodetree[j].parent == i)
          g[i][j] = 1;
    dfs(0,1);
    sort(inbounds.begin(),inbounds.end());
    return inbounds;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing ProbabilityTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397741431;
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
		ProbabilityTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tree[] = {"40","0 70 10"};
				int lowerBound = 30;
				int upperBound = 50;
				int __expected[] = { 0,  1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 1:
			{
				string tree[] = {"20","2 50 50","0 50 50"};
				int lowerBound = 49;
				int upperBound = 51;
				int __expected[] = { 1,  2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 2:
			{
				string tree[] = {"10","0 99 41","1 40 3","2 91 43"};
				int lowerBound = 81;
				int upperBound = 88;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 3:
			{
				string tree[] = {"79","0 64 52","1 70 87","0 38 99","1 24 8"};
				int lowerBound = 47;
				int upperBound = 81;
				int __expected[] = { 0,  1,  2,  3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 4:
			{
				string tree[] = {"51",
				                 "29 58 3",
				                 "6 56 86",
				                 "18 97 1",
				                 "44 99 25",
				                 "33 69 90",
				                 "27 67 49",
				                 "32 15 19",
				                 "33 1 21",
				                 "45 12 33",
				                 "29 24 40",
				                 "45 86 74",
				                 "40 30 65",
				                 "0 18 27",
				                 "1 90 65",
				                 "0 47 62",
				                 "40 81 72",
				                 "42 25 56",
				                 "45 16 81",
				                 "8 94 92",
				                 "29 41 92",
				                 "24 4 29",
				                 "32 56 91",
				                 "20 16 77",
				                 "1 35 79",
				                 "45 77 61",
				                 "6 50 19",
				                 "20 69 43",
				                 "4 6 16",
				                 "15 55 26",
				                 "42 73 90",
				                 "40 8 49",
				                 "33 16 33",
				                 "15 95 47",
				                 "9 66 40",
				                 "25 80 39",
				                 "35 72 70",
				                 "27 10 36",
				                 "40 36 10",
				                 "32 2 48",
				                 "33 44 23",
				                 "22 51 45",
				                 "25 8 43",
				                 "18 32 96",
				                 "45 41 74",
				                 "0 51 6",
				                 "18 48 15"};
				int lowerBound = 8;
				int upperBound = 82;
				int __expected[] = { 0,  1,  2,  3,  4,  5,  6,  7,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  23,  24,  25,  26,  27,  28,  29,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 5:
			{
				string tree[] = {"98", "0 27 45", "1 87 65", "0 50 89", "2 20 98", "2 54 15", "5 88 60", "1 33 19", "0 36 27", "2 39 32", "7 1 33", "2 55 55", "0 64 72", "6 78 44", "7 16 33", "3 90 99", "12 31 54", "8 21 14", "16 48 53", "2 56 29", "5 44 40", "5 59 84", "10 37 48", "21 65 12", "16 86 37", "4 86 6", "20 27 39", "26 90 86", "21 79 85", "13 37 26", "29 83 35", "18 44 59", "6 5 4", "16 79 25", "29 86 18", "15 60 35", "32 63 15", "33 22 92", "29 46 77"};
				int lowerBound = 48;
				int upperBound = 82;
				int __expected[] = {2, 3, 6, 11, 12, 13, 18, 19, 21, 23, 24, 28, 30, 31, 35, 37, 38};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			case 6:
			{
				string tree[] = {"45", "0 22 7", "1 83 32", "1 7 67", "2 91 43", "1 11 31", "0 76 9", "6 7 94", "2 17 37", "5 5 49", "2 3 98", "10 70 13", "10 15 4", "6 22 50", "5 29 72", "9 34 77", "6 16 63", "10 31 48", "9 86 87", "0 19 43", "3 53 47", "16 42 1", "3 40 67", "1 70 18", "8 37 7", "5 95 93", "21 91 65", "2 36 78", "20 4 83", "22 47 21", "7 62 84", "23 99 68", "8 55 33", "19 38 54", "0 75 60", "5 80 45", "31 31 75", "1 33 78", "23 98 87", "8 55 14", "38 35 55", "33 78 68", "41 21 97", "13 81 93", "18 53 41"};
				int lowerBound = 52;
				int upperBound = 61;
				int __expected[] = {3, 7, 10, 14, 35};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
			}
			/*case 7:
			{
				string tree[] = ;
				int lowerBound = ;
				int upperBound = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOdds(vector <string>(tree, tree+sizeof(tree)/sizeof(string)), lowerBound, upperBound); break;
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
