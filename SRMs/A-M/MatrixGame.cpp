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

class MatrixGame {
 public:
  vector<string> minmat;
  bool isSmallest(vector<string> matrix) {
    sort(matrix.begin(),matrix.end());
    for (int i=0;i<matrix.size();i++)
      if (matrix[i] != minmat[i])
        return matrix[i] < minmat[i];
    return false;   
  }
  void rec(vector<string>& matrix) {
    if (isSmallest(matrix)) {
      vector<string> matrix2 = matrix;
      sort(matrix2.begin(),matrix2.end());
      minmat = matrix2;
    }
  }
  vector <string> getMinimal(vector <string> matrix) {
    minmat = matrix;
    vector<int> p;
    for (int i=0;i<matrix[0].size();i++) p.push_back(i);
    do {
      vector<string> matrix2 = matrix;
      for (int i=0;i<p.size();i++)
        for (int j=0;j<matrix.size();j++)
          matrix2[j][i] = matrix[j][p[i]];
      rec(matrix2);
    } while (next_permutation(p.begin(),p.end()));
    return minmat;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing MatrixGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1403641542;
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
		MatrixGame _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string matrix[] = {"000",
				                   "000",
				                   "000"};
				string __expected[] = {"000", "000", "000" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}
			case 1:
			{
				string matrix[] = {"010",
				                   "000",
				                   "110"};
				string __expected[] = {"000", "001", "011" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}
			case 2:
			{
				string matrix[] = {"111",
				                   "111",
				                   "111"};
				string __expected[] = {"111", "111", "111" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}
			case 3:
			{
				string matrix[] = {"01010",
				                   "10101",
				                   "01010",
				                   "10101"};
				string __expected[] = {"00011", "00011", "11100", "11100" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}
			case 4:
			{
				string matrix[] = {"11010100",
				                   "11110001",
				                   "00011101",
				                   "11111111",
				                   "01110100",
				                   "10000110",
				                   "00001001",
				                   "11010111"};
				string __expected[] = {"00000011", "00001111", "00110100", "01011100", "01111101", "11001100", "11011001", "11111111" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}
			/*case 5:
			{
				string matrix[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string matrix[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string matrix[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getMinimal(vector <string>(matrix, matrix+sizeof(matrix)/sizeof(string))); break;
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
