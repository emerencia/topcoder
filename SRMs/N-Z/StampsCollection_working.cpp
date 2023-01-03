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
const int tt = -1;
// 18:51
// END CUT HERE
bool g[51][51];
LL mem[51][2][2];

class StampsCollection {
 public:
  int m;
  vector<int> path;
  vector<int> marked;
  vector<int> price;
  void dfs(int node, vector<int>& tpath) {
    bool nya = true;
    for (int i=0;i<m;i++)
      if (g[node][i] && marked[i] == -1) {
        marked[i] = marked[node];
        dfs(i,tpath);
        if (nya) {
          // in-order traversal to ensure
          // that connected nodes appear
          // in adjacent indices in the path vector
          tpath.push_back(node);
          nya = false;
        }
      }
    if (nya) tpath.push_back(node);
  }
  LL rec(int idx, int usedprev, int usedfirst) {
    LL& r = mem[idx][usedprev][usedfirst];
    if (r != -1) return r;
    if (idx == path.size()) return r = 0;
    LL t = 0;
    if (idx == 0) {
      if (usedfirst) t = price[path[idx]]+rec(idx+1,1,usedfirst);
      else t = rec(idx+1,0,usedfirst);
    } else if (idx+1 == path.size()) {
      t = rec(idx+1,0,usedfirst);
      if ((!usedprev || !g[path[idx-1]][path[idx]]) &&
          (!usedfirst || !g[path[0]][path.back()]))
        t = max(t,price[path[idx]]+rec(idx+1,1,usedfirst));
    } else {
      t = rec(idx+1,0,usedfirst);
      if (!usedprev || !g[path[idx-1]][path[idx]])
        t = max(t,price[path[idx]]+rec(idx+1,1,usedfirst));
    }
    return r = t;
  }
  int sell(int n, vector <string> deman, vector <int> price) {
    this->price = price;
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
      vector<int> marked2 = marked;
      marked[i] = c++;
      path.clear();
      dfs(i,path);
      // now we determined the starting point of the sequence
      // so run dfs again to find a properly ordered sequence
      int realfirst = path[0];
      path.clear();
      marked = marked2;
      marked[realfirst] = c-1;
      dfs(realfirst,path);
      memset(mem,-1,sizeof(mem));
      LL rinc = max(rec(0,0,0),rec(0,0,1));
      r+=rinc;
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
      case 10:
		  {
				int n = 50;
				string demand[] = {"17", "35 27", "9 23", "41 1", "4", "36", "45", "12 14", "16 0", "18 39", "38 40", "44 9", "32 22", "3 34", "46", "36", "40 0", "4 12", "18 25", "20 48", "11", "27 34", "38 16", "33", "46 33", "39", "35 24", "17 1", "29 7", "19", "7 25", "23 28", "8 47", "31 32", "20 49", "5 26", "8 24", "42 43", "28", "26 2", "15", "43 15", "44 48", "13 21", "21 42", "47", "3 30", "2", "22 10", "5"};
				int price[] = {1, 2, 2, 4, 5, 2, 2, 1, 2, 2, 5, 4, 3, 4, 5, 5, 3, 1, 5, 2, 1, 5, 5, 3, 1, 2, 5, 5, 4, 2, 5, 1, 3, 1, 5, 2, 2, 1, 4, 5, 4, 3, 1, 2, 2, 5, 3, 1, 2, 5};
				_expected = 99;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
      case 11:
		  {
				int n = 50;
				string demand[] = {"42 38", "2 32", "41 18", "28 32", "11 17", "14 31", "16 44", "41", "14 2", "10 13", "9 6", "17 10", "35 25", "25 11", "8", "5 4", "8 46", "3", "12 27", "26 15", "34", "38 43", "45 18", "21 30", "31 35", "40 16", "20 19", "40 36", "5", "37 22", "43 3", "21 1", "47 22", "27 42", "34", "29 47", "36 15", "20", "29 33", "30 12", "28 13", "19 33", "48 4", "45", "46 26", "9 1", "24 7", "37 39", "48 6", "0 44"};
				int price[] = {4, 1, 3, 5, 1, 5, 2, 4, 1, 2, 1, 2, 2, 1, 4, 4, 2, 5, 3, 4, 2, 5, 1, 4, 3, 4, 5, 1, 1, 5, 5, 5, 5, 5, 4, 3, 4, 2, 1, 1, 4, 2, 2, 2, 2, 1, 5, 5, 2, 3};
				_expected = 90;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
      case 9:
		  {
				int n = 50;
				string demand[] = {"11 20", "16 30", "45 36", "31 49", "38 33", "19 33", "25", "48", "32 13", "38", "14 27", "41 44", "11 3", "43 21", "31 20", "2 41", "36 18", "0 15", "1 16", "30 9", "17 22", "21", "17 34", "48 25", "7 34", "43 22", "8", "14 44", "39 26", "10 6", "46 13", "4 27", "40 28", "47", "39 46", "35", "37 19", "37 5", "9 3", "24", "10 6", "40 4", "29 45", "8", "24 15", "12 1", "2 28", "0", "12 32", "42"};
				int price[] = {2, 1, 5, 5, 1, 2, 1, 3, 2, 1, 4, 5, 1, 1, 5, 4, 5, 1, 3, 2, 4, 5, 4, 3, 2, 2, 4, 5, 5, 3, 5, 3, 5, 2, 3, 2, 3, 3, 4, 2, 5, 2, 3, 1, 5, 4, 1, 4, 4, 5};
				_expected = 101;
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
