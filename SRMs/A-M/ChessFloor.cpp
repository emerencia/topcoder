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

class ChessFloor {
 public:
  int minimumChanges(vector <string> floor) {
    set<char> thingies;
    for (int i =0;i<floor.size();i++)
      for (int j = 0;j<floor[i].size();j++)
        thingies.insert(floor[i][j]);
    if (thingies.size() == 1)
      return (floor.size() * floor.size())/2;
    vector<char> thingiez(thingies.begin(),thingies.end());
    int r = INT_MAX;
    for (int k = 0;k<thingiez.size();k++) {
      char first = thingiez[k];
      for (int l = 0; l < thingiez.size(); l++) {
        if (k == l) continue;
        char second = thingiez[l];
        int t = 0;
        for (int i = 0; i < floor.size(); i++)
          for (int j = 0;j < floor[i].size();j++) {
            if ((i+j)%2 && floor[i][j] != first) t++;
            if (!((i+j)%2) && floor[i][j] != second) t++;
          }
        r = min(r,t);
      }
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
		cout << "Testing ChessFloor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438441666;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChessFloor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string floor[] = {"aba",
				                  "bbb",
				                  "aba"};
				_expected = 1;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}
			case 1:
			{
				string floor[] = {"wbwbwbwb",
				                  "bwbwbwbw",
				                  "wbwbwbwb",
				                  "bwbwbwbw",
				                  "wbwbwbwb",
				                  "bwbwbwbw",
				                  "wbwbwbwb",
				                  "bwbwbwbw"}
				                  ;
				_expected = 0;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}
			case 2:
			{
				string floor[] = {"zz",
				                  "zz"};
				_expected = 2;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}
			case 3:
			{
				string floor[] = {"helloand",
				                  "welcomet",
				                  "osingler",
				                  "oundmatc",
				                  "hsixhund",
				                  "redandsi",
				                  "xtythree",
				                  "goodluck"};
				_expected = 56;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}
			case 4:
			{
				string floor[] = {"jecjxsengslsmeijrmcx",
				                  "tcfyhumjcvgkafhhffed",
				                  "icmgxrlalmhnwwdhqerc",
				                  "xzrhzbgjgabanfxgabed",
				                  "fpcooilmwqixfagfojjq",
				                  "xzrzztidmchxrvrsszii",
				                  "swnwnrchxujxsknuqdkg",
				                  "rnvzvcxrukeidojlakcy",
				                  "kbagitjdrxawtnykrivw",
				                  "towgkjctgelhpomvywyb",
				                  "ucgqrhqntqvncargnhhv",
				                  "mhvwsgvfqgfxktzobetn",
				                  "fabxcmzbbyblxxmjcaib",
				                  "wpiwnrdqdixharhjeqwt",
				                  "xfgulejzvfgvkkuyngdn",
				                  "kedsalkounuaudmyqggb",
				                  "gvleogefcsxfkyiraabn",
				                  "tssjsmhzozbcsqqbebqw",
				                  "ksbfjoirwlmnoyyqpbvm",
				                  "phzsdodppzfjjmzocnge"};
				_expected = 376;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}
			/*case 5:
			{
				string floor[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string floor[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string floor[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <string>(floor, floor+sizeof(floor)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
