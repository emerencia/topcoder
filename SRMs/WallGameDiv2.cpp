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
#include <cstring>
using namespace std;
typedef pair<int,int> PII;

int dp[2][51];
const int kInf = -1;

class WallGameDiv2 {
 public:
  int play(vector <string> costs) {
    int N = costs.size();
    int M = costs[0].size();
    fill(&dp[0][0],&dp[2][0],kInf);
    int cur = 0, next = 1;
    dp[0][0] = 0;
    for (int i=0;i+1<N;i++) {
      fill(&dp[next][0],&dp[next][51],kInf);
      for (int j=0;j<M;j++) {
        int cu = dp[cur][j];
        if (cu == kInf) continue;
        for (int k=j;k>=0;k--) {
          if (costs[i][k] == 'x') break;
          cu += costs[i][k]-'0';
          dp[next][k] = max(dp[next][k],cu);
        }
        cu = dp[cur][j];
        for (int k=j;k<M;k++) {
          if (costs[i][k] == 'x') break;
          cu += costs[i][k]-'0';
          dp[next][k] = max(dp[next][k],cu);
        }
      }
      swap(cur,next);
    }
    int mx = 0;
    for (int i=0;i<M;i++)
      if (costs[N-1][i] != 'x')
        mx = max(mx,dp[cur][i]+costs[N-1][i]-'0');
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"042"
,"391"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(0, Arg1, play(Arg0)); }
	void test_case_1() { string Arr0[] = {"0xxxx"
,"1x111"
,"1x1x1"
,"11191"
,"xxxx1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, play(Arg0)); }
	void test_case_2() { string Arr0[] = {"0"
,"5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, play(Arg0)); }
	void test_case_3() { string Arr0[] = {"0698023477896606x2235481563x59345762591987823x663"
,"1x88x8338355814562x2096x7x68546x18x54xx1077xx5131"
,"64343565721335639575x18059738478x156x781476124780"
,"2139850139989209547489708x3466104x5x3979260330074"
,"15316x57171x182167994729710304x24339370252x2x8846"
,"459x479948xx26916349194540891252317x99x4329x34x91"
,"96x3631804253899x69460666282614302698504342364742"
,"4x41693527443x7987953128673046855x793298x8747219x"
,"7735427289436x56129435153x83x37703808694432026643"
,"340x973216747311x970578x9324423865921864682853036"
,"x1442314831447x860181542569525471281x762734425650"
,"x756258910x0529918564126476x481206117984425792x97"
,"467692076x43x91258xx3xx079x34x29xx916574022682343"
,"9307x08x451x2882604411x67995x333x045x0x5xx4644590"
,"4x9x088309856x342242x12x79x2935566358156323631235"
,"04596921625156134477422x2691011895x8564609x837773"
,"223x353086929x27222x48467846970564701987061975216"
,"x4x5887805x89746997xx1419x758406034689902x6152567"
,"20573059x699979871151x444449x5170122650576586x898"
,"683344308229681464514453186x51040742xx138x5170x93"
,"1219892x9407xx63107x24x4914598xx4x478x31485x69139"
,"856756530006196x8722179365838x9037411399x41126560"
,"73012x9290145x1764125785844477355xx827269976x4x56"
,"37x95684445661771730x80xx2x459547x780556228951360"
,"54532923632041379753304212490929413x377x204659874"
,"30801x8716360708478705081091961915925276739027360"
,"5x74x4x39091353819x10x433010250089676063173896656"
,"03x07174x648272618831383631629x020633861270224x38"
,"855475149124358107x635160129488205151x45274x18854"
,"091902044504xx868401923845074542x50x143161647934x"
,"71215871802698346x390x2570413992678429588x5866973"
,"87x4538137828472265480468315701832x24590429832627"
,"9479550007750x658x618193862x80317248236583631x846"
,"49802902x511965239855908151316389x972x253946284x6"
,"053078091010241324x8166428x1x93x83809001454563464"
,"2176345x693826342x093950x12x7290x1186505760xx978x"
,"x9244898104910492948x2500050208763770568x92514431"
,"6855xx7x145213846746325656963x0419064369747824511"
,"88x15690xxx31x20312255171137133511507008114887695"
,"x391503034x01776xx30264908792724712819642x291x750"
,"17x1921464904885298x58x58xx174x7x673958x9615x9230"
,"x9217049564455797269x484428813681307xx85205112873"
,"19360179004x70496337008802296x7758386170452xx359x"
,"5057547822326798x0x0569420173277288269x486x582463"
,"2287970x0x474635353111x85933x33443884726179587xx9"
,"0x697597684843071327073893661811597376x4767247755"
,"668920978869307x17435748153x4233659379063530x646x"
,"0019868300350499779516950730410231x9x18749463x537"
,"00508xx083203827x42144x147181308668x3192478607467"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3512; verify_case(3, Arg1, play(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WallGameDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
