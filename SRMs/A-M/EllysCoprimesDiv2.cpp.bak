#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 00:36
class EllysCoprimesDiv2 {
 public:
  int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  int getCount(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int c = 0;
    for (int i=0;i+1<numbers.size();i++)
      if (gcd(numbers[i],numbers[i+1]) > 1) {
        ++c;
        bool found = false;
        for (int j=numbers[i]+1;j<numbers[i+1];j++)
          if (gcd(numbers[i],j) == 1 && gcd(numbers[i+1],j) == 1) {
            found = true;
            break;
          }
        if (!found) ++c;
      }
    return c;
  }
};

int idx = 0;

void print_result(int expected,int received) {
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
  EllysCoprimesDiv2 a;
  vector<int> b;
  b.push_back(2200);
  b.push_back(42);
  b.push_back(2184);
  b.push_back(17);
  print_result(3,a.getCount(b));
  b.clear();
  b.push_back(13);
  b.push_back(1);
  b.push_back(6);
  b.push_back(20);
  b.push_back(33);
  print_result(0,a.getCount(b));
  b.clear();
  b.push_back(7);
  b.push_back(42);
  print_result(1,a.getCount(b));
  b.clear();
  b.push_back(55780);
  b.push_back(44918);
  b.push_back(55653);
  b.push_back(4762);
  b.push_back(41536);
  b.push_back(40083);
  b.push_back(79260);
  b.push_back(7374);
  b.push_back(24124);
  b.push_back(91858);
  b.push_back(7856);
  b.push_back(12999);
  b.push_back(64025);
  b.push_back(12706);
  b.push_back(19770);
  b.push_back(71495);
  b.push_back(32817);
  b.push_back(79309);
  b.push_back(53779);
  b.push_back(8421);
  b.push_back(97984);
  b.push_back(34586);
  b.push_back(893);
  b.push_back(64549);
  b.push_back(77792);
  b.push_back(12143);
  b.push_back(52732);
  b.push_back(94416);
  b.push_back(54207);
  b.push_back(51811);
  b.push_back(80845);
  b.push_back(67079);
  b.push_back(14829);
  b.push_back(25350);
  b.push_back(22976);
  b.push_back(23932);
  b.push_back(62273);
  b.push_back(58871);
  b.push_back(82358);
  b.push_back(13283);
  b.push_back(33667);
  b.push_back(64263);
  b.push_back(1337);
  b.push_back(42666);
  print_result(15,a.getCount(b));
}
