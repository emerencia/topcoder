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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long LL;
typedef pair<int,LL> PLL;
// BEGIN CUT HERE
const int tt = 8;
// 18:51
// END CUT HERE
bool g[51][51];

class StampsCollection {
 public:
  int m;
  vector<int> marked;
  void dfs(int node, vector<int>& path) {
    path.push_back(node);
    for (int i=0;i<m;i++)
      if (g[node][i] && marked[i] == -1) {
        marked[i] = marked[node];
        return dfs(i,path);
      }
  }
  int sell(int n, vector <string> deman, vector <int> price) {
    this->m = price.size();
    vector<vector<int> > wantedby = vector<vector<int> >(n);
    for (int i=0;i<deman.size();i++) {
      stringstream a(deman[i]);
      while (!a.eof()) {
        int c;
        a >> c;
        wantedby[c].push_back(i);
      }
    }
    memset(g,0,sizeof(g));
    for (int i=0;i<wantedby.size();i++)
      if (wantedby[i].size() == 2) {
        g[wantedby[i][0]][wantedby[i][1]] = 1;
        g[wantedby[i][1]][wantedby[i][0]] = 1;
      }
    marked = vector<int>(price.size(),-1);
    int c = 0;
    LL r = 0;
    for (int i=0;i<price.size();i++) {
      if (marked[i] != -1) continue;
      marked[i] = c++;
      vector<int> path;
      dfs(i,path);
      
      cout << "path size: " << path.size() << endl;
      for (int j=0;j<path.size();j++)
        cout << path[j] << ": " << deman[path[j]] <<
            "\t\t" << price[path[j]] << endl;
      
      if (path.size()%2) {
        // odd: try for every starting val
        LL rmax = 0;
        if (!g[path[0]][path.back()]) {
          // also try odds and evens if start and end don't connect
          vector<LL> rways(2,0);
          for (int j=0;j<path.size();j++)
            rways[j%2]+=price[path[j]];
          rmax = max(rways[0],rways[1]);
        }
        for (int k=0;k<path.size();k++) {
          LL rcur = 0;
          for (int j=0;j<path.size()/2;j++)
            rcur+=price[path[(k+2*j)%path.size()]];
          if (rcur == 0) rcur = price[path[k]];
          rmax = max(rmax,rcur);
        }
        cout << "added1: " << rmax << endl << endl;
        r+=rmax;
      } else { // even: only two possibilities: odds and evens
        vector<LL> rways(2,0);
        for (int j=0;j<path.size();j++)
          rways[j%2]+=price[path[j]];
        cout << "added2: " << max(rways[0],rways[1]) << endl << endl;
        r+=max(rways[0],rways[1]);
      }
    }
    return r;
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
		cout << "Testing StampsCollection (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391531789;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StampsCollection _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 10;
				string demand[] = {"0 4"};
				int price[] = {3};
				_expected = 3;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				string demand[] = {"1 0","0"};
				int price[] = {3,5};
				_expected = 5;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				string demand[] = {"0 1","0 2","1 2"};
				int price[] = {10,11,12};
				_expected = 12;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 3;
				string demand[] = {"0","1 0","1 2"};
				int price[] = {5,9,5};
				_expected = 10;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 20;
				string demand[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"};
				int price[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5};
				_expected = 40;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 50;
				string demand[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49"}
;
				int price[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				_expected = 50000000;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 50;
				string demand[] = {"0", "1", "1", "2", "2 3", "3", "4", "4 5", "5 6", "6", "7", "7 8", "8 9", "9 10", "10", "11", "11 12", "12 13", "13 14", "14 15", "15", "16", "16 17", "17 18", "18 19"};
				int price[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 14;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 25;
				string demand[] = {"0", "0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "10", "10", "11", "11", "12", "12", "13", "13", "14", "14", "15", "15", "16", "16", "17", "17", "18", "18", "19", "19", "20", "20", "21", "21", "22", "22", "23", "23", "24", "24"};
				int price[] = {100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99};
				_expected = 2500;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
      case 8:
		  {
				int n = 21;
				string demand[] = {"0", "0 2", "2 4", "4 6", "8 6", "8", "1 3", "1 5", "5 7", "7 9", "9 10", "10 11", "12 13", "13 14", "14 15", "15 20", "20 12"};
				int price[] = {3, 7, 3, 1, 3, 1, 5, 7, 3, 2, 3, 2, 7, 1, 1, 7, 10};
				_expected = 35;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
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
