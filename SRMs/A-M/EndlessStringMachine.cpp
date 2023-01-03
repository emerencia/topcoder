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

class EndlessStringMachine {
 public:
  string input;
  string program;
  vector<LL> sizes;
  string repeated;
  char getSimple(int s, int i) {
    if (i > input.size()+(LL)s*repeated.size()) return '-';
    if (i <= input.size()) return input[i-1];
    return repeated[(i-input.size()-1)%repeated.size()];
  }
  char getHard(int i, int s) {
    if (i >= sizes[s]) return '-';
    if (s == 0) {
      if (i < input.size()) return input[i];
      return '!';
    }
    for (int j=0;j<program.size();j++) {
      if (program[j] == '$') {
        if (i >= sizes[s-1])
          i-=sizes[s-1];
        else
          return getHard(i,s-1);
      } else {
        if (i == 0) return program[j];
        i--;
      }
    }
    return '?';
  }
  string getFragment(string input, string program, int s, int min, int max) {
    this->input = input;
    this->program = program;
    int numsign = 0;
    for (int i=0;i<program.size();i++)
      numsign+= program[i] == '$';
    if (numsign == 1) {
      repeated = program.substr(1);
      string r;
      for (int i=min;i<=max;i++)
        r+=getSimple(s,i);
      return r;
    }
    sizes.clear();
    LL cursize = input.size();
    sizes.push_back(cursize);
    while (cursize < max && sizes.size() <= s) {
      cursize = cursize*numsign + program.size()-numsign;
      sizes.push_back(cursize);
    }
    string r;
    for (int i=min;i<=max;i++)
      r+=getHard(i-1,sizes.size()-1);
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
		cout << "Testing EndlessStringMachine (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394914338;
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
		EndlessStringMachine _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string input = "a";
				string program = "$meric$";
				int s = 6;
				int min = 1;
				int max = 35;
				_expected = "americamericamericamericamericameri";
				_received = _obj.getFragment(input, program, s, min, max); break;
			}
			case 1:
			{
				string input = "top";
				string program = "$coder";
				int s = 1;
				int min = 1;
				int max = 20;
				_expected = "topcoder------------";
				_received = _obj.getFragment(input, program, s, min, max); break;
			}
			case 2:
			{
				string input = "abc";
				string program = "$x$y$z$";
				int s = 10;
				int min = 30;
				int max = 50;
				_expected = "bcyabcxabcyabczabczab";
				_received = _obj.getFragment(input, program, s, min, max); break;
			}
			case 3:
			{
				string input = "xy";
				string program = "$a$bb";
				int s = 12;
				int min = 5000;
				int max = 5099;
				_expected = "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb";
				_received = _obj.getFragment(input, program, s, min, max); break;
			}
			/*case 4:
			{
				string input = ;
				string program = ;
				int s = ;
				int min = ;
				int max = ;
				_expected = ;
				_received = _obj.getFragment(input, program, s, min, max); break;
			}*/
			/*case 5:
			{
				string input = ;
				string program = ;
				int s = ;
				int min = ;
				int max = ;
				_expected = ;
				_received = _obj.getFragment(input, program, s, min, max); break;
			}*/
			/*case 6:
			{
				string input = ;
				string program = ;
				int s = ;
				int min = ;
				int max = ;
				_expected = ;
				_received = _obj.getFragment(input, program, s, min, max); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
