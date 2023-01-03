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
using namespace std;

class KingdomReorganization {
 public:
   struct Edge {
     int from;
     int to;
     int cost;
     Edge() : from(-1),to(-1),cost(-1) { }
     Edge(int from, int to, int cost) : from(from),to(to),cost(cost) { }
     bool operator<(const Edge& o) const {
       return cost < o.cost;
     }
   };
   int cost(char a) {
     if (a >= 'a' && a <= 'z')
       return a-'a'+26;
     return a-'A';
   }
  int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
    int mc = 0;
    vector<Edge> e;
    for (int i=0;i<kingdom.size();i++) {
      for (int j=i+1;j<kingdom.size();j++) {
        if (kingdom[i][j] == '1') {
          mc+=cost(destroy[i][j]);
          e.push_back(Edge(i,j,-cost(destroy[i][j])));
        } else {
          e.push_back(Edge(i,j,cost(build[i][j])));
        }
      }
    }
    sort(e.begin(),e.end());
    vector<int> color(kingdom.size());
    for (int i=0;i<color.size();i++) color[i] = i;
    for (int i=0;i<e.size();i++) {
      if (color[e[i].from] != color[e[i].to]) {
        mc+= e[i].cost;
        int oldc = color[e[i].to];
        for (int j=0;j<color.size();j++) if (color[j] == oldc) color[j] = color[e[i].from];
      }
    }
    return mc;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"011","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"011000","101000","110000","000011","000101","000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(2, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0001","0001","0001","1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AfOj","fAcC","OcAP","jCPA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AWFH","WAxU","FxAV","HUVA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 65; verify_case(5, Arg3, getCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingdomReorganization ___test;
  ___test.run_test(-1);
}
// END CUT HERE
