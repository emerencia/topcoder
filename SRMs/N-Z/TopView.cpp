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

const int kBige  = 1000;
const int kBig = kBige/2;

int isfree[kBige*52];

struct Card {
  int high_i;
  int low_i;
  int high_j;
  int low_j;
  Card() : high_i(-1),low_i(-1),high_j(-1),low_j(-1) {}
  void at(int i,int j) {
    if (high_i == -1 || i > high_i) high_i = i;
    if (low_i == -1 || i < low_i) low_i = i;
    if (high_j == -1 || j > high_j) high_j = j;
    if (low_j == -1 || j < low_j) low_j = j;
  }
  bool calc_needed(char c,const vector<string>& grid,vector<vector<int> >& adjm) {
    for (int i=low_i;i<=high_i;i++)
      for (int j=low_j;j<=high_j;j++) {
        if (isfree[i+kBig*j]) return false;
        if (grid[i][j] != c) {
          adjm[c][grid[i][j]] = 1;
        }
      }
    return true;
  }
};

class TopView {
 public:
  string findOrder(vector <string> grid) {
    memset(isfree,0,sizeof(isfree));
    vector<char> chars;
    vector<Card> cards(128);
    for (int i=0;i<grid.size();i++) {
      for (int j=0;j<grid[0].size();j++) {
        if (grid[i][j] == '.') isfree[i+kBig*j] = 1;
        else {
          cards[grid[i][j]].at(i,j);
          bool f = true;
          for (int k=0;k<chars.size();k++) {
            if (chars[k] == grid[i][j]) { f = false; break; }
          }
          if (f) chars.push_back(grid[i][j]);
        }
      }
    }
    vector<vector<int> > adjm(128,vector<int>(128,0));
    for (int i=0;i<chars.size();i++)
      if (!cards[chars[i]].calc_needed(chars[i],grid,adjm)) return "ERROR!";
    priority_queue<int> q;
    vector<int> incecnt(128,0);
    int tcnt = 0;
    for (int i=0;i<chars.size();i++) {
      int c = 0;
      for (int j=0;j<chars.size();j++) {
        if (i == j) continue;
        c+= adjm[chars[j]][chars[i]];
      }
      tcnt+=c;
      incecnt[chars[i]] = c;
      if (c == 0) q.push(-chars[i]);
    }
    string r = "";
    while (!q.empty()) {
      char a = char(-q.top());
      q.pop();
      r+=a;
      for (int i=0;i<chars.size();i++) {
        if (a == chars[i]) continue;
        if (adjm[a][chars[i]]) {
          adjm[a][chars[i]] = 0;
          tcnt--;
          if (!--incecnt[chars[i]]) {
            q.push(-chars[i]);
          }
        }
      }
    }
    return (tcnt ? "ERROR!" : r);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..AA..",
 ".CAAC.",
 ".CAAC."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CA"; verify_case(0, Arg1, findOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"..47..",
 "..74.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(1, Arg1, findOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "65AXab"; verify_case(2, Arg1, findOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(3, Arg1, findOrder(Arg0)); }
  void test_case_4() { string Arr0[] = {"..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "...................................ZZZ............", "..................................YZZaa...........", ".................................XYY.abb..........", "................................WXX...bcc.........", "...............................VWW.....cdd........", "..............................UVV.......dee.......", ".............................TUU.........eff......", "............................STT...........fgg.....", "...........................RSS.............ghh....", "..........................QRR...............hii...", ".........................PQQ.................ijj..", "........................OPP...................jkk.", ".......................NOO.....................kk.", "......................MNN......................kk.", ".....................LMM......................llk.", "....................KLL......................mml..", "...................JKK......................nnm...", "..................IJJ......................oon....", ".................HII......................ppo.....", "................GHHGGGGGGGGGGGGGGGG......qqp......", "...............FGGGGGGGGGGGGGGGGGGGrrrrrrrq.......", "..............EFGGGGGGGGGGGGGGGGGGGrrrrrrr........", ".............DEE..................srrrrrrr........", "............CDD...................ss..............", "...........BCC....................ss..............", "..........ABB.....................ss..............", ".........9AA......................ss..............", "........899....................tttts..............", ".......788.....................tttt...............", "......677................uuuuuuuutt...............", ".....566.................uuuuuuuutt...............", ".....550..............vvvvuuuuuuu.................", "......001.......zzzz..wwvv........................", ".......112......zzzz..wwvv........................", "........223.....zzzz.xxw..........................", ".........3344444zzzzyyx...........................", "..........444444...yyy............................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "4321056789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqsrtuvwxyz"; verify_case(4, Arg1, findOrder(Arg0)); }
  void test_case_5() { string Arr0[] = {"yyyyyyyyyyyyyyyyyy..", "yyyyyyyyyyyyyyyyyyTT", "yyyyyyyyyyyyyyyyyyTT", "yyyyyyyyyyyyyyyyyyTT", "yyyyyyyyyyyyyyyyyyTT", "yyyyyyyyyyyyyyyyyyTT", "mmFFFJppppp7777qJJV.", "mmFFFJpppwwwwwwwwwww", "mmFFFJpppwwwwwwwwwww", "eeeeeeeeewwwwwwwwwww", "eeeeeeeeewwwwwwwwwww", "eeeeeeeeewwwwwwwwwww", "eeeeeeeeeeelllllllll", "eeeeeeeeeeelllllllll", "eeeeeeeeeeelllllllll", "eeeeeeeeeeelllllllll", "eeeeeeeeeeelllllllll", "eeeeeeeeeeelllllllll", "eeeeeeeeeeeUUUjjjet6", "bvFAAAEEAAAUUUjjjAt3", "bvFGGGEEGGGUUUGG.NZ3", "bvFGGGEEGGGUUUGG.NN3", "..FGGGEEGGGGGGGG.NN."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "36FAGEJ7NTVZbeUjlmpqtvwy"; verify_case(5, Arg1, findOrder(Arg0)); }
 void test_case_6() { string Arr0[] = {
 "..AA..",
 ".CAA..",
 ".CAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AC"; verify_case(6, Arg1, findOrder(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TopView ___test;
  ___test.run_test(-1);
}
// END CUT HERE
