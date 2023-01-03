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
int dist[2501][63][2];
const int INF = 1e8;

class NameInput {
 public:
  int n,m;
  string predict,name;
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
    memset(dist,-1,sizeof(dist));
    for (int i=0;i<n;i++)
      for (int j=0;j<63;j++) {
        char c = tochar(j);
        int flag = 0;
        for (int k=0;k*2<=n;k++) {
          int idx1 = (i+k)%n;
          int idx2 = (i-k+n)%n;
          if (!(flag&(1<<0)) && predict[idx1] == c) {
            flag |= (1<<0);
            dist[i][j][0] = idx1;
            if ((flag&3) == 3) break;
          } 
          if (!(flag&(1<<1)) && predict[idx2] == c) {
            flag |= (1<<1);
            dist[i][j][1] = idx2;
            if ((flag&3) == 3) break;
          }
        }
      }
    int cur = 0, next = 1;
    memset(dp,0,sizeof(dp));
    for (int idx=m-1;idx>=0;idx--) {
      int c = toint(name[idx]);
      for (int pos = 0;pos < n;pos++) {
        int t = INF;
        for (int i=0;i<2;i++) {
          int d = dist[pos][c][i];
          if (d == -1) continue;
          int dd = min((pos-d+n)%n,(d-pos+n)%n);
          t = min(t,dd+dp[cur][d]);
        }
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
				string predictionSequence[] = {"6P6ggg96pqPPqp9P99gggpgp6g9pppPp6pPgPq9g6gg9gpgq6P", "pg6pqgqq6qPpq6ppgpg9qgPg96p9qq99669pPqgp9qq9gq6gqq", "P6PPPPgPppqpPpq99g6gqpq6Pqp9Pg9q6P6ggp6999gq9g6qqp", "PPgq9P6gp9qppqpP9666pgqp6gpP66qppPqqP9g6ppPP96q6gp", "q99PpP69qpp969g96PgpP9gpPP6qg69p6qpqq69q69gq6pPqpp", "gP6gpg6gp6ppP69gp6Pp9p6pPpgP6ppq9p96q9gq6Pq6gPqPg9", "pg9p966q9pp96qgpPgpqpgg6Pg9696gP9pqP966Pg9PpqPpppg", "pP6P99pg9q9PPp6gpp96qp6qp9qgP6q66q6qP6gqP99qpg9ppg", "66PPqgq9gq99pqg66gqgpp6qqgp6g96gqg66p6PPpq9g9pgPp9", "96p9qP9PpPq6qpqpggPp669pPpgpqg96pqpp9p9g9p6Pg66Pg6", "pg9qp6gqgp9Pp9qqpqp9P9gqP6g9p66p99P6q969999qPPqgp9", "qppP6qPq96gPPqg9gq9gqPp6pgqpqqgggp6g6q6PgP669696pq", "qgPpq69gg6qq66PPPqp9qgPqg6gPgPp9P9ggq6qqpg6P6pqgPp", "PpPggqg9qPP6pP9qPg6gp6PPg66PPgp96ppp6q6q9qpgPgq6PP", "g69q9gpg9P99pPpgp9g6p9gq6qp9qPqPggpPgp6q9g9gq6gP6P", "PP6gg6P9pppgq9Pqpqq69pP96Pgpqq96pp99ppq9696q6g9Pq6", "69gpgg6qP66g9q96q6g6g9q99PPgq6ggg6PPgqg9qq9Pqp696P", "9Pg66q6qq9q9pPpp66P69qPqP9Pq6pg6pPPpppq99p99p969p6", "66pgPpqP9pP6qqp99PPPPqP6Pg966qqP9g699pgpPpp99gpPP6", "g6qpg69gq66gg9Pg6ppqqgq6ppgPPgP9pqq669Pg9qg9g9pp9p", "q6qPPqqqgg6PqpgP6q699gg999gpqpP66gP69g9qPPq6PPPPgq", "gg9pP696Pq6q9gpqpg6pP96q9gqqgp6PP99p9qqpg9PqP9Pq6p", "gg9g999g99ppg6pqp9qqq96ggpqq9gp6pP66p6g69qp9pgP6gg", "6qppgp6P69p96gq69PPp9qq9pPpPpP99Pq69ggP9Pg66g69PgP", "gPq669P6pP69P699pgqPgpg6Pqq66p9gqpqq6p9pgqqp69gggg", "6Pp6Pgq666q6gggp9qgPg6gPpqqq99qqp996qgg9P99PP6ggpp", "P69999gqqPPPqpgp9ppP99Pp6P999PgP99P6qgpp6qP6Pqqp6g", "q66Pppqq6pPppP6p6Pgqqq9q669pggg6969gPq6pq9p66gqPPP", "6pp6pPP9q699PqqPg6g69ppp6gq6qPppPqg699PqP69qq66PqP", "gqgPqgq9gppqppP6g66pg6P69Pq99Pppgqq99gPPPgqP99gp66", "9qq9pPp6P69pqP99g6qqp6q6gPpg6gqqppp9P6q6PqpqP66Pqq", "Pqgggpq66qpPpP6Pq9ppqqPPPg6p9p69P9p69966ppg669qq9q", "6q96qg66p9qpg6pp6pgg999pqPgppgqg9ggg9pqg6pg6qpp66g", "gq6pq6g6qqp6qqq9P696qgPqqP9g66pPpgP99pq966Pgq6ppp6", "gPqpgppq6pPggpqP9PgPg699qg6qggpP6qP9g66Pgp6ppqgq6g", "q6g69gpP6PqP6g6pP6q9pg9Ppq6p96Pgq9pp6qg9p9pPPq99gq", "Pq6gPq6Pqgq69g99p9P666pPqppP9gp9q996Pp969Pq69p6g9P", "6gp9p6qqpgp96qq9qqPqqgg9g9p6qPP6qp9ggPPqpqpg9ggqq9", "qp9pgg69gPq9pq6PPPg6P6g6P6g6P6qgPp6999P6ggppp96PP9", "9gqpPppg6qg96qq996PPqPPqPPqqPpqpppqgqpPgg6Pp9qP99q", "66p6qg9PqP9P6g6p9pg6pgPp99qqqPP66gPP9P9gqqpq6gq96p", "qqqgqgggqgP9ppqPpgPp66P99P66666PPpp99pPqqpqq96gp66", "P69q6P9Pp9pPqPpgq9qq6gpqpp9pPqPpPp9PqPPP9gg6qggq6g", "qg69pppqgqpg9gPp966qgqPgPggP6qqqp999q6q69pqp96pp6g", "P6g9g9P66g69pPq6PqgqP999pppgg6p9pPPPgpP9qPP6pgppqp", "ggg6PqP6pqp96PPp69qg96Pqg6Pp96qpgpp96Ppp9qqpqgPqPP", "9q6Ppqpgpp9P6g9PP9gP6qpp9qgpg9PPp9g6pqpPpp69g6q9pq", "6PPPPqp6gP9gP6Pq6gg9qPqp966ppqqPp6Pgq9p99gpppP6qqp", "666PPg96g99Pgqq6g6Pg9pgpp6Pqq9qgp69pqP9969pPPPq9g6", "g6pg9p9pq66pPqg996Pp69gg69pgP9qqPgppqp9699q9q6g9gg"};
				string name[] = {"6996p6669qg9qq9qPgpg9Pq6pq6qPPqq66qpq69gg6PPggqgpg", "qqP96qqPg96qg96P696qg6q99ggg9pqPPp69PpggpqPqqppq9g", "9q99ppgPp6gqp9qPPqqp6q9qqqp9gpgp9gqgppq9g9q9qg6q6P", "qq9q6qgPgqpgPggg69Pq6ppgPqq9g9gppPP96pg69qPpqgpg6g", "q9gp6p9gppg9pp9qpqpP9PpPP99pPq6qgPq66pgqqgqg9p66pq", "gPqqg999PqqqPpgppPgPqppPpqpgg6qqq9p6qqgpqpPpp99pg6", "p6pPp9gp9696P6999p9ppPp6qg6gP9q99ggpPPgg9PPpq66qpp", "6qPgp9pPqPq6g9999q999p6qqPp996ppgPqP6qqp9pP9qqgq6g", "p9p6g6666pPqgpp9ppqpp69pggqqp99PgpggPP696gqgpq9966", "66pP9gg9p999Pggqq9PpqPg9gggqg9Pp6qpq6q6qPp99qqgp6g", "g9696qp6P9qPggg99P9qP69P6pqPPqqppq9ppPppgqqPq6Pp69", "g6P6996gg996pP9gPpPqP9qPP6gpqpqPqq9q66qqpp9Pqq9PgP", "P96q9pgqq9Pg9p99qqgp66gg9qg69gggq9pqggq9pP9Pgpg66q", "g9PgpqgPpPPP969ppggq6696P6669P6p66gqq6gqppP9Pqg9qp", "9p6p6qpPPg9qgqpPq9p6g999qp9gp6gpPpqggP9gPppgPg9ggg", "PppP9pP9pp99gPpqPPPgpgp9pqpPpPPp66P6Pgpg9qgp9Pg9Pq", "ggqpp9Pq69Pqggp6PPgP9q66pg6gq66qgg9q6pPg9g66pq9pqg", "q9gP6p9gp6g6P6q6g96q99gpp6qqpg6P966ggq66pgPp9pq6Pg", "966qq6qqPggpPpgP9gqqP69p99pgpgP6gP6g9Pg6gPpg99PqqP", "g9ppggqqg9p9PPq9pp6qqpppPg6Ppqgg9p9ppq9g6Pppp9gqg6", "Pqp99q6g9Pp9ppqqgP99q6p969PgP9pPggpg99gqgPPq9qpPqp", "69gg99pgPgg96p6P66gp6p99gpqqPp6qPpqP6p69pPpgP696gP", "PP6gpp6PPqgp9g66p96qgPqpqqqPpgpppgqPPpppq9gpPp6ppg", "p6p666qPPqPP9q69q9pqPpqq6P69gqqgp6pp9g6qPq9PPqpqpq", "PpqgPgg9P99gP6Pppgqp6Ppg6PP9gpgggPP6q6pqPPp9gpPp6P", "q69P96p9p96gq9Pqg99qP6gqPg6gqgq9PqqPqpP99g9p6pq6Pg", "96Ppp6Pg69qpPpP66g99Pp9qpgp9ppgq6gq6pgPg696gP96p69", "pP9696P6ppgpq99q6PqPqPPqP666gP669q99p9qPgqP6gqgq99", "qp999p6ggq66g9gqgpp96Pqg9g9P66P9PPpgqqgp9pq6g9pggP", "6qgPgqpqP9qpP9q6Pg969ggg696gqq6qqpP9pg6gg6q6pg96pP", "Pqpgqppqg6P66ppPqqgPgqPP6qqqPPqqgp9g9ppPgPPppgg6pg", "9q6ppP9qpgPqPpqPq6gp9gpg6pPggqg6gP6q99ggpgPq6p66qP", "9pqgqgggPp99pg96gppPpgg9p99P6Pg6gPq9qPqgq6gP6p9gpg", "q9PgP66gPgq999qPqqqP6pPqg9qpPPpg9ppPpgppqp9q6P6g6g", "9gPg6pqg6qgpg6q9PP6gPPgpp96Pgqp9g99g6969qq96ggpppp", "g6qp66gq9999q9P9P6Ppgpggqgqggp9g6ppPpgPg66p6pg66g6", "qPpgp9qp996p6696pqgPPg9666q6ppqg6g9pp6qgPg9669q6P6", "q6gP969g9qPP9gqgg6gPggpPpgPgqpp6qqPgPPPpgg96qgggpq", "9qgggggqP99qq6Pqpq6PpgP9q9Pg669g9g9p99q6q6qggg6Ppg", "P9pggpPp6PPgg9pq6pgpp6P9q6gpgp6gppPPPpqg66gg66g6pg", "p69696pq9Pgg9qp69ggpPPqgqPpp9qp69p9g96pPP6g9p6p6Pq", "qp96pq6g9g99qPgg666q9Pgpqgqq9pPg96g9gq996966PgPgP9", "pP9gPqPpqpp9qP6Pg69PPgp9PPgggPq6969P6qqpPp6g99q9gg", "qp69PggggqP9Ppgqg6qgggqqg9qgpp6q9p9P66pqgPgppq9999", "P6q9pqqqP6p6Pg9g9g99gqpP9P69p6qgp6qP6Ppp9gqpq969gp", "9q6gg6gp6gPg6Pg6PqqpPP6PPP6pPPg666p669ppppg9ggPg6g", "qqq9g9qPg69q9PPg9g96Pq6Pq669P6p6qpP9ppqggq9gP9996p", "9qg99gp96p99g699gPqPp66966Pgg9PgP6p9pgpg9qg9qg66PP", "P6ppq9PppP9p999qP9q69p69pp69qqPPpqgggg6qgppgg6gpPq", "p6qggq6q6ppq9q6p6g9qpqpP66gq9996gqpgpg6Pg9pg9qqgp9"};
				_expected = 3907;
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
