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
typedef pair<string,string> PSS;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int mem[2501][2501];

class WinterAndReindeers {
 public:
  string A;
  string B;
  bool issubseq(const string& S, const string& s) {
    int si = 0;
    for (int i=0;i<S.size();i++)
      if (s[si] == S[i]) {
        si++;
        if (si == s.size()) return true;
      }
    return false;
  }
  set<PSS> getfixes(const string& A, const string& C) {
    set<PSS> a;
    for (int i=0;i<A.size();i++) {
      int si = 0;
      if (A[i] != C[si]) continue;
      for (int ai = i;ai<A.size();ai++)
        if (C[si] == A[ai]) {
          si++;
          if (si == C.size())
            a.insert(PSS(A.substr(0,i),A.substr(ai+1)));
        }
    }
    return a;
  }
  int rec(string& a, string& b) {
    this->A = a;
    this->B = b;
    //cout << a << " : " << b << endl;
    memset(mem,-1,sizeof(mem));
    return rec2(0,0);
  }
  int rec2(int ai, int bi) {
    int& r = mem[ai][bi];
    if (r != -1) return r;
    if (ai == A.size() || bi == B.size())
      return r = 0;
    if (A[ai] == B[bi])
      return r = 1+rec2(ai+1,bi+1);
    return max(rec2(ai+1,bi),rec2(ai,bi+1));
  }
  int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
    string A = accumulate(allA.begin(),allA.end(),string(""));
    string B = accumulate(allB.begin(),allB.end(),string(""));
    string C = accumulate(allC.begin(),allC.end(),string(""));
    if (!issubseq(A,C) || !issubseq(B,C)) return 0;
    set<PSS> a = getfixes(A,C);
    set<PSS> b = getfixes(B,C);
    int mxl = 0;
    for (set<PSS>::iterator i=a.begin();i!=a.end();i++) {
      PSS ap = (*i);
      for (set<PSS>::iterator it=b.begin();it!=b.end();it++) {
        PSS bp = (*it);
        mxl = max(mxl,rec(ap.first,bp.first)+rec(ap.second,bp.second)+(int)C.size());
      }
    }
    return mxl;
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
