#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = 7;
// 
// END CUT HERE

class PilingRectsDiv1 {
 public:
  struct Rectangle {
    int x;
    int y;
    Rectangle(int x, int y) : x(x), y(y) {}
    bool operator<(const Rectangle& o) const {
      if (y != o.y) return y < o.y;
      return x < o.x;
    }
  };
  template <class T>
  class NthSmallest {
    multiset<T> left;
    multiset<T> right;
    int n;
   public:
    NthSmallest(int n) : n(n) {}
    void insert(T i) {
      if (left.size() < n) {
        left.insert(i);
        return;
      }
      left.insert(i);
      T elem = *left.rbegin();
      left.erase(left.find(elem));
      right.insert(elem);
    }
    T nth_smallest(int m) {
      while (left.size() > m) {
        T elem = *left.rbegin();
        left.erase(left.find(elem));
        right.insert(elem);
      }
      while (left.size() < m && right.size()) {
        T elem = *right.begin();
        right.erase(right.find(elem));
        left.insert(elem);
      }
      n = m;
      if (right.size()) return *right.begin();
      return *left.rbegin();
    }
    T min_elem() {
      if (left.size()) return *left.begin();
      return *right.begin();
    }
  };
  bool operator()(const Rectangle& a, const Rectangle& b) const {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  }
  long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {
    vector<int> X = vector<int>(2*N);
    vector<int> Y = vector<int>(2*N); 
    for (int i=0;i<XS.size();i++) {
      X[i] = XS[i];
      Y[i] = YS[i];
    }
    for (int i=XS.size();i<2*N;i++) {
      X[i] = ((LL)X[i-1] * XA + XB) % XC + 1;
      Y[i] = ((LL)Y[i-1] * YA + YB) % YC + 1;
    }
    // X always <= Y
    for (int i=0;i<X.size();i++)
      if (X[i] > Y[i])
        swap(X[i],Y[i]);
    vector<Rectangle> rectangles;
    for (int i=0;i<X.size();i++)
      rectangles.push_back(Rectangle(X[i],Y[i]));
    sort(rectangles.begin(),rectangles.end(),*this);
    for (int i=0;i<rectangles.size();i++)
      cout << i << ", x: " << rectangles[i].x << ", y: " << rectangles[i].y << endl;
    int lx = rectangles[0].x;
    LL mx = 0;
    NthSmallest<int> na(N); // we use two of these because it takes time
    NthSmallest<int> nb(N); // to swap between N-1 and N-i-1 all the time
    for (int i=N+1;i<rectangles.size();i++) {
      na.insert(rectangles[i].y);
      nb.insert(rectangles[i].y);
    }
    vector<int> minys;
    int miny = rectangles[0].y;
    minys.push_back(miny);
    for (int i=1;i<N;i++) {
      miny = min(miny,rectangles[i].y);
      minys.push_back(miny);
    }
    if (N == 1) return rectangles[0].x*rectangles[0].y+
                       rectangles[1].x*rectangles[1].y;
    for (int i=N-1;i>=0;i--) {
      // items up to i inclusive go left side
      na.insert(rectangles[i+1].y);
      nb.insert(rectangles[i+1].y);
      int ly = minys[i];
      int rx = rectangles[i+1].x;
      int ry = rectangles[i+1].y;
      int miny = na.min_elem();
      int nmin1 = na.nth_smallest(N-1);
      int nminimin1 = nb.nth_smallest(N-i-1);
      cout << ly << " " << miny << " " << nmin1 << " " << nminimin1 << endl;
      ly = min(ly,miny);
      ry = min(ry,nminimin1);
      mx = max(mx,(LL)lx*ly + (LL)rx*ry);
      ry = min(rectangles[i+1].y,miny);
      ly = min(minys[i],nmin1);
      mx = max(mx,(LL)lx*ly + (LL)rx*ry);
    }
    return mx;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing PilingRectsDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392409262;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PilingRectsDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int XS[] = {1,2,3,4};
				int YS[] = {10,5,3,5};
				int XA = 0;
				int XB = 0;
				int XC = 1;
				int YA = 0;
				int YB = 0;
				int YC = 1;
				_expected = 14LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 1:
			{
				int N = 2;
				int XS[] = {7,7};
				int YS[] = {4,4};
				int XA = 9;
				int XB = 0;
				int XC = 10;
				int YA = 2;
				int YB = 7;
				int YC = 9;
				_expected = 56LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 2:
			{
				int N = 3;
				int XS[] = {5,6,9,10,4,7};
				int YS[] = {9,5,8,6,8,7};
				int XA = 0;
				int XB = 0;
				int XC = 1;
				int YA = 0;
				int YB = 0;
				int YC = 1;
				_expected = 69LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 3:
			{
				int N = 10000;
				int XS[] = {1000000000};
				int YS[] = {1000000000};
				int XA = 93827162;
				int XB = 91238127;
				int XC = 98231267;
				int YA = 92138287;
				int YB = 98563732;
				int YC = 99381279;
				_expected = 1240119561532788LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 4:
			{
				int N = 5;
				int XS[] = {375,571,973,896,460,930,583,530,657,590};
				int YS[] = {284,37,994,699,941,745,166,884,270,708};
				int XA = 428;
				int XB = 1000;
				int XC = 788;
				int YA = 851;
				int YB = 125;
				int YC = 894;
				_expected = 420515LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 5:
			{
				int N = 34734;
				int XS[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974};
				int YS[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172};
				int XA = 569;
				int XB = 185;
				int XC = 285;
				int YA = 741;
				int YB = 304;
				int YC = 296;
				_expected = 10050LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 6:
			{
				int N = 1;
				int XS[] = {1};
				int YS[] = {1};
				int XA = 1;
				int XB = 1;
				int XC = 1;
				int YA = 1;
				int YB = 1;
				int YC = 1;
				_expected = 2LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 7:
			{
				int N = 2;
				int XS[] = {3,2,4,2};
				int YS[] = {1,2,2,2};
				int XA = 1;
				int XB = 1;
				int XC = 1;
				int YA = 1;
				int YB = 1;
				int YC = 1;
				_expected = 7LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 8:
			{
				int N = 1;
				int XS[] = {5,12};
				int YS[] = {9,2};
				int XA = 1;
				int XB = 2;
				int XC = 3;
				int YA = 1;
				int YB = 2;
				int YC = 3;
				_expected = 69LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
