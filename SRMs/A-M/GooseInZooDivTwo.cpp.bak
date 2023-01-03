#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

// 01:08 - 01:27

const int kMod = 1e9+7;
int g[2501][2501];

class GooseInZooDivTwo {
 public:
  vector<bool> seen;
  vector<bool> bird;
  void dfs(int v) {
    seen[v] = 1;
    for (int i=0;i<2500;i++)
      if (!seen[i] && bird[i] && g[v][i])
        dfs(i);
  }
  int count(vector<string> field, int dist) {
    memset(g,0,sizeof(g));
    bool foundsomething = false;
    bird = vector<bool>(2501,false);
    for (int i=0;i<field.size();i++)
      for (int j=0;j<field[0].size();j++) {
        if (field[i][j] == '.') continue;
        bird[i*50+j] = 1;
        for (int k=0;k<field.size();k++)
          for (int l=0;l<field[0].size();l++) {
            if (field[k][l] == '.') continue;
            if (abs(i-k)+abs(j-l) <= dist) {
              foundsomething = true;
              g[i*50+j][k*50+l] = 1;
            }
          }
      }
    if (!foundsomething) return 0;
    seen = vector<bool>(2501,false);
    int c = 0;
    for (int i=0;i<seen.size();i++) {
      if (!bird[i]) continue;
      if (seen[i]) continue;
      c++;
      dfs(i);
    }
    if (c == 0) return 0;
    long long r = 1;
    for (int i=0;i<c;i++)
      r = (r*2)%kMod;
    r--;
    return r;
  }
};

int idx = 0;

void print_result(int expected, int received) {
  if (expected == received)
    cout << "TEST " << idx << " PASSED" << endl;
  else {
    cout << "TEST " << idx << " FAILED" << endl;
    cout << "  expected: " << expected << endl;
    cout << "  received: " << received << endl;
  }
  idx++;
}

int main() {
  GooseInZooDivTwo a;
  vector<string> b;
  b.push_back("vvv");
  print_result(7,a.count(b,0));
  b.clear();
  b.push_back(".");
  print_result(0,a.count(b,100));
  b.clear();
  b.push_back("vvv");
  print_result(1,a.count(b,1));
  b.clear();
  b.push_back("v.v..................v............................");
  b.push_back(".v......v..................v.....................v");
  b.push_back("..v.....v....v.........v...............v......v...");
  b.push_back(".........vvv...vv.v.........v.v..................v");
  b.push_back(".....v..........v......v..v...v.......v...........");
  b.push_back("...................vv...............v.v..v.v..v...");
  b.push_back(".v.vv.................v..............v............");
  b.push_back("..vv.......v...vv.v............vv.....v.....v.....");
  b.push_back("....v..........v....v........v.......v.v.v........");
  b.push_back(".v.......v.............v.v..........vv......v.....");
  b.push_back("....v.v.......v........v.....v.................v..");
  b.push_back("....v..v..v.v..............v.v.v....v..........v..");
  b.push_back("..........v...v...................v..............v");
  b.push_back("..v........v..........................v....v..v...");
  b.push_back("....................v..v.........vv........v......");
  b.push_back("..v......v...............................v.v......");
  b.push_back("..v.v..............v........v...............vv.vv.");
  b.push_back("...vv......v...............v.v..............v.....");
  b.push_back("............................v..v.................v");
  b.push_back(".v.............v.......v..........................");
  b.push_back("......v...v........................v..............");
  b.push_back(".........v.....v..............vv..................");
  b.push_back("................v..v..v.........v....v.......v....");
  b.push_back("........v.....v.............v......v.v............");
  b.push_back("...........v....................v.v....v.v.v...v..");
  b.push_back("...........v......................v...v...........");
  b.push_back("..........vv...........v.v.....................v..");
  b.push_back(".....................v......v............v...v....");
  b.push_back(".....vv..........................vv.v.....v.v.....");
  b.push_back(".vv.......v...............v.......v..v.....v......");
  b.push_back("............v................v..........v....v....");
  b.push_back("................vv...v............................");
  b.push_back("................v...........v........v...v....v...");
  b.push_back("..v...v...v.............v...v........v....v..v....");
  b.push_back("......v..v.......v........v..v....vv..............");
  b.push_back("...........v..........v........v.v................");
  b.push_back("v.v......v................v....................v..");
  b.push_back(".v........v................................v......");
  b.push_back("............................v...v.......v.........");
  b.push_back("........................vv.v..............v...vv..");
  b.push_back(".......................vv........v.............v..");
  b.push_back("...v.............v.........................v......");
  b.push_back("....v......vv...........................v.........");
  b.push_back("....vv....v................v...vv..............v..");
  b.push_back("..................................................");
  b.push_back("vv........v...v..v.....v..v..................v....");
  b.push_back(".........v..............v.vv.v.............v......");
  b.push_back(".......v.....v......v...............v.............");
  b.push_back("..v..................v................v....v......");
  b.push_back(".....v.....v.....................v.v......v.......");
  print_result(797922654,a.count(b,3));
}
