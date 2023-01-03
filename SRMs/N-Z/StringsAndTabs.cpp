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
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class StringsAndTabs {
 public:
  char pitchback(int n) {
    if (n < 10) return '0'+n;
    return 'A'+n-10;
  }
  int transformpitch(char c) {
    if (c >= 'A' && c <= 'Z')
      return c-'A'+10;
    return c-'0';
  }
  vector <string> transformTab(vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d) {
    vector<string> tabo(stringsB.size(),string(tab[0].size(),'x'));
    for (int i=0;i<tab[0].size();i++) {
      vector<int> notes;
      for (int j=0;j<tab.size();j++)
        if (tab[j][i] != '-')
          notes.push_back(transformpitch(tab[j][i])+d+stringsA[j]);
      sort(notes.rbegin(),notes.rend());
      string used(stringsB.size(),'-');
      bool good = true;
      for (int j=0;j<notes.size();j++) {
        int highestopen=-100;
        int highi=-1;
        char highp=0;
        for (int k=0;k<used.size();k++) {
          if (used[k] != '-') continue;
          if (stringsB[k] <= notes[j] && stringsB[k]+35 >= notes[j]) {
            if (stringsB[k] >= highestopen) {
              highestopen = stringsB[k];
              highi = k;
              highp = pitchback(notes[j]-stringsB[k]);
            }
          }
        }
        if (highi == -1) {
          good = false;
          break;
        }
        used[highi]=highp;
      }
      if (good)
        for (int j=0;j<stringsB.size();j++)
          tabo[j][i] = used[j];
    }
    return tabo;
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
		cout << "Testing StringsAndTabs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390228209;
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
		StringsAndTabs _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tab[] = {"-----------------",
				                "-------------0-1-",
				                "---------0-2-----",
				                "---0-2-3---------",
				                "-3---------------",
				                "-----------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {9};
				int d = 0;
				string __expected[] = {"-3-5-7-8-A-C-E-F-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 1:
			{
				string tab[] = {"-4457754-20024422-4457754-20024200-"};
				int stringsA[] = {0};
				int stringsB[] = {28,23,19,14,9,4};
				int d = 12;
				string __expected[] = {"-----------------------------------", "-----------------------------------", "----00---------------00------------", "-223--32-0--02200-223--32-0--020---", "----------33---------------33---33-", "-----------------------------------" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 2:
			{
				string tab[] = {"-----------------------------------",
				                "-----------------------------------",
				                "----00---------------00------------",
				                "-223--32-0--02200-223--32-0--020---",
				                "----------33---------------33---33-",
				                "-----------------------------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {33,28,24,31};
				int d = 12;
				string __expected[] = {"-----------------------------------", "-001--10-----00---001--10-----0----", "---------2002--22---------2002-200-", "----00---------------00------------" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 3:
			{
				string tab[] = {"-----0------2-2222--0-------0-",
				                "----0------2---222---5-----55-",
				                "---0------2-----22----9---999-",
				                "--0------2-------2-----E-EEEE-",
				                "-0------2---------------------",
				                "0------2----------------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {33,28,28};
				int d = 12;
				string __expected[] = {"xxx-27-xx-049-999x--7777-777x-", "xxx----xx-------5x---------Cx-", "xxx3---xx0-----99x--------CCx-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 4:
			{
				string tab[] = {"012345---------",
				                "---------UVWXYZ"};
				int stringsA[] = {-2,2};
				int stringsB[] = {0};
				int d = 0;
				string __expected[] = {"xx0123---WXYZxx" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 5:
			{
				string tab[] = {"0220----02--",
				                "75--75----57",
				                "------B9B9B9",
				                "--242424----"};
				int stringsA[] = {33,28,24,31};
				int stringsB[] = {33,28,28};
				int d = 0;
				string __expected[] = {"222222222222", "------------", "555555555555" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			/*case 6:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}*/
			/*case 7:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}*/
			/*case 8:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
