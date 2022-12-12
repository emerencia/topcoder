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

class TopFive {
 public:
  int points;
  vector<double> probtoscorelower;
  struct Contestant {
    vector<int> results;
    vector<int> probs;
    Contestant(int r1, int r2, int r3, int a1, int a2, int a3) {
      results.push_back(r1);
      results.push_back(r2);
      results.push_back(r3);
      probs.push_back(a1);
      probs.push_back(a2);
      probs.push_back(a3);
    }
  };
  vector<Contestant> contestants;
  vector<Contestant> getContestants(const vector<string>& results, const vector<string>& accuracies) {
    vector<Contestant> r;
    for (int i=0;i<results.size();i++) {
      stringstream a(results[i] + " " + accuracies[i]);
      int r1,r2,r3,a1,a2,a3;
      a >> r1 >> r2 >> r3 >> a1 >> a2 >> a3;
      r.push_back(Contestant(r1,r2,r3,a1,a2,a3));
    }
    return r;
  }
  double problower(int idx, int scoreidx, int scoreacc) {
    if (scoreidx == 3) {
      return scoreacc < points;
    }
    int prob = contestants[idx].probs[scoreidx];
    if (prob == 0) return problower(idx,scoreidx+1,scoreacc);
    if (prob == 100) return problower(idx,scoreidx+1,
        scoreacc+contestants[idx].results[scoreidx]);
    double p = prob/100.0;
    return p*problower(idx,scoreidx+1,
        scoreacc+contestants[idx].results[scoreidx]) + 
        (1-p)*problower(idx,scoreidx+1,scoreacc);
  }
  double rec(int togo, int idx) {
    if (idx == probtoscorelower.size())
      return 1;
    if (!togo) return probtoscorelower[idx]*rec(togo,idx+1);
    return probtoscorelower[idx]*rec(togo,idx+1) + 
           (1-probtoscorelower[idx])*rec(togo-1,idx+1);
  }
  double findProbability(vector <string> results, vector <string> accuracies, int points) {
    contestants = getContestants(results,accuracies);
    this->points = points;
    probtoscorelower = vector<double>(contestants.size(),0);
    for (int i=0;i<probtoscorelower.size();i++)
      probtoscorelower[i] = problower(i,0,0);
    sort(probtoscorelower.begin(),probtoscorelower.end());
    int spotstaken = 0;
    for (int i=0;i<probtoscorelower.size();i++)
      if (probtoscorelower[i] < 1e-9)
        spotstaken++;
    if (spotstaken >= 5) return 0;
    int spotsfree = 5-spotstaken;
    vector<double> variableprobs;
    for (int i=0;i<probtoscorelower.size();i++) {
      if (probtoscorelower[i] < 1e-9 || probtoscorelower[i] > 1-1e-9)
        continue;
      variableprobs.push_back(probtoscorelower[i]);
    }
    probtoscorelower = variableprobs;
    if (variableprobs.size() < spotsfree) return 1;
    return rec(spotsfree-1,0);
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
		cout << "Testing TopFive (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397837509;
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
		TopFive _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string results[] = {"200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200"};
				string accuracies[] = {"100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "0 0 50"
				                      };
				int points = 100;
				_expected = 0.5;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}
			case 1:
			{
				string results[] = {"200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200"};
				string accuracies[] = {"100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "100 100 100"};
				int points = 100;
				_expected = 0.0;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}
			case 2:
			{
				string results[] = {"928 209 594", "547 408 596", "190 865 494", "353 392 962", "6 252 267",
				                    "817 671 562", "631 78 290", "593 292 312", "59 51 286", "553 541 487",
				                    "466 318 271", "605 892 562", "596 261 63", "865 895 625", "893 479 586",
				                    "759 596 476", "157 407 819", "509 695 861", "696 730 430", "271 221 0",
				                    "922 296 640", "999 456 654", "320 550 805", "835 808 711", "9 161 670",
				                    "82 737 480", "939 12 363"};
				string accuracies[] = {"84 87 72", "39 60 84", "56 78 48", "0 80 59", "11 69 94",
				                       "100 53 77", "87 77 55", "0 67 7", "89 63 3", "4 69 99", 
				                      "58 9 49", "81 8 84", "81 85 55", "84 68 28", "7 1 46", 
				                      "30 50 51", "16 82 8", "60 17 88", "44 30 67", "20 65 65", 
				                      "40 75 73", "38 97 20", "82 38 88", "90 78 58", "58 30 66",
				                       "3 95 50", "76 60 57"};
				int points = 1623;
				_expected = 0.8657569451352308;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}
			case 3:
			{
				string results[] = {"200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "600 600 600"};
				string accuracies[] = {"100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "100 100 100",
				                      "75 75 75"
				                      };
				int points = 500;
				_expected = 0.015625;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}
			case 4:
			{
				string results[] = {"200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "200 200 200",
				                   "33 33 33",
				                   "33 200 200"};
				string accuracies[] = {"100 0 0",
				                      "0 0 100",
				                      "0 100 0",
				                      "100 100 100",
				                      "100 100 100",
				                      "33 80 50"
				                      };
				int points = 200;
				_expected = 0.10000000000000009;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}
			/*case 5:
			{
				string results[] = ;
				string accuracies[] = ;
				int points = ;
				_expected = ;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}*/
			/*case 6:
			{
				string results[] = ;
				string accuracies[] = ;
				int points = ;
				_expected = ;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
			}*/
			/*case 7:
			{
				string results[] = ;
				string accuracies[] = ;
				int points = ;
				_expected = ;
				_received = _obj.findProbability(vector <string>(results, results+sizeof(results)/sizeof(string)), vector <string>(accuracies, accuracies+sizeof(accuracies)/sizeof(string)), points); break;
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
