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

class GroceryBagger {
 public:
  int minimumBags(int strength, vector <string> itemType) {
    map<string,int> weight;
    for (int i=0;i<itemType.size();i++)
      weight[itemType[i]]++;
    int bags = 0;
    for (map<string,int>::iterator i=weight.begin();i!=weight.end();i++)
      bags+= (i->second+strength-1)/strength;
    return bags;
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
		cout << "Testing GroceryBagger (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398195136;
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
		GroceryBagger _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int strength = 2;
				string itemType[] = {"DAIRY",
				                     "DAIRY",
				                     "PRODUCE",
				                     "PRODUCE",
				                     "PRODUCE",
				                     "MEAT"};
				_expected = 4;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}
			case 1:
			{
				int strength = 3;
				string itemType[] = {"DAIRY",
				                     "DAIRY",
				                     "PRODUCE",
				                     "PRODUCE",
				                     "PRODUCE",
				                     "MEAT"};
				_expected = 3;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}
			case 2:
			{
				int strength = 10;
				string itemType[] = {};
				_expected = 0;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}
			case 3:
			{
				int strength = 5;
				string itemType[] = {"CANNED",   "CANNED",  "PRODUCE",
				                     "DAIRY",    "MEAT",    "BREAD",
				                     "HOUSEHOLD","PRODUCE", "FROZEN",
				                     "PRODUCE", "DAIRY"};
				_expected = 7;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}
			case 4:
			{
				int strength = 2;
				string itemType[] = {"CANNED",   "CANNED",  "PRODUCE",
				                     "DAIRY",    "MEAT",    "BREAD",
				                     "HOUSEHOLD","PRODUCE", "FROZEN",
				                     "PRODUCE", "DAIRY"};
				_expected = 8;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}
			/*case 5:
			{
				int strength = ;
				string itemType[] = ;
				_expected = ;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int strength = ;
				string itemType[] = ;
				_expected = ;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int strength = ;
				string itemType[] = ;
				_expected = ;
				_received = _obj.minimumBags(strength, vector <string>(itemType, itemType+sizeof(itemType)/sizeof(string))); break;
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
