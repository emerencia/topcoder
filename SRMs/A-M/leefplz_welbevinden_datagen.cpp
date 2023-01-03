#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

double mean(const vector<double>& a) {
  double tot = 0.0;
  for (int i=0;i<a.size();i++) {
    tot+=a[i];
  }
  return tot/a.size();
}
double stddev(const vector<double>& a) {
  double mn = mean(a);
  double sd = 0.0;
  for (int i=0;i<a.size();i++) {
    sd += (a[i]-mn)*(a[i]-mn);
  }
  sd = sqrt(sd/max(1,int(a.size()-1)));
  return sd;
}
void normalize(vector<double>& a,double mu, double sigma) {
  double mn = mean(a);
  double sd = stddev(a);
  for (int i=0;i<a.size();i++) {
    a[i] = mu+sigma*(a[i]-mn)/sd;
  }
}
int main() {
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  normal_distribution<> distribution (0,1); // mean, std
  vector<double> m = vector<double>();
  for (int i=0;i<30;i++)
    m.push_back(distribution(generator));
  normalize(m,0,1);
  cout << "[";
  for (int i=0;i<m.size();i++) {
    cout << m[i] << (i+1 == m.size() ? "];" : ", ");
    if (!(i%9)) cout << endl;
  }
  cout << endl;
}
