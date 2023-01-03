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

class Algrid {
 public:
  vector <string> makeProgram(vector <string> output) {
    vector<string> r = output;
    for (int i=0;i+1<output.size();i++) {
      for (int j=output[0].size()-2;j>=0;j--) {
        if (output[i][j] == 'W' && output[i][j+1] == 'W') {
          //r[i+1][j] = output[i+1][j];
          //r[i+1][j+1] = output[i+1][j+1];
        } else if (output[i][j] == 'B' && output[i][j+1] == 'W') {
          if (r[i+1][j] == 'W' || r[i+1][j+1] == 'W') return vector<string>();
          r[i+1][j] = 'X';
          r[i+1][j+1] = 'X';
        } else if (output[i][j] == 'W' && output[i][j+1] == 'B') {
          if (r[i+1][j] == 'B' || r[i+1][j+1] == 'B') return vector<string>();
          r[i+1][j] = 'X';
          r[i+1][j+1] = 'X';
        } else { // BB
          swap(r[i+1][j],r[i+1][j+1]);
        }
      }
    }
    for (int i=0;i<r.size();i++)
      for (int j=0;j<r[0].size();j++)
        if (r[i][j] == 'X')
          r[i][j] = 'B';
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
		cout << "Testing Algrid (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390300308;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Algrid _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string output[] = {"WWWWWWW",
				                   "WWWWWWB",
				                   "BBBBBWW"};
				string __expected[] = {"WWWWWWW", "WWWWWWB", "BBBBBBB" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}
			case 1:
			{
				string output[] = {"BBBBB",
				                   "WBWBW"};
				string __expected[] = {"BBBBB", "WWBWB" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}
			case 2:
			{
				string output[] = {"BBBB",
				                   "BBBB",
				                   "BBWB",
				                   "WWBB",
				                   "BWBB"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}
			case 3:
			{
				string output[] = {"WWBBBBW",
				                   "BWBBWBB",
				                   "BWBBWBW",
				                   "BWWBWBB"};
				string __expected[] = {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}
			/*case 4:
			{
				string output[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string output[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string output[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.makeProgram(vector <string>(output, output+sizeof(output)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
