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

class Decipher {
 public:
  vector <string> decipher(vector <string> encoded, string frequencyOrder) {
    vector<int> count(26,0);
    for (int i=0;i<encoded.size();i++)
      for (int j=0;j<encoded[i].size();j++) {
        if (encoded[i][j] == ' ') continue;
        count[encoded[i][j]-'A']++;
      }
    vector<PII> sorted;
    for (int i=0;i<26;i++)
      sorted.push_back(PII(-count[i],i));
    sort(sorted.begin(),sorted.end());
    vector<int> replacewith(26,0);
    for (int i=0;i<26;i++) replacewith[i] = i;
    for (int i=0;i<frequencyOrder.size();i++)
      replacewith[sorted[i].second] = frequencyOrder[i]-'A';
    vector<string> r = encoded;
    for (int i=0;i<encoded.size();i++)
      for (int j=0;j<encoded[i].size();j++) {
        if (encoded[i][j] == ' ') continue;
        r[i][j] = replacewith[encoded[i][j]-'A']+'A';
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
		cout << "Testing Decipher (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395894723;
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
		Decipher _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string encoded[] = { "ABBBCC" };
				string frequencyOrder = "XYZ";
				string __expected[] = {"ZXXXYY" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}
			case 1:
			{
				string encoded[] = { "RZLW" };
				string frequencyOrder = "CEFD";
				string __expected[] = {"EDCF" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}
			case 2:
			{
				string encoded[] = { "XX YYY Z YYY XX",
				                     "WWWWWZWWWWW" };
				string frequencyOrder = "ETMQ";
				string __expected[] = {"MM TTT Q TTT MM", "EEEEEQEEEEE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}
			case 3:
			{
				string encoded[] = { " X ",
				                     "",
				                     " ",
				                     "  ",
				                     "   " };
				string frequencyOrder = "B";
				string __expected[] = {" B ", "", " ", "  ", "   " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}
			case 4:
			{
				string encoded[] = { "RAZVLHAR KNW CNR",
				                     "HEA HNFMNSAR NFAK" };
				string frequencyOrder = "EORTPNFHSCDIWG";
				string __expected[] = {"REGISTER NOW FOR", "THE TOPCODER OPEN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}
			/*case 5:
			{
				string encoded[] = ;
				string frequencyOrder = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}*/
			/*case 6:
			{
				string encoded[] = ;
				string frequencyOrder = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}*/
			/*case 7:
			{
				string encoded[] = ;
				string frequencyOrder = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decipher(vector <string>(encoded, encoded+sizeof(encoded)/sizeof(string)), frequencyOrder); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
