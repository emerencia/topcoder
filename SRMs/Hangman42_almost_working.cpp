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
// start reading: 17:35
// done thinking: 18:40
// done implementation: 19:02
// END CUT HERE
int frequency[51][27];
int haschar[26];
double mem[1<<10];
bool seen[1<<10];
double mem2[1<<10][27];
bool seen2[1<<10][27];

class Hangman42 {
 public:
  int n,m;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  double rec2(int mask, int c) {
    double r = mem2[mask][c];
    if (seen2[mask][c]) return r;
    seen2[mask][c] = 1;
    double t = 0;
    int bc = bitcount(mask);
    for (int i=0;i<n;i++) {
      if (!(mask&(1<<i))) continue;
      int newmask = mask;
      for (int j=0;j<m;j++)
        if (frequency[j][c]&mask)
          newmask = newmask&frequency[j][c];
      newmask |= (1<<i);
      if (newmask == mask) continue;
      if (haschar[c]&(1<<i))
        t += 1.0/bc*rec(newmask);
      else
        t+= 1.0/bc*(1-rec(newmask));
    }
    return r = t;
  }
  double rec(int mask) {
    double& r = mem[mask];
    if (seen[mask]) return r;
    seen[mask] = 1;
    int bc = bitcount(mask);
    if (bc == 1) return r = 1; // mask 0 should never occur
    r = 0;
    double t = 0;
    for (int i=0;i<26;i++) {
      int nrwithchar = bitcount(haschar[i]&mask);
      if (!nrwithchar) continue;
      t = max(t,rec2(mask,i));
    }
    return r = t;
  }
  double probability(vector <string> words) {
    n = words.size();
    m = words[0].size();
    memset(frequency,0,sizeof(frequency));
    for (int i=0;i<words.size();i++)
      for (int j=0;j<words[i].size();j++)
        frequency[j][words[i][j]-'a']|=(1<<i);
    memset(haschar,0,sizeof(haschar));
    for (int i=0;i<words.size();i++)
      for (int j=0;j<words[i].size();j++)
        haschar[words[i][j]-'a']|=(1<<i);
    memset(seen,0,sizeof(seen));
    memset(seen2,0,sizeof(seen2));
    return rec((1<<words.size())-1);
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
		cout << "Testing Hangman42 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399303427;
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
		Hangman42 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"top","web","cam","buy","now"};
				_expected = 0.6;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"a"};
				_expected = 1.0;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"ozeexsuaihtuucqghqsjzqzugmaebvdrddyztehr",
				                 "lvjvwhqyeqpapbjusjtxfbcgfbsudrbhpydzryyp",
				                 "cigacdzesqanrlflmsxvhvtvtnzelbzlopcchdob",
				                 "edqogzausmjxzoagpsssxwnmfranrrswjsdgqcqv",
				                 "ptvbnhdcecegnnsofcxaqtizrkwvazfngvzgcsqb",
				                 "guiqkikpwwbzgpvtikaaxxjitqkqfughdlmjtdax",
				                 "gbubcxhxscszrcuzbggjmnzlzihftpmpmaamtxcp",
				                 "tuijqvgvbiwbyjhjmkmmqlmhayvdqhlkpptqqide",
				                 "yidryvjmpbjkdzhmhtoynhbwlbsehcbymltrddsj"};
				_expected = 0.8888888888888888;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"abcdefghiz", "abcdefghyj", "abcdefgxik", "abcdefwhil", "abcdevghim", "abcdufghin", "abctefghio", "absdefghio", "arcdefghip", "qbcdefghip"};
				_expected = 0.5;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 4:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.probability(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
