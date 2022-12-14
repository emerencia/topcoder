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
int dp[2][2501][2501];

class WinterAndReindeers {
 public:
  bool issubseq(const string& S, const string& s) {
    int si = 0;
    for (int i=0;i<S.size();i++)
      if (s[si] == S[i]) {
        si++;
        if (si == s.size()) return true;
      }
    return false;
  }
  int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
    string A = accumulate(allA.begin(),allA.end(),string(""));
    string B = accumulate(allB.begin(),allB.end(),string(""));
    string C = accumulate(allC.begin(),allC.end(),string(""));
    if (!issubseq(A,C) || !issubseq(B,C)) return 0;
    memset(dp,-1,sizeof(dp));
    int cur=0,next = 1;
    for (int ai=A.size();ai>=0;ai--) {
      for (int bi=B.size();bi>=0;bi--)
        for (int ci=0;ci<=C.size();ci++) {
          if (ci == C.size()) {
            if (ai == A.size() || bi == B.size()) {
              dp[next][bi][ci] = 0;
              continue;
            }
            if (A[ai] == B[bi]) {
              dp[next][bi][ci]=1+dp[cur][bi+1][ci];
              continue;
            }
            dp[next][bi][ci] = max(dp[cur][bi][ci],dp[next][bi+1][ci]);
            continue;
          }
          if (ai == A.size() || bi == B.size()) {
            dp[next][bi][ci] = -100000;
            continue;
          }
          int t = -100000;
          if (A[ai] == B[bi] && ci == 0)
            t = 1+dp[cur][bi+1][ci];
          if (A[ai] == B[bi] && B[bi] == C[ci])
            t = max(t,1+dp[cur][bi+1][ci+1]);
            t = max(t,max(dp[cur][bi][ci],dp[next][bi+1][ci]));
          dp[next][bi][ci] = t;
        }
      swap(cur,next);
    }
    return dp[cur][0][0];
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
		cout << "Testing WinterAndReindeers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391206141;
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
		WinterAndReindeers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string allA[] = {"X"};
				string allB[] = {"X", "Y"};
				string allC[] = {"X"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 1:
			{
				string allA[] = {"ABCXD"};
				string allB[] = {"BCDEF"};
				string allC[] = {"CD"};
				_expected = 3;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 2:
			{
				string allA[] = {"WE", "LOVE"};
				string allB[] = {"WORKING", "FOR", "SANTA"};
				string allC[] = {"JK"};
				_expected = 0;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 3:
			{
				string allA[] = {"ABCDE"};
				string allB[] = {"CDEAB"};
				string allC[] = {"B"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 4:
			{
				string allA[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
				string allB[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
				string allC[] = {"AXBADXBBAB", "CDD"};
				_expected = 23;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 5:
			{
				string allA[] = {"GHUMEAYLNLFDXFIRCVSCXGGBWKFNQDUXWFNFOZVSRTKJPREPGG", "XRPNRVYSTMWCYSYYCQPEVIKEFFMZNIMKKASVWSRENZKYCXFXTL", "SGYPSFADPOOEFXZBCOEJUVPVABOYGPOEYLFPBNPLJVRVIPYAMY", "EHWQNQRQPMXUJJLOOVAOWUXWHMSNCBXCOKSFZKVATXDKNLYJYH", "FIXJSWNKKUFNUXXZRZBMNMGQOOKETLYHNKOAUGZQRCDDIUTEIO", "JWAYYZPVSCMPSAJLFVGUBFAAOVLZYLNTRKDCPWSRTESJWHDIZC", "OBZCNFWLQIJTVDWVXHRCBLDVGYLWGBUSBMBORXTLHCSMPXOHGM", "GNKEUFDXOTOGBGXPEYANFETCUKEPZSHKLJUGGGEKJDQZJENPEV", "QGXIEPJSRDZJAZUJLLCHHBFQMKIMWZOBIWYBXDUUNFSKSRSRTE", "KMQDCYZJEEUHMSRQCOZIJIPFIONEEDDPSZRNAVYMMTATBDZQSO", "EMUVNPPPSUACBAZUXMHECTHLEGRPUNKDMBPPWEQTGJOPARMOWZ", "DQYOXYTJBBHAWDYDCPRJBXPHOOHPKWQYUHRQZHNBNFUVQNQQLR", "ZJPXIOGVLIEXDZUZOSRKRUSVOJBRZMWZPOWKJILEFRAAMDIGPN", "PUUHGXPQNJWJMWAXXMNSNHHLQQRZUDLTFZOTCJTNZXUGLSDSMZ", "CNOCKVFAJFRMXOTHOWKBJZWUCWLJFRIMPMYHCHZRIWKBARXBGF", "CBCEYHJUGIXWTBVTREHBBCPXIFBXVFBCGKCFQCKCOTZGKUBMJR", "MBSZTSSHFROEFWSJRXJHGUZYUPZWWEIQURPIXIQFLDUUVEOOWQ", "CUDHNEFNJHAIMUCZFSKUIDUBURISWTBRECUYKABFCVKDZEZTOI", "DUKUHJZEFCZZZBFKQDPQZIKFOBUCDHTHXDJGKJELRLPAXAMCER", "OSWITDPTPCCLIFKELJYTIHRCQAYBNEFXNXVGZEDYYHNGYCDRUD", "MPHMECKOTRWOSPOFGHFOZQVLQFXWWKMFXDYYGMDCASZSGOVSOD", "KJGHCWMBMXRMHUYFYQGAJQKCKLZNAYXQKQOYZWMYUBZAZCPKHK", "TKYDZIVCUYPURFMBISGEKYRGZVXDHPOAMVAFYRARXSVKHTQDIH", "ERSIGBHZJZUJXMMYSPNARAEWKEGJCCVHHRJVBJTSQDJOOTGPKN", "FPFYCGFIEOWQRWWWPZSQMETOGEPSPXNVJIUPALYYNMKMNUVKLH", "SECDWRACGFMZKGIPDFODKJMJQWIQPUOQHIMVFVUZW"};
				string allB[] = {"YVIJGFULLKJDUHSJAFBTLKMFQRMYJFJNHHSSQCTYDTEAMDCJBP", "RHTNEGYIWXGCJWLGRSMEAEARWTVJSJBAOIOJLWHYPNVRUIHOSW", "KIFYGTYDHACWYHSGEWZMTGONZLTJHGAUHNIHREQGJFWKJSMTPJ", "HAEFQZAAULDRCHJCCDYRFVVRIVUYEEGFIVDRCYGURQDREDAKUB", "NFGUPROQYLOBCWQXKZMAUSJGMHCMHGDNMPHNQKAMHURKTRFFAC", "LVGRZKKLDACLLTEOJOMONXRQYJZGINRNNZWACXXAEDRWUDXZRF", "USEWJTBOXVYNFHKSTCENAUMNDDXFDMVZCAUTDCCKXAAYDZSXTT", "OBBGQNGVVPJGOJOGLMKXGBFCPYPCKQCHBDDZWRXBZMQRLXVOBT", "WHXGINFGFRCCLMZNMJUGWWBSQFCIHUBSJOLLMSQSGHMCPHELSO", "TFLBGSFNPCUZSRUPCHYNVZHCPQUGRIWNIQXDFJPWPXFBLKPNPE", "ELFJMTKUQPZOMWNLMBUPMKTLPTNDMPDSYDSGVFPENEMWBORIFS", "UQHCESKMKHSSMVNONWAFXWHGBIBABVQOPQFOVIUSSQFQWEHTXD", "ZUJTLNTXMRJXXWTLGGKYTBIOLYDNILQADOJSKKVFXAHHJMBOCL", "JARINTDWCLDVDXROPBYJZWYYOJUOTHWMLVRGLFZDZDBTUBXUOF", "FVNCRSWSAZNMOIJOIVVGOBQPNCKWVNHKEBMTDHVYGKJISUXHAT", "MUUDQBHMKNHFXAXQXKJLZZQTSJFAEEDFUUJKOLXJOQKDVFEPVL", "HVHRWTFDUKXFFJPSSWYXLIJJHEVRYXOZBAFPFMOWGRGONUATDQ", "LAHYGGYLJDDJHMLTEDZLODSRKEUTGTNKNTARJKPXINOVGZDTHU", "NWOOXVJJMPSVKNHKWJOPMMLEBKSUCVZQLYQNWCMBVBHRMLOWPJ", "BWYVWTGTOQNMICXAPZARKNNXTUUFARZROSDQWSMTCJGHECQUDO", "SRTJXYAAYKQRXYCRXUWJXNPQJNBKCPDMOKALXAPEMVBQLZSVXZ", "KUTAPPWGZPDPYZKZCVBNTCVFXSXPJAOXTFHVXXYTGOKRCXAETA", "UQGNDMPHWZYIAYABJRQGEPPXYJSTTYZUVLDVYBSUXKBMFZVRTN", "OVIDZNPGHOZVAFMSNSNQIVMVUBCWTFSRQTMKNEPBHOWEJAZHKW", "CMMTPIXXXLZQYSXTWWTAIDYAXYQLEPRXIBEXXYFVSDDYGTHCUY", "YFWPJSFYBGLGZMBINTATTNHODTONPYZWOTKGNGUPHPKXEATOWZ", "ABSDNVQHKFCMOFISFRFQGVPMVORPJFZSLZMPJJNEHRYKXJZUBU", "ACCLFKCYZOBGHTUOXRAJVPRECWGXXPSWCGMMVEDEWDMFNQWCUQ", "DSCILIQECIHLUILGMFCSWTWKKXLCBHQKVCSWJEBKRJLPGFGRAT", "ZBSGUVZIFNHYXWJSJAVWAUXPANNAMXJDVZUHNACZYHEPWZOLHU", "SLRKVWPNVGZMIIZWUDWDFZLKTBQDXGYYIUDSJVEZKMESBJLKYE", "RTAHNEXHUQMJICBMUSQDKLASOLWJXPTXXEUMZFWYUCPABQSEFF", "UNQPKFNNBECBBCJPDYJLIBITLLPLXELRDKEXDTQUVPTTEYHTLQ", "LBBBVOQOZKYNAYYRBAQMYJHZXNDSIYFSEXWBIOEWQVQRTCDLPQ", "MVJIFVGYMKGOTZJMNZQTMRPNDEVNMTHJITSSPAQNJRDOYJWPYA", "TMLEYQSVKPAMSVBMVXRLLIVFEDKJIGAVYXJVEQVRBACUIGAIPY", "HBBXIPBZNCWHRBLIRIZXOQPTQQWEAAFJEQIOZPYFAUUQMVHXKM", "NXMSYAMPTLZANOTLSLWUHTFQJRRWBWHMQHZKHDKCRFVBEIYIPV", "FVPZHYUJABTQWWTBKDOGKEMHIBYXRNXSXRZLETBQEXKRQOIERN", "APLQYJPQOUBVJSEBALWNKSVLOIDZFPIRWYCZTWZZVEWXOTAKUD", "KPEDUPKCZLHWUSKDNEVDCPLBKLPJMPFDCYQTRCVVVTRFFVPEKK", "QMCUPRYJAUTEUVCZVICTHRXSXCLPRGDLWXFAIGAYRUEICUFDIA", "MHTKBXOTDIRXXGVZQMEYROVFICHQNIVFJZAUQFDFTGMOPSRGPU", "GXTUHLCVSPIHAZRSSFSZWXBQMURWMXCDBHUMRGJQMVNKYRTNSJ", "VWZXSSQXNJOMUYJNJ"};
				string allC[] = {"UWRSYXWQY"};
				_expected = 498;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			/*case 6:
			{
				string allA[] = ;
				string allB[] = ;
				string allC[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string allA[] = ;
				string allB[] = ;
				string allC[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
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
