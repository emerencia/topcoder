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

class DistinctDigits {
 public:
  int n;
  int ans;
  vector<int> lowdig;
  vector<int> higdig;
  vector<int> digitvector(int n) {
    vector<int> r;
    r.push_back(n%10);
    while (n/10) {
      n/=10;
      r.push_back(n%10);
    }
    reverse(r.begin(),r.end());
    return r;
  }
  bool rec2(int idx, bool biggerthansmall, bool smallerthanbig, const vector<int>& digits, vector<bool>& used) {
    if (idx == digits.size() || (biggerthansmall && smallerthanbig)) return true;
    for (int i=0;i<digits.size();i++) {
      if (used[i] ||
          (!biggerthansmall && digits[i] < lowdig[idx]) || 
          (!smallerthanbig  && digits[i] > higdig[idx])) continue;
      bool tbig = biggerthansmall;
      bool tsmall = smallerthanbig;
      if (digits[i] > lowdig[idx]) tbig = true;
      if (digits[i] < higdig[idx]) tsmall = true;
      used[i] = true;
      if (rec2(idx+1,tbig,tsmall,digits,used)) return true;
      used[i] = false;
    }
    return false;
  }
  bool canbevalid(int n) {
    vector<int> digits = digitvector(n);
    if (digits.size() > lowdig.size() && digits.size() < higdig.size()) return true;
    if (digits.size() > lowdig.size()) {
      // nrdig == hign so try to get something smaller than or equal to high
      sort(digits.begin(),digits.end());
      vector<bool> used(digits.size(),false);
      for (int i=0;i<higdig.size();i++) {
        bool cangotonext = false;
        for (int j=0;j<digits.size();j++) {
          if (used[j]) continue;
          if (digits[j] < higdig[i] && (digits[j] != 0 || i)) return true;
          if (i == 0 && digits[j] == 0) continue;
          used[j] = true;
          cangotonext = (digits[j] == higdig[i]);
          break;
        }
        if (i+1 == higdig.size()) return cangotonext;
        if (!cangotonext) return false;
      }
      return false;
    }
    if (digits.size() < higdig.size()) {
      // nrdig == nrdig in low so try get something bigger than low
      sort(digits.rbegin(),digits.rend());
      vector<bool> used(digits.size(),false);
      for (int i=0;i<lowdig.size();i++) {
        bool cangotonext = false;
        for (int j=0;j<digits.size();j++) {
          if (used[j]) continue;
          if (digits[j] > lowdig[i]) return true;
          used[j] = true;
          cangotonext = (digits[j] == lowdig[i]);
          break;
        }
        if (i+1 == lowdig.size()) return cangotonext;
        if (!cangotonext) return false;
      }
      return false;
    }
    // else it is equal to both
    // try find numbers in between
    vector<bool> used(digits.size(),false);
    return rec2(0,false,false,digits,used);
  }
  void rec(int idx,int sofar,int lastdig) {
    if (idx == n) {
      ans += canbevalid(sofar);
      return;
    }
    for (int i=lastdig;i>0;i--)
      rec(idx+1,sofar*10+i,i);
    if (idx != 0)
      rec(idx+1,sofar*10,0);
  }
  int count(int low, int high) {
    lowdig = digitvector(low);
    higdig = digitvector(high);
    ans = 0;
    for (int i=lowdig.size();i<=higdig.size();i++) {
      n = i;
      rec(0,0,9);
    }
    return ans;
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
		cout << "Testing DistinctDigits (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393012479;
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
		DistinctDigits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low = 1;
				int high = 20;
				_expected = 20;
				_received = _obj.count(low, high); break;
			}
			case 1:
			{
				int low = 1;
				int high = 30;
				_expected = 29;
				_received = _obj.count(low, high); break;
			}
			case 2:
			{
				int low = 151;
				int high = 309;
				_expected = 98;
				_received = _obj.count(low, high); break;
			}
			case 3:
			{
				int low = 1;
				int high = 15000;
				_expected = 1641;
				_received = _obj.count(low, high); break;
			}
			case 4:
			{
				int low = 153697;
				int high = 154689;
				_expected = 318;
				_received = _obj.count(low, high); break;
			}
			case 5:
			{
				int low = 1000;
				int high = 10000000;
				_expected = 19159;
				_received = _obj.count(low, high); break;
			}
			/*case 6:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 7:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 8:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
