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

class PlatypusDuckAndBeaver {
 public:
  int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
    // duck   = 2 webbed feet, 1 duck bill, 0 beaver tail
    // beaver = 4 webbed feet, 0 duck bill, 1 beaver tail
    // plat   = 4 webbed feet, 1 duck bill, 1 beaver tail
    // duckbills   = ducks + plats
    // webbedFeet  = 2*ducks + 4*beavers + 4*plats
    // beaverTails = plats + beavers
    // duckbills-beavertails = ducks-beavers
    // 4* webbedFeet = 2*ducks + beavers + plats
    // 4*webbedFeet-duckBills = ducks + beavers
    // (4*webbedFeet-beaverTails)/2 = ducks
    //int ducks = (4*webbedFeet-beaverTails)/2;
    //int plats = duckBills-ducks;
    //int beavers = beaverTails-plats;
    // webbedFeet/2 = ducks + 2*beavers+ 2*plats
    // beavers+plats = beavertails
    // ducks+plats = duckBills
    int beavers = webbedFeet/2 -duckBills -beaverTails;
    int plats = beaverTails-beavers;
    int ducks = duckBills-plats;
    return ducks+plats+beavers;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 2; int Arg3 = 3; verify_case(2, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 60; int Arg1 = 10; int Arg2 = 10; int Arg3 = 20; verify_case(3, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 200; int Arg2 = 200; int Arg3 = 300; verify_case(4, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PlatypusDuckAndBeaver ___test;
  ___test.run_test(-1);
}
// END CUT HERE
