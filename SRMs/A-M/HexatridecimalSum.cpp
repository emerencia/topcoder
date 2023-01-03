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

class HexatridecimalSum {
 public:
  static char tochar(int val) {
    if (val <= 9) return '0'+val;
    return 'A'+val-10;
  }
  static int toint(char val) {
    if (val >= '0' && val <= '9') return val-'0';
    return val-'A'+10;
  }
  struct HexString {
    string s;
    HexString(string s) : s(s) {}
    bool operator<(const HexString& o) const {
      if (s.size() != o.s.size()) return s.size() < o.s.size();
      for (int i=0;i<s.size();i++)
        if (s[i] != o.s[i])
          return s[i] < o.s[i];
      return false;
    }
    void add(const string& o) {
      int maxlen = max(s.size(),o.size());
      string r;
      int carry = 0;
      for (int i=0;i<=maxlen;i++) {
        int curdig = carry;
        if (i < s.size()) curdig += toint(s[s.size()-i-1]);
        if (i < o.size()) curdig += toint(o[o.size()-i-1]);
        r=string(1,tochar(curdig%36))+r;
        carry = curdig/36;
      }
      while (carry) {
        r=string(1,tochar(carry%36))+r;
        carry/=36;
      }
      s = r;
    }
  };
  string maximizeSum(vector <string> numbers, int K) {
    int maxlen = 0;
    for (int i=0;i<numbers.size();i++)
      maxlen = max(maxlen,(int)numbers[i].size());
    vector<pair<HexString,int> > sums;
    for (int i=0;i<36;i++) {
      char replacechar = tochar(i);
      string cursum;
      int carry = 0;
      for (int j=0;j<=maxlen;j++) {
        int curdig = carry;
        for (int k=0;k<numbers.size();k++) {
          if (numbers[k].size() <= j) continue;
          if (numbers[k][numbers[k].size()-j-1] == replacechar)
            curdig += toint('Z');
          else
            curdig += toint(numbers[k][numbers[k].size()-j-1]);
        }
        cursum=string(1,tochar(curdig%36))+cursum;
        carry=curdig/36;
      }
      while (carry) {
        cursum=string(1,tochar(carry%36))+cursum;
        carry/=36;
      }
      sums.push_back(pair<HexString,int>(cursum,replacechar));
    }
    sort(sums.rbegin(),sums.rend());
    vector<int> convmap(256);
    for (int i=0;i<256;i++)
      convmap[i] = i;
    for (int i=0;i<K;i++)
      convmap[sums[i].second] = 'Z';
    vector<string> numbers2 = numbers;
    for (int i=0;i<numbers2.size();i++)
      for (int j=0;j<numbers2[i].size();j++)
        numbers2[i][j] = convmap[numbers2[i][j]];
    HexString s("");
    for (int i=0;i<numbers2.size();i++)
      s.add(numbers2[i]);
    int off = 0;
    while (off < s.s.size() && s.s[off] == '0') off++;
    return s.s.substr(off);
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
		cout << "Testing HexatridecimalSum (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394113887;
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
		HexatridecimalSum _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"HELLO"};
				int k = 2;
				_expected = "ZZLLO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 1:
			{
				string numbers[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
				int k = 5;
				_expected = "1100TC85";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 2:
			{
				string numbers[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
				int k = 0;
				_expected = "QNO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 3:
			{
				string numbers[] = {"KEQUALS36"};
				int k = 36;
				_expected = "ZZZZZZZZZ";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 4:
			{
				string numbers[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
				int k = 7;
				_expected = "31YUB";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			/*case 5:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
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
