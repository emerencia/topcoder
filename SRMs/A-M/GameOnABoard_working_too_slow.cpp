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
//22:20-23:36

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int cost[1600];

class GameOnABoard {
 public:
  int n;
  int m;
  vector<string> costings;
  void dfs(int cur,vector<int>& whichseg,vector<int>& zerosegments, int pos) {
    int iii = cur/m;
    int jjj = cur%m;
    whichseg[cur] = pos;
    zerosegments.push_back(cur);
    for (int l=0;l<4;l++) {
      if (iii+dx[l] >= 0 && iii + dx[l] < n && jjj+dy[l] >= 0 && jjj+dy[l] < m) {
        int ni = (iii+dx[l])*m+(jjj+dy[l]);
        if (whichseg[ni] != -1 || costings[iii+dx[l]][jjj+dy[l]] == '1') continue;
        dfs(ni,whichseg,zerosegments,pos);
      }
    }
  }
  int optimalChoice(vector <string> costings) {
    this->costings = costings;
    n = costings.size();
    m = costings[0].size();
    vector<vector<int> > zerosegments;
    vector<int> whichseg(n*m,-1);
    for (int i=0;i<n*m;i++) {
      int ii = i/m;
      int jj = i%m;
      if (costings[ii][jj] == '0' && whichseg[i] == -1) {
        zerosegments.push_back(vector<int>());
        dfs(i,whichseg,zerosegments[zerosegments.size()-1],zerosegments.size()-1);
      }
    }
    int minc = 1e9;
    for (int i = 0;i<n*m;i++) {
      int ii = i/m;
      int jj = i%m;
      memset(cost,-1,sizeof(cost));
      cost[i] = (costings[ii][jj] == '1');
      for (int k=0;k<80;k++)
        for (int j = 0;j<n*m;j++) {
          if (cost[j] == -1) continue;
          int iii = j/m;
          int jjj = j%m;
          for (int l=0;l<4;l++) {
            if (iii+dx[l] >= 0 && iii + dx[l] < n && jjj+dy[l] >= 0 && jjj+dy[l] < m) {
              int ni = (iii+dx[l])*m+(jjj+dy[l]);
              int tcost = (costings[iii+dx[l]][jjj+dy[l]] == '1');
              if (cost[ni] == -1 || cost[j]+tcost < cost[ni]) {
                cost[ni] = cost[j]+tcost;
                if (!tcost) {
                  int seg = whichseg[ni];
                  for (int e=0;e<zerosegments[seg].size();e++)
                    if (cost[zerosegments[seg][e]] == -1 || cost[zerosegments[seg][e]] > cost[j])
                      cost[zerosegments[seg][e]] = cost[j];
                }
              }
            }
          }
        }
      int maxc = 0;
      for (int j=0;j<n*m;j++) {
        // if (cost[j] == -1) cout << "error" << endl;
        if (cost[j] != -1 && cost[j] > maxc)
          maxc = cost[j];
      }
      minc = min(minc,maxc);
    }
    return minc;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, optimalChoice(Arg0)); }
	void test_case_1() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, optimalChoice(Arg0)); }
	void test_case_2() { string Arr0[] = {"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, optimalChoice(Arg0)); }
	void test_case_3() { string Arr0[] = {"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, optimalChoice(Arg0)); }
	void test_case_4() { string Arr0[] = {"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, optimalChoice(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GameOnABoard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
