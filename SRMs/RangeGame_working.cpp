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
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int MAX = 2e9;

int stringtonum(string s) {
  stringstream a(s);
  int r;
  a >> r;
  return r;
}

class RangeGame {
 public:
  struct Range {
    int start;
    int end;
    bool operator<(const Range& o) const {
      if (start != o.start) return start < o.start;
      return end < o.end;
    }
    bool matches(const Range& o) const {
      return max(start,o.start)  <= min(end,o.end);
    }
    Range overlap(const Range& o) const {
      return (Range){max(start,o.start),min(end,o.end)};
    }
  };
  struct Pattern {
    vector<Range> ranges;
    Pattern() { }
    Pattern(string s) {
      stringstream a(s);
      while (!a.eof()) {
        string r;
        a >> r;
        if (r.find('-') == string::npos) {
          int num = stringtonum(r);
          ranges.push_back((Range){num,num});
          continue;
        }
        int num1 = stringtonum(r.substr(0,r.find('-')));
        int num2 = stringtonum(r.substr(r.find('-')+1));
        ranges.push_back((Range){num1,num2});
      }
    }
    int first() const {
      if (!ranges.size()) return MAX+1;
      return ranges[0].start;
    }
    Pattern intersect(const Pattern& o) const {
      if (ranges.size() == 0) return o;
      if (o.ranges.size() == 0) return *this;
      Pattern r;
      for (int i=0;i<ranges.size();i++)
        for (int j=0;j<o.ranges.size();j++)
          if (ranges[i].matches(o.ranges[j]))
            r.ranges.push_back(ranges[i].overlap(o.ranges[j]));
      // remove subsumes for ranges?
      sort(r.ranges.begin(),r.ranges.end());
      return r;
    }
    bool matches(const Pattern& o) const {
      Pattern r = intersect(o);
      return r.ranges.size() != 0;
    }
    bool operator<(const Pattern& o) const {
      return first() > o.first();
    }
  };
  typedef pair<int,Pattern> PIP;
  PIP rec(int idx, const vector<Pattern>& patterns, Pattern cur) {
    if (idx == patterns.size()) return PIP(0,cur);
    PIP r = rec(idx+1,patterns,cur);
    if (patterns[idx].matches(cur)) {
      PIP r2 = rec(idx+1,patterns,patterns[idx].intersect(cur));
      r = max(r,PIP(1+r2.first,r2.second));
    }
    return r;
  }
  int most_likely(const vector<Pattern>& patterns) {
    Pattern a;
    PIP r = rec(0,patterns,a);
    return r.second.first();
  }
  vector <int> bestDoors(vector <string> possible, vector <string> hints) {
    vector<Pattern> patterns;
    for (int i=0;i<possible.size();i++)
      patterns.push_back(Pattern(possible[i]));
    vector<int> r;
    r.push_back(most_likely(patterns));
    for (int i=0;i<hints.size();i++) {
      Pattern hint(hints[i]);
      vector<Pattern> npatterns;
      for (int i=0;i<patterns.size();i++) {
        if (hint.matches(patterns[i])) continue;
        npatterns.push_back(patterns[i]);
      }
      swap(patterns,npatterns);
      r.push_back(most_likely(patterns));
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
		cout << "Testing RangeGame (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397945747;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RangeGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string possible[] = {"1-100","100-200","200-300"};
				string hints[] = {"50-75","250-1000"};
				int __expected[] = { 100,  200,  100 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			case 1:
			{
				string possible[] = {"100-900 1111","200-800 2222","300-700 3333","4444"};
				string hints[] = {"2000-4000","500"};
				int __expected[] = { 300,  100,  4444 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			case 2:
			{
				string possible[] = {"346591240","858005279","1321831520","1453846384","1972718383","530431653-1848872872"};
				string hints[] = {"1400000000-2000000000","400000000-600000000"};
				int __expected[] = { 858005279,  346591240,  346591240 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}
			/*case 3:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string possible[] = ;
				string hints[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestDoors(vector <string>(possible, possible+sizeof(possible)/sizeof(string)), vector <string>(hints, hints+sizeof(hints)/sizeof(string))); break;
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
