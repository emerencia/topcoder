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

class CandyBox {
 public:
  vector <double> expectedScore(int C, vector <int> score, int S) {
    vector<double> scores;
    for (int i=0;i<score.size();i++)
      scores.push_back(score[i]);
    for (int i=0;i<S;i++) {
      vector<double> nextscores(scores.size(),0);
      for (int j=0;j<scores.size();j++)
        for (int k=j+1;k<scores.size();k++) {
          // Number of possible pairs when something cannot choose itself
          // (which is the number of possible swaps here) is n*(n-1)/2.
          // Here, n = scores.size()*C, so this becomes
          // scores.size()*C*(scores.size()*C-1)/2.0
          // The probability of one swap is 1 divided by this number:
          // 2.0/(scores.size()*C*(scores.size()*C-1))
          // There are C pieces of both types of candy, so the possibility
          // is multiplied by C*C:
          // 2.0*C*C/(scores.size()*C*(scores.size()*C-1))
          // finally, the score for each individual piece of candy
          // is 1/Cth part of the original candies, so we divide by C
          // // 2.0*C/(scores.size()*C*(scores.size()*C-1))
          double p = 2.0*C/(scores.size()*C*(scores.size()*C-1));
          nextscores[j] += p*double(scores[k]-scores[j]);
          nextscores[k] += p*double(scores[j]-scores[k]);
        }
      for (int j=0;j<scores.size();j++)
        scores[j] += nextscores[j];
    }
    return scores;
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
		cout << "Testing CandyBox (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401216801;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CandyBox _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 10;
				int score[] = {1, 10};
				int S = 0;
				double __expected[] = {1.0, 10.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}
			case 1:
			{
				int C = 2;
				int score[] = {1, 10};
				int S = 1;
				double __expected[] = {4.0, 7.000000000000001 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}
			case 2:
			{
				int C = 1;
				int score[] = {1, 4, 10};
				int S = 1;
				double __expected[] = {5.0, 5.0, 5.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}
			case 3:
			{
				int C = 98;
				int score[] = {13, 82, 74, 78, 12, 71, 81, 80, 30};
				int S = 154;
				double __expected[] = {26.25622829378155, 74.87969915903301, 69.24219529059805, 72.06094722481552, 25.551540310227182, 67.12813133993495, 74.17501117547864, 73.47032319192427, 38.23592401420582 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}
			/*case 4:
			{
				int C = ;
				int score[] = ;
				int S = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}*/
			/*case 5:
			{
				int C = ;
				int score[] = ;
				int S = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}*/
			/*case 6:
			{
				int C = ;
				int score[] = ;
				int S = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedScore(C, vector <int>(score, score+sizeof(score)/sizeof(int)), S); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
