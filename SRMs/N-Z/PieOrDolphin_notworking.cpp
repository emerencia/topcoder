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

class PieOrDolphin {
 public:
  vector <int> Distribute(vector <int> choice1, vector <int> choice2) {
    vector<vector<vector<int> > > g = vector<vector<vector<int> > >(50, vector<vector<int> >(50));
    vector<int> degree(50,0);
    for (int i = 0;i<choice1.size();i++) {
      if (choice1[i] < choice2[i])
        swap(choice1[i],choice2[i]);
      g[choice1[i]][choice2[i]].push_back(i);
      degree[choice1[i]]++;
      degree[choice2[i]]++;
    }
    vector<int> r(choice1.size(),1);
    for (int i = 0;i<50;i++)
      for (int j = 0;j<i;j++)
        for (int k = 0;k+1 < g[i][j].size();k+=2) {
          r[k] = 2;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing PieOrDolphin (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433943166;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PieOrDolphin _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int choice1[] = {10, 20, 10};
				int choice2[] = {20, 30, 20};
				int __expected[] = {2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 1:
			{
				int choice1[] = {0, 0};
				int choice2[] = {1, 1};
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 2:
			{
				int choice1[] = {0, 1, 2, 3, 5, 6, 7, 8};
				int choice2[] = {8, 7, 6, 5, 3, 2, 1, 0};
				int __expected[] = {2, 2, 2, 2, 2, 2, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 3:
			{
				int choice1[] = {49, 0, 48, 1};
				int choice2[] = {3, 4, 5, 6};
				int __expected[] = {2, 2, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 4:
			{
				int choice1[] = {21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
				                34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6};
				int choice2[] = {25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
				                7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39};
				int __expected[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
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
