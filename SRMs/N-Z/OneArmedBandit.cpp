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

class OneArmedBandit {
 public:
  bool ispossible(const vector<string>& wheels, string line) {
    for (int i=0;i<wheels.size();i++) {
      if (line[i] == '-') continue;
      vector<char> counts(26,0);
      for (int j=0;j<wheels[i].size();j++)
        counts[wheels[i][j]-'A']++;
      if (!counts[line[i]-'A']) return false;
    }
    return true;
  }
  double calcprob(const vector<string>& wheels, string line) {
    double r = 1;
    for (int i=0;i<wheels.size();i++) {
      if (line[i] == '-') continue;
      vector<char> counts(26,0);
      for (int j=0;j<wheels[i].size();j++)
        counts[wheels[i][j]-'A']++;
      r*=double(counts[line[i]-'A'])/wheels[i].size();
    }
    return r;
  }
  double progressiveJackpot(vector <string> wheels, string jackpotLine, vector <string> payoffTable) {
    double expectedearnings = 0;
    for (int i=0;i<payoffTable.size();i++) {
      stringstream a(payoffTable[i]);
      string b;
      int c;
      a >> b >> c;
      expectedearnings += c*calcprob(wheels,b);
    }
    if (expectedearnings >= 1-1e-9) return 0;
    if (!ispossible(wheels,jackpotLine)) return -1;
    double expectedfromjackpot = 1-expectedearnings;
    double r = expectedfromjackpot/calcprob(wheels,jackpotLine);
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
		cout << "Testing OneArmedBandit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397939319;
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
		OneArmedBandit _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string wheels[] = {"ABC", "ABC", "ABC"};
				string jackpotLine = "AAA";
				string payoffTable[] = {"BBB 5", "CCC 2"};
				_expected = 20.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 1:
			{
				string wheels[] = {"ABC", "ABC", "ABC"};
				string jackpotLine = "AAA";
				string payoffTable[] = {"AAB 4", "AA- 3", "AB- 2"};
				_expected = 8.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 2:
			{
				string wheels[] = {"ABC", "ABC", "ABC"};
				string jackpotLine = "AAA";
				string payoffTable[] = {"AA- 5", "A-- 2"};
				_expected = 0.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 3:
			{
				string wheels[] = {"ABC", "ABC", "BBC"};
				string jackpotLine = "AAA";
				string payoffTable[] = {"AAB 4", "AA- 3", "AB- 2"};
				_expected = -1.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 4:
			{
				string wheels[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"};
				string jackpotLine = "AAAA";
				string payoffTable[] = {};
				_expected = 10000.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 5:
			{
				string wheels[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"};
				string jackpotLine = "AAAA";
				string payoffTable[] = {"AAAE 20"};
				_expected = 10000.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 6:
			{
				string wheels[] = {"KACACEIBGCVDAKMACAAW",
				                   "CECMBDBJCLHFNDCBDDNB",
				                   "BYAGBJFDAGBHEGEFVXDR",
				                   "UDWFABFAHDXACICQHAEH",
				                   "EBHOCHABAHBDAUBZHHAB"};
				string jackpotLine = "KJ--Z";
				string payoffTable[] = {"Z-U-U 23",
				                        "YUBSA 142",
				                        "Q-AN- 92",
				                        "ZA-CX 133",
				                        "-BE-Z 125"};
				_expected = 3500.0;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			case 7:
			{
				string wheels[] = {"UQKJQXGRWNLSGQPPRKNYALFDEHVBFYAIUNHLYJ", "MAUJZJKYKXEAKLTXEPIRIRHFNGCGHNNBKDMEEW", "HGMXGGHYSMMKHCYMAKYOCQFMFBQINOAQJUDFWK", "ZZHXSULDRYGMWXPMPDLOPFZWHKEMCWFDUJXKKQ", "QFCXTJDNQJJMVHQJNUASMDPFABQILLBHTXBEQE", "THSSFLBEEDQHPAAZFUXZTMWCEPRTWZJTXGGJRR", "CTKMMXWGKJKQXMVGUPIFBMXQOSLSKQHQQAESKG", "JTKWJXDVHSFCIVCYCZIPQVDWJKJDPPNDYMREJY"};
				string jackpotLine = "FYJPJDTN";
				string payoffTable[] = {"CUWTFASE 406097", "GYCQMGVN 860264", "ILTIPFTD 945589", "DGIUAFXB 974300", "QLYVXODL 767613", "WWDLBOKF 921813", "NEJPRSPP 51676", "DXSRWPYR 117129", "VLLSHALC 89338", "FLBQJZCD 65680", "GLXVXJNS 990402", "XJBORZME 769154", "XAVJDIXM 400609", "XFDXJNWP 21886", "WRLUQYWT 383511", "ZMFJPFFM 158026", "HCFNDCEB 422791", "ZPPDPMFT 98875", "LDTSBMJT 447176", "ZCUQFUKZ 702783", "VEGUSYIC 50872", "MOQCVYFW 768005", "TPHMBJBU 900731", "KAMDKWIP 555637", "TYCMNILJ 821694", "JGMNVHGP 111939", "PLKOEAGD 982946", "ERNEZZZL 814928", "IJPCRRDW 499619", "OKCFBHLM 226059", "JZOMZJEC 367418", "HUCVLCCH 977765", "XVYSXFYO 162783", "WVNXNFZJ 707788", "WCOMEXTB 850477", "NVISQQCF 840876", "DDAUIRXM 799040"};
				_expected = 1.811441756293334E11;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}
			/*case 8:
			{
				string wheels[] = ;
				string jackpotLine = ;
				string payoffTable[] = ;
				_expected = ;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string wheels[] = ;
				string jackpotLine = ;
				string payoffTable[] = ;
				_expected = ;
				_received = _obj.progressiveJackpot(vector <string>(wheels, wheels+sizeof(wheels)/sizeof(string)), jackpotLine, vector <string>(payoffTable, payoffTable+sizeof(payoffTable)/sizeof(string))); break;
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
