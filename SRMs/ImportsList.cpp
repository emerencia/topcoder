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

class ImportsList {
 public:
  vector <int> importsCount(vector <string> requires) {
    int n = requires.size();
    vector<vector<int> > dist(n,vector<int>(n,0));
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (requires[i][j] == 'Y')
          dist[i][j] = 1;
    for (int k=0;k<n;k++)
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          if (dist[i][k] && dist[k][j])
            dist[i][j] = 2;
    vector<int> r;
    for (int i=0;i<n;i++) {
      int c = 0;
      for (int j=0;j<n;j++)
        c+=dist[i][j]==1;
      r.push_back(c);
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing ImportsList (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396389291;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ImportsList _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string requires[] = {"NNN"
				                    ,"NNN"
				                    ,"NNN"};
				int __expected[] = {0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}
			case 1:
			{
				string requires[] = {"NYYY"
				                    ,"NNYY"
				                    ,"NNNY"
				                    ,"NNNN"};
				int __expected[] = {1, 1, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}
			case 2:
			{
				string requires[] = {"NNNNY"
				                    ,"NNNNY"
				                    ,"YNNNY"
				                    ,"NNNNN"
				                    ,"NNNNN"};
				int __expected[] = {1, 1, 1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}
			case 3:
			{
				string requires[] = {"NYYNYNYYYNYYNYNN"
				                    ,"NNNNNNNNNNNNNNNN"
				                    ,"NNNNNNNNNNYNNNNN"
				                    ,"NNNNNNNNNYNNYNNN"
				                    ,"NYNNNNYNNNYYNNNN"
				                    ,"NYNNYNYNYNYYNNNN"
				                    ,"NNNNNNNNNNYNNNNN"
				                    ,"NNYNNNYNYNYNNNNN"
				                    ,"NNNNNNYNNNYNNNNN"
				                    ,"NNNNNNNNNNNNYNNN"
				                    ,"NNNNNNNNNNNNNNNN"
				                    ,"NNNNNNNNNNNNNNNN"
				                    ,"NNNNNNNNNNNNNNNN"
				                    ,"NNNNNNYNNNYNNNNN"
				                    ,"YYYYYNYYYYYYYYNY"
				                    ,"NYYYNNYNNYYNYYNN"};
				int __expected[] = {3, 0, 1, 1, 3, 2, 1, 2, 1, 1, 0, 0, 0, 1, 2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}
			/*case 4:
			{
				string requires[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string requires[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string requires[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.importsCount(vector <string>(requires, requires+sizeof(requires)/sizeof(string))); break;
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
