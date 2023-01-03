#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

// 01:08 - 01:27

const int kMod = 1e9+7;
int g[105][105];
int h[105][105];

class GooseInZooDivTwo {
 public:
  int count(vector<string> field, int dist) {
    memset(g,0,sizeof(g));
    memset(h,0,sizeof(h));
    bool foundsomething = false;
    for (int i=0;i<field.size();i++)
      for (int j=0;j<field[0].size();j++) {
        if (field[i][j] == '.') continue;
        for (int k=0;k<field.size();k++)
          for (int l=0;l<field[0].size();l++) {
            if (field[k][l] == '.') continue;
            if (abs(i-k)+abs(j-l) <= dist) {
              foundsomething = true;
              g[i+j][k+l] = 1;
              h[i-j+50][k-l+50] = 1;
            }
          }
      }
    if (!foundsomething) return 0;
    for (int k=0;k<105;k++)
      for (int i=0;i<105;i++)
        for (int j=0;j<105;j++)
          if (g[i][k] && g[k][j])
            g[i][j] = 1;
    for (int k=0;k<105;k++)
      for (int i=0;i<105;i++)
        for (int j=0;j<105;j++)
          if (h[i][k] && h[k][j])
            h[i][j] = 1;
    int c = 0;
    vector<vector<bool> > seen(105,vector<bool>(105,false));
    for (int i=0;i<50;i++) {
      for (int j=0;j<50;j++) {
        if (seen[i+j][i-j+50]) continue;
        bool seensomething = false;
        for (int k=0;k<50;k++)
          for (int l=0;l<50;l++)
            if (g[i+j][k+l] && h[i-j+50][k-l+50]) {
              seensomething = true;
              seen[k+l][k-l+50] = 1;
            }
        if (seensomething) c++;
      }
    }
    cout << "c: " << c << endl;
    if (c == 0) return 0;
    long long r = 1;
    for (int i=0;i+1<c;i++)
      r = (r*2)%kMod;
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
