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
const int tt = -1;
// 
// END CUT HERE

class FindingSquareInTable {
 public:
  void insertreverse(set<int>& a, string s) {
    stringstream b(s);
    int c;
    b >> c;
    a.insert(c);
    reverse(s.begin(),s.end());
    stringstream d(s);
    d >> c;
    a.insert(c);
  }
  int findMaximalSquare(vector <string> table) {
    set<int> a;
    for (int i=0;i<table.size();i++)
      for (int j=0;j<table[0].size();j++) {
        // row string
        string s = string(1,table[i][j]);
        for (int k=j+1;k<table[0].size();k++)
          s+=table[i][k];
        insertreverse(a,s);
        s = string(1,table[i][j]);
        for (int k=i+1;k<table.size();k++)
          s+=table[k][j];
        insertreverse(a,s);
        for (int k=-9;k<9;k++)
          for (int l=-9;l<9;l++) {
            s = string(1,table[i][j]);
            insertreverse(a,s);
            for (int c=1;c<9;c++) {
              int ni = i+k*c;
              int nj = j+l*c;
              if (ni < table.size() && nj < table[0].size()) {
                s+=table[ni][nj];
                insertreverse(a,s);
              }
            }
          }
      }
    int maxnt = *max_element(a.begin(),a.end());
    int r = -1;
    if (a.count(0)) r = 0;
    for (int i=1;i*i<=maxnt;i++)
      if (a.count(i*i))
        r = i*i;
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
		cout << "Testing FindingSquareInTable (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393945894;
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
		FindingSquareInTable _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"123",
				                  "456"};
				_expected = 64;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"00000",
				                  "00000",
				                  "00200",
				                  "00000",
				                  "00000"};
				_expected = 0;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"3791178",
				                  "1283252",
				                  "4103617",
				                  "8233494",
				                  "8725572",
				                  "2937261"};
				_expected = 320356;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"135791357",
				                  "357913579",
				                  "579135791",
				                  "791357913",
				                  "913579135"};
				_expected = 9;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 4:
			{
				string table[] = {"553333733",
				                  "775337775",
				                  "777537775",
				                  "777357333",
				                  "755553557",
				                  "355533335",
				                  "373773573",
				                  "337373777",
				                  "775557777"};
				_expected = -1;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 5:
			{
				string table[] = {"257240281",
				                  "197510846",
				                  "014345401",
				                  "035562575",
				                  "974935632",
				                  "865865933",
				                  "684684987",
				                  "768934659",
				                  "287493867"};
				_expected = 95481;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
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
