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
int dp[2][2501];
const int INF = 1e8;

class NameInput {
 public:
  int n,m;
  string predict,name;
  vector<vector<vector<PII> > > dist;
  char tochar(int i) {
    if (i < 26) return 'a'+i;
    if (i < 52) return 'A'+i-26;
    return '0'+i-52;
  }
  int toint(char c) {
    if (c >= 'a' && c <= 'z') return c-'a';
    if (c >= 'A' && c <= 'Z') return c-'A'+26;
    return c-'0'+52;
  }
  int countUpDownKeyPresses(vector <string> predictionSequence, vector <string> nname) {
    predict = accumulate(predictionSequence.begin(),predictionSequence.end(),string(""));
    n = predict.size();
    name = accumulate(nname.begin(),nname.end(),string(""));
    m = name.size();
    dist = vector<vector<vector<PII> > >(n,vector<vector<PII> >(63));
    for (int i=0;i<n;i++)
      for (int j=0;j<63;j++) {
        char c = tochar(j);
        int flag = 0;
        for (int k=0;k*2<=n;k++) {
          int idx1 = (i+k)%n;
          int idx2 = (i-k+n)%n;
          if (!(flag&(1<<0)) && predict[idx1] == c) {
            flag |= (1<<0);
            dist[i][j].push_back(PII(k,idx1));
            if ((flag&3) == 3) break;
          }
          if (!(flag&(1<<1)) && idx1 != idx2 && predict[idx2] == c) {
            flag |= (1<<1);
            dist[i][j].push_back(PII(k,idx2));
            if ((flag&3) == 3) break;
          }
        }
      }
    int cur = 0, next = 1;
    memset(dp,0,sizeof(dp));
    for (int idx=m-1;idx>=0;idx--) {
      int c = toint(name[idx]); // move out of loop
      for (int pos = 0;pos < n;pos++) {
        /*
        if (idx == m) {
          dp[next][pos] = 0;
          continue;
        }
        */
        int t = INF;
        for (int i=0;i<dist[pos][c].size();i++)
          t = min(t,dist[pos][c][i].first+dp[cur][dist[pos][c][i].second]);
        dp[next][pos] = t;
      }
      swap(cur,next);
    }
    int r = dp[cur][0];
    return r < INF ? r : -1;
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
		cout << "Testing NameInput (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400858549;
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
		NameInput _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string predictionSequence[] = {"Jjhon"};
				string name[] = {"John"};
				_expected = 5;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 1:
			{
				string predictionSequence[] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789"};
				string name[] = {"Joh","nAndFr","iends"};
				_expected = 186;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 2:
			{
				string predictionSequence[] = {"aaaabbbab","baabbabaabba"};
				string name[] = {"bbaaababba","baababababbb"};
				_expected = 16;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 3:
			{
				string predictionSequence[] = {"john"};
				string name[] = {"John"};
				_expected = -1;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 4:
			{
				string predictionSequence[] = {"4"};
				string name[] = {"4444444444444"};
				_expected = 0;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 5:
			{
				string predictionSequence[] = {"abcABC123","cbaCBA321"};
				string name[] = {"aB32C2AaB3c","c32bA"};
				_expected = 38;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 6:
			{
				string predictionSequence[] = {"89998989998899998889988989999999988888988988999999", "98999999888888999888899888899999988988989898998898", "88999999898999998899989899989998998899898898989988", "89989888888998988999989888999898989998888988889989", "98888888898899889889898899989999988888998999899898", "98999899899988888889899899889989898999998888989999", "98898889999998999999988988888898889888898989899888", "88998999989889888999998889999899888988898888899889", "98999989888989888898988899999998888998898999999899", "89898899988889888999998988889989888888998998988999", "98898998998989899888998898999998999988988899988988", "88999889989998899888988899998899998889889988898888", "98998899899988998989988899998998988899888888888998", "88988989888999899998889999989889889888999888899988", "88989899899899898998989998989988988889999889989988", "89899999998888988989998998898898998988898988889999", "99988988889988888899999888998988888899898998999899", "88999988899989899998888899888999989888899899999899", "89898998899989989889898898889998989899899999889999", "88998989899898988999988999999898998889889898998988", "88899889899998888998989898898899988989888889899989", "99999989988999888989889989899998889889889989988989", "99899999999889889998998889898898888999989999899899", "99888999899898998998989889899889889898988899998899", "abcdefghijklmnopqrstuvwxyz024699899988898898899999", "88989889889989889988898989898889989989899888899989", "98999898988899989989899998989998999999989888998989", "98888899889889898889889989988889899998898899989998", "88898988989899998898989998989998889988988998888899", "88999889899988998888998999888998898988988989989988", "88889888898899998888899989999899989898899998988889", "89998899988898889899999999898998999988899988899889", "98998988999989998999898888999888999899888898888888", "98888889889898888998989888999998898899989898999989", "88899998998989998988899888888899999899889899899989", "98989998898999998888998998988888889899899988988899", "98989989898988899898899888889998899888898899899898", "89988898999988989899889889889899888899989888889999", "89998899899989988998999899899888999998889898989898", "89898898989989888998898988989988888899899888998888", "98998888998899898899888999988899988999999988988989", "88899888999889889898889898998898889888889898888889", "99988998989889989998999988998989888898998999898999", "89889898999999888989889888998888888998989998898989", "88988999999898889989989898989989899898898999898888", "98889989899888889988888989998989988989898998899988", "89999999888998899989889989898999989998899899988988", "98999889999999989988988888898988889899898899889998", "899989999888998898889998988989ABCDEFGHIJKLMNOPQRST", "UVWXYZ1357"};
				string name[] = {"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyY", "zZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsS", "tTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmM", "nNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgG", "hHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aA", "bBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", "0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStT", "uUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnN", "oOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhH", "iIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbB", "cCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01", "23456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuU", "vVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoO", "pPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiI", "jJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcC", "dDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123", "456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvV", "wWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpP", "qQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJ", "kKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdD", "eEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ012345", "6789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwW", "xXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQ", "rRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkK", "lLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeE", "fFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01234567", "89aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX", "yYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrR", "sStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlL", "mMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfF", "gGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789", "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyY", "zZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsS", "tTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmM", "nNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgG", "hHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aA", "bBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", "0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStT", "uUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnN", "oOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhH", "iIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbB", "cCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01", "23456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuU", "vVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoO", "pPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiI", "jJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcC", "dDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123", "456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvV", "wWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpP", "qQrRsStTuUvVwWxXyYzZ0123456789"};
				_expected = 2949681;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 7:
			{
				string predictionSequence[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaammmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "mmmmmmmmmmmmmmmmQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", "QQQQQQQQQQQQQQQQQQQQQQQQwwwwwwwwwwwwwwwwwwwwwwwwww", "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwZZZZZZZZZZZZZZZZZZ", "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ", "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ", "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ", "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ7777777777", "77777777777777777777777777777777777777777777777777", "77777777777777777777777777777777777777777777777777", "77777777777777777777777777777777777777777777777777", "777777777777777777777777777777777777777777777777JJ", "JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ", "JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ", "JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ", "JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ", "JJJJJJllllllllllllllllllllllllllllllllllllllllllll", "llllllllllllllllllllllllllllllllllllllllllllllllll", "llllllllllllllllllllllllllllllllllllllllllllllllll", "llllllllllllllllllllllllllllllllllllllllllllllllll", "lllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "eeeeeeeeeeeeeeeeeeeeeeDDDDDDDDDDDDDDDDDDDDDDDDDDDD", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYgggggggggggg", "gggggggggggggggggggggggggggggggggggggggggggggggggg", "gggggggggggggggggggggggggggggggggggggggggggggggggg", "gggggggggggggggggggggggggggggggggggggggggggggggggg", "gggggggggggggggggggggggggggggggggggggggggggggg"};
				string name[] = {"YZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQew", "DZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQ", "ewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJm", "lQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7a", "JmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg", "7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZY", "Zg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewD", "ZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQe", "wDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJml", "QewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJ", "mlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7", "aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZ", "g7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZ", "YZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQew", "DZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQ", "ewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJm", "lQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7a", "JmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg", "7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZY", "Zg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewD", "ZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQe", "wDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJml", "QewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJ", "mlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7", "aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZ", "g7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZ", "YZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQew", "DZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQ", "ewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJm", "lQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7a", "JmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg", "7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZY", "Zg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewD", "ZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQe", "wDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJml", "QewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJ", "mlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7", "aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZ", "g7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZ", "YZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQew", "DZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQ", "ewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJm", "lQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7a", "JmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg", "7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZY", "Zg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewD", "ZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQe", "wDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJml", "QewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJ", "mlQewDZYZg7aJmlQewDZYZg7aJmlQewDZYZg7aJmlQewDZ"};
				_expected = 2397425;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 8:
			{
				string predictionSequence[] = {"bcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbc", "bdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbd", "bcbebcbdbcbfbcbdbcbebcbdbcbibcbdbcbebcbdbcbfbcbdbc", "bebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbe", "bcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebc", "bdbcbjbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbd", "bcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbc", "bgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbibcbdbcbebcbdbcbf", "bcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbc", "bdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbd", "bcbebcbdbcbkbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbc", "bebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbe", "bcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbibcbdbcbebc", "bdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbd", "bcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbc", "bfbcbdbcbebcbdbcbjbcbdbcbebcbdbcbfbcbdbcbebcbdbcbg", "bcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbc", "bdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbibcbd", "bcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbc", "bebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbe", "bcbdbcbfbcbdbcbebcbdbcblbcbdbcbebcbdbcbfbcbdbcbebc", "bdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbd", "bcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbc", "bibcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbf", "bcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbc", "bdbcbebcbdbcbfbcbdbcbebcbdbcbjbcbdbcbebcbdbcbfbcbd", "bcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbc", "bebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbe", "bcbdbcbibcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebc", "bdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbd", "bcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbkbcbdbcbebcbdbc", "bfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbh", "bcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbc", "bdbcbebcbdbcbibcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbd", "bcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbc", "bebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbjbcbdbcbe", "bcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebc", "bdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbd", "bcbfbcbdbcbebcbdbcbibcbdbcbebcbdbcbfbcbdbcbebcbdbc", "bgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbf", "bcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbmmn", "opqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789bc", "bdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbd", "bcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbc", "bebcbdbcbfbcbdbcbebcbdbcbibcbdbcbebcbdbcbfbcbdbcbe", "bcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbdbcbhbcbdbcbebc", "bdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbcbfbcbdbcbebcbd", "bcbjbcbdbcbebcbdbcbfbcbdbcbebcbdbcbgbcbdbcbebcbdbc", "bfbcbdbcbebcbdbcbhbcbdbcbebcbdbcbfbcbdbcbebcbdbcbg", "bcbdbcbebcbdbcbfbcbdbcbebcbdbcbibcbdbcbebcbdbcbfbc"};
				string name[] = {"WlkjihgfedcbzlkjihgfedcbYlkjihgfedcbDlkjihgfedcbLl", "kjihgfedcbrlkjihgfedcbUlkjihgfedcbMlkjihgfedcbnlkj", "ihgfedcbQlkjihgfedcbxlkjihgfedcbBlkjihgfedcbvlkjih", "gfedcbWlkjihgfedcbslkjihgfedcbBlkjihgfedcb0lkjihgf", "edcb3lkjihgfedcbBlkjihgfedcbxlkjihgfedcbSlkjihgfed", "cbBlkjihgfedcbwlkjihgfedcbLlkjihgfedcbVlkjihgfedcb", "ZlkjihgfedcbulkjihgfedcbElkjihgfedcbNlkjihgfedcb1l", "kjihgfedcbJlkjihgfedcbrlkjihgfedcbVlkjihgfedcb3lkj", "ihgfedcbElkjihgfedcb4lkjihgfedcbLlkjihgfedcbIlkjih", "gfedcbPlkjihgfedcbGlkjihgfedcbplkjihgfedcbmlkjihgf", "edcbOlkjihgfedcbGlkjihgfedcbtlkjihgfedcbwlkjihgfed", "cbxlkjihgfedcbDlkjihgfedcb7lkjihgfedcbDlkjihgfedcb", "Ulkjihgfedcb8lkjihgfedcbAlkjihgfedcbIlkjihgfedcbDl", "kjihgfedcbVlkjihgfedcbvlkjihgfedcbClkjihgfedcbRlkj", "ihgfedcbulkjihgfedcbPlkjihgfedcbWlkjihgfedcbplkjih", "gfedcbGlkjihgfedcbBlkjihgfedcbAlkjihgfedcbGlkjihgf", "edcbrlkjihgfedcbslkjihgfedcb2lkjihgfedcbAlkjihgfed", "cbVlkjihgfedcbDlkjihgfedcbZlkjihgfedcbKlkjihgfedcb", "YlkjihgfedcbFlkjihgfedcb1lkjihgfedcbTlkjihgfedcbRl", "kjihgfedcbtlkjihgfedcbplkjihgfedcbtlkjihgfedcbBlkj", "ihgfedcbElkjihgfedcbUlkjihgfedcbMlkjihgfedcbKlkjih", "gfedcbFlkjihgfedcbVlkjihgfedcbHlkjihgfedcbSlkjihgf", "edcbJlkjihgfedcb5lkjihgfedcbVlkjihgfedcbrlkjihgfed", "cbulkjihgfedcbHlkjihgfedcbHlkjihgfedcbrlkjihgfedcb", "XlkjihgfedcbClkjihgfedcbLlkjihgfedcbnlkjihgfedcbql", "kjihgfedcbtlkjihgfedcbSlkjihgfedcbXlkjihgfedcbylkj", "ihgfedcb8lkjihgfedcbIlkjihgfedcb2lkjihgfedcbIlkjih", "gfedcbRlkjihgfedcbWlkjihgfedcbAlkjihgfedcbVlkjihgf", "edcbOlkjihgfedcbVlkjihgfedcbylkjihgfedcbUlkjihgfed", "cb3lkjihgfedcbYlkjihgfedcbwlkjihgfedcbzlkjihgfedcb", "HlkjihgfedcbUlkjihgfedcbFlkjihgfedcbIlkjihgfedcbPl", "kjihgfedcb5lkjihgfedcb9lkjihgfedcb3lkjihgfedcbSlkj", "ihgfedcbUlkjihgfedcb2lkjihgfedcbQlkjihgfedcb9lkjih", "gfedcb8lkjihgfedcbHlkjihgfedcbXlkjihgfedcbolkjihgf", "edcb3lkjihgfedcb8lkjihgfedcbVlkjihgfedcbulkjihgfed", "cbRlkjihgfedcbqlkjihgfedcbqlkjihgfedcbVlkjihgfedcb", "plkjihgfedcb9lkjihgfedcbmlkjihgfedcbtlkjihgfedcbTl", "kjihgfedcbvlkjihgfedcbDlkjihgfedcbulkjihgfedcb4lkj", "ihgfedcbUlkjihgfedcbOlkjihgfedcbRlkjihgfedcbMlkjih", "gfedcbzlkjihgfedcbClkjihgfedcbTlkjihgfedcbDlkjihgf", "edcbolkjihgfedcbvlkjihgfedcbslkjihgfedcb8lkjihgfed", "cbrlkjihgfedcbYlkjihgfedcbolkjihgfedcbrlkjihgfedcb", "plkjihgfedcbqlkjihgfedcbMlkjihgfedcbFlkjihgfedcbZl", "kjihgfedcbtlkjihgfedcbClkjihgfedcbTlkjihgfedcbTlkj", "ihgfedcbtlkjihgfedcbWlkjihgfedcbHlkjihgfedcb7lkjih", "gfedcb6lkjihgfedcbrlkjihgfedcbslkjihgfedcb6lkjihgf", "edcbylkjihgfedcbMlkjihgfedcb2lkjihgfedcbQlkjihgfed", "cbGlkjihgfedcbKlkjihgfedcbtlkjihgfedcbolkjihgfedcb", "SlkjihgfedcbtlkjihgfedcbVlkjihgfedcbJlkjihgfedcbXl", "kjihgfedcbDlkjihgfedcbwlkjihgfedcbFlkjihgfedcbLlkj"};
				_expected = 438295;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)*1.75/CLOCKS_PER_SEC;
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
