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
typedef pair<char,int> PCI;
typedef pair<long long,PCI> PLLC;
int mem[51][101][3];

// this is wrong

class EelAndRabbit {
 public:
  int rec(vector<PLLC>& events,int idx, int fishin, int left) {
    // cout << idx << " " << fishin << " " << left << endl;
    if (left == 0) return 0;
    if (idx == events.size()) return fishin-50;
    int& r = mem[idx][fishin][left];
    if (r != -1) return r;
    int oidx = idx;
    int ofishin = fishin;
    while (idx < events.size() && events[idx].first == events[oidx].first) {
      fishin+= (events[idx].second.first == 'a' ? 1 : (events[idx].second.first == 'e' ? -1 : 0));
      ofishin+= (events[idx].second.first == 'a' ? 1 : 0);
      idx++;
    }
    int r1 = 0;
    if (ofishin > 50) {
      vector<PLLC> events2 = events;
      int c = ofishin - 50;
      vector<bool> indices(51,false);
      for (int i=idx;i<events2.size();i++) {
        if (events2[i].second.first == 'a') {
          indices[events2[i].second.second] = true;
        }
        if (events2[i].second.first == 'e' && !indices[events2[i].second.second]) {
          events2[i].second.first = 'b';
        }
      }
      r1 = c+rec(events2,idx,50,left-1);
    }
    int r2 = rec(events,idx,fishin,left);
    return r = max(r1,r2);
  }
  int getmax(vector<int> l, vector<int> t) {
    vector<PLLC> events;
    for (int i=0;i<l.size();i++) {
      events.push_back(PLLC(t[i],PCI('a',i)));
      events.push_back(PLLC(t[i]+l[i],PCI('e',i)));
    }
    memset(mem,-1,sizeof(mem));
    sort(events.begin(),events.end());
    return rec(events,0,50,2);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 4, 3, 2, 2, 1, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 6, 3, 7, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EelAndRabbit ___test;
  ___test.run_test(-1);
}
// END CUT HERE
