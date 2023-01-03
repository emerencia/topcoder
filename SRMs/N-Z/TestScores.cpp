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
bool seen[51][51];
double mem[51][51];

class TestScores {
 public:
  vector<double> questions;
  double mean;
  double rec(int idx, int questionscorrect) {
    double& r = mem[idx][questionscorrect];
    if (seen[idx][questionscorrect]) return r;
    seen[idx][questionscorrect] = 1;
    if (idx == questions.size())
      return r = (questionscorrect-mean)*(questionscorrect-mean);
    return r = questions[idx]*rec(idx+1,questionscorrect+1) +
               (1-questions[idx])*rec(idx+1,questionscorrect);
  }
  double weightedScore(vector <double> questions, int testScore) {
    this->questions = questions;
    mean = 0;
    for (int i=0;i<questions.size();i++)
      mean+=questions[i];
    memset(seen,0,sizeof(seen));
    double sd = sqrt(rec(0,0));
    double diffinsd = (testScore-mean)/sd;
    return 1000+300*diffinsd;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing TestScores (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399063948;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TestScores _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				double questions[] = {0.5, 0.5};
				int testScore = 1;
				_expected = 1000.0;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			case 1:
			{
				double questions[] = {0.5, 0.5, 0.5};
				int testScore = 3;
				_expected = 1519.6152422706632;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			case 2:
			{
				double questions[] = {0.2, 0.3, 0.4};
				int testScore = 3;
				_expected = 1806.6323435772447;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			case 3:
			{
				double questions[] = {0.2, 0.3, 0.4};
				int testScore = 0;
				_expected = 654.3004241811809;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			case 4:
			{
				double questions[] = {0.9, 0.9, 0.9, 0.9};
				int testScore = 0;
				_expected = -800.0;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			case 5:
			{
				double questions[] = { 0.956062, 0.592855, 0.405804,
				                       0.484474, 0.633413, 0.219248,
				                       0.801282, 0.724066, 0.886559,
				                       0.794041, 0.324220 };
				int testScore = 7;
				_expected = 1037.5680868214772;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}
			/*case 6:
			{
				double questions[] = ;
				int testScore = ;
				_expected = ;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}*/
			/*case 7:
			{
				double questions[] = ;
				int testScore = ;
				_expected = ;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}*/
			/*case 8:
			{
				double questions[] = ;
				int testScore = ;
				_expected = ;
				_received = _obj.weightedScore(vector <double>(questions, questions+sizeof(questions)/sizeof(double)), testScore); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
