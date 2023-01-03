#include <iostream>
#include <vector>
using namespace std;

const int md = 1e9+7;
int pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x*x % md;
    if (step & b) x = (long long)x*a % md;
    step >>= 1;
  }
  return x;
}

int inv[3010];

int main() {
  for (int i=0;i<=3000;i++) inv[i] = pw(i, md-2);
  for (int i=0;i<=20;i++) {
  int f = 1;
  for (int u=1;u<=3;u++) f = (long long)f * (i-u+1) % md;
  for (int u=1;u<=3;u++) f = (long long)f * inv[u] % md;
  cout << f << ",";
}
cout << endl;
}
