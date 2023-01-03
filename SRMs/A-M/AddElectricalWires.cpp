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
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class AddElectricalWires {
 public:
  int n;
  vector<string> wires;
  vector<bool> seen;
  vector<int> counts;
  void markas(int idx, int gridi) {
    counts[gridi]++;
    seen[idx] = true;
    for (int i=0;i<n;i++)
      if (wires[idx][i] == '1' && !seen[i])
        markas(i,gridi);
  }
  int maxNewWires(vector <string> wires, vector <int> gridConnections) {
    // for every connected component you can have n*(n-1) connections
    // there are gridConnections.size() connected components
    // consider each component individually
    // and add the unconnected nodes to the largest connected component
    this->wires = wires;
    n = wires.size();
    seen = vector<bool>(n,false);
    counts = vector<int>(gridConnections.size(),0);
    int c = 0;
    for (int i=0;i<gridConnections.size();i++)
      markas(gridConnections[i],c++);
    int unconnected = 0;
    for (int i=0;i<seen.size();i++)
      unconnected += !seen[i];
    sort(counts.rbegin(),counts.rend());
    counts[0]+=unconnected;
    int totcons = 0;
    for (int i=0;i<counts.size();i++)
      totcons += counts[i]*(counts[i]-1)/2;
    for (int i=0;i<n;i++)
      for (int j=i+1;j<n;j++)
        totcons -= wires[i][j] == '1';
    return totcons;
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
		cout << "Testing AddElectricalWires (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389801662;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AddElectricalWires _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string wires[] = {"000","000","000"};
				int gridConnections[] = {0};
				_expected = 3;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 1:
			{
				string wires[] = {"000","000","000"};
				int gridConnections[] = {0,1};
				_expected = 1;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 2:
			{
				string wires[] = {"01","10"};
				int gridConnections[] = {0};
				_expected = 0;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 3:
			{
				string wires[] = {"00000","00000","00000","00000","00000"};
				int gridConnections[] = {0,1,2,3,4};
				_expected = 0;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 4:
			{
				string wires[] = {"01000","10100","01010","00100","00000"};
				int gridConnections[] = {2,4};
				_expected = 3;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 5:
			{
				string wires[] = {"00000000001000000100000000000000000000000000000000", "00111000000000000000000000000001001000000000000010", "01011000000000000000000000000001001000000000000010", "01101000000000000000000000000001001000000000000010", "01110000000000000000000000000001001000000000000010", "00000000000000000000000000000000000000000000000000", "00000000000001010000000000000000000000000000000000", "00000000000000000000000000011000010100000000000000", "00000000000000000000010101000000100000000000000000", "00000000000000000000000000000000000000000101100000", "10000000000000000100000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "00000010000000010000000000000000000000000000000000", "00000000000000000010000000000100000000000000000000", "00000010000001000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "10000000001000000000000000000000000000000000000000", "00000000000000100000000000000100000000000000000000", "00000000000000000000000010000010000010000010000000", "00000000000000000000000000000000000000000000000000", "00000000100000000000000101000000100000000000000000", "00000000000000000000000000000000000000000000000000", "00000000100000000000010001000000100000000000000000", "00000000000000000001000000000010000010000010000000", "00000000100000000000010100000000100000000000000000", "00000000000000000000000000000000000000000000000000", "00000001000000000000000000001000010100000000000000", "00000001000000000000000000010000010100000000000000", "00000000000000100010000000000000000000000000000000", "00000000000000000001000010000000000010000010000000", "01111000000000000000000000000000001000000000000010", "00000000100000000000010101000000000000000000000000", "00000001000000000000000000011000000100000000000000", "01111000000000000000000000000001000000000000000010", "00000001000000000000000000011000010000000000000000", "00000000000000000001000010000010000000000010000000", "00000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000001000", "00000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "00000000010000000000000000000000000000000001100000", "00000000000000000001000010000010000010000000000000", "00000000010000000000000000000000000000000100100000", "00000000010000000000000000000000000000000101000000", "00000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000100000000000", "00000000000000000000000000000000000000000000000000", "01111000000000000000000000000001001000000000000000", "00000000000000000000000000000000000000000000000000"};
				int gridConnections[] = {43, 35, 25, 49, 29, 38, 13, 42, 10, 3};
				_expected = 150;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			/*case 6:
			{
				string wires[] = ;
				int gridConnections[] = ;
				_expected = ;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string wires[] = ;
				int gridConnections[] = ;
				_expected = ;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
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
