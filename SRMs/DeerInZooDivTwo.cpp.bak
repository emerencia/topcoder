#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// 00:56 - 01:06

class DeerInZooDivTwo {
 public:
  vector<int> getminmax(int N, int K) {
    vector<int> r;
    r.push_back(max(0,N-K));
    r.push_back(max(0,N-K/2-K%2));
    return r;
  }
};

int idx = 0;

string vector_to_string(const vector<int>& a) {
  string s;
  for (int i=0;i+1<a.size();i++)
    s+= a[i]+", ";
  if (a.size()) s+= a.back();
  return s;
}
void print_result(const vector<int>& expected, const vector<int>& received) {
  if (expected == received)
    cout << "TEST " << idx << " PASSED" << endl;
  else {
    cout << "TEST " << idx << " FAILED" << endl;
    cout << "  expected: " << vector_to_string(expected) << endl;
    cout << "  received: " << vector_to_string(received) << endl;
  }
  idx++;
}

int main() {
  DeerInZooDivTwo a;
  vector<int> b;
  b.push_back(1);
  b.push_back(2);
  print_result(b,a.getminmax(3,2));
  b.clear();
  b.push_back(0);
  b.push_back(1);
  print_result(b,a.getminmax(3,3));
  b.clear();
  b.push_back(10);
  b.push_back(10);
  print_result(b,a.getminmax(10,0));
  b.clear();
  b.push_back(333);
  b.push_back(493);
  print_result(b,a.getminmax(654,321));
  b.clear();
  b.push_back(0);
  b.push_back(3);
  print_result(b,a.getminmax(100,193));
}