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

class GeneticCrossover {
 public:
  bool isdom(char c) {
    return c >= 'A' && c <= 'Z';
  }
  double cross(string p1a, string p1b, string p2a, string p2b, vector <int> dom, vector <int> rec, vector <int> dependencies) {
    int n = dependencies.size();
    vector<double> domprobs;
    vector<string> s1;
    s1.push_back(p1a);
    s1.push_back(p1b);
    vector<string> s2;
    s2.push_back(p2a);
    s2.push_back(p2b);
    for (int i=0;i<n;i++) {
      int c = 0;
      int sum = 0;
      for (int j=0;j<2;j++)
        for (int k=0;k<2;k++) {
          if (isdom(s1[j][i]) || isdom(s2[k][i])) ++sum;
          ++c;
        }
      double p = double(sum)/c;
      domprobs.push_back(p);
    }
    while (true) {
      bool changed = false;
      for (int i=0;i<dependencies.size();i++) {
        if (dependencies[i] != -1 && dependencies[dependencies[i]] == -1) {
          domprobs[i]*=domprobs[dependencies[i]];
          dependencies[i] = -1;
          changed = true;
        }
      }
      if (!changed) break;
    }
    double r = 0;
    for (int i=0;i<n;i++)
      r+= domprobs[i]*dom[i]+(1-domprobs[i])*rec[i];
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing GeneticCrossover (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397738393;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GeneticCrossover _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string p1a = "AaaAA";
				string p1b = "AaaAA";
				string p2a = "AaaAA";
				string p2b = "AaaAA";
				int dom[] = {1,2,3,4,5};
				int rec[] = {-1,-2,-3,-4,-5};
				int dependencies[] = {-1,-1,-1,-1,1};
				_expected = -5.0;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}
			case 1:
			{
				string p1a = "AbegG";
				string p1b = "ABEgG";
				string p2a = "aBEgg";
				string p2b = "abegG";
				int dom[] = {5,5,5,5,5};
				int rec[] = {1,1,1,1,1};
				int dependencies[] = {-1,0,1,2,3};
				_expected = 14.25;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}
			case 2:
			{
				string p1a = "XyMpdnVsbinDvqBpcWGDLfsmQtZpeirvTmoRmBASfqqrFS";
				string p1b = "xYmpdnVsBINdvQBPCwgDlFSmQTzpEIrVtmoRmbaSfqQRfS";
				string p2a = "XYMpdnvsBINdVQbpCWgDlfSMqTzPeIrVTMOrmbaSfQqrFs";
				string p2b = "XYMpDnVSBIndvQBPCWGDlFsMqtzpEiRVTMORMBASFqQrfS";
				int dom[] = {-82,-35,-51,52,87,25,8,27,-12,-10,-63,-36,-95,-35,-98,95,-76,7,36,-35,92,23,-94,
				             -31,-30,36,51,-49,-19,-3,19,32,58,82,-36,-87,-54,-17,-40,32,-91,-56,0,-16,70,42};
				int rec[] = {-36,77,90,50,83,66,-94,-66,-22,-83,-86,-89,-55,-3,-51,18,-41,-91,91,32,-25,-60,
				             5,79,100,85,60,98,55,95,-67,-46,-26,48,-64,16,-36,-95,-54,19,96,79,78,-91,-12,35};
				int dependencies[] = {-1,-1,1,-1,3,-1,-1,1,3,5,4,0,-1,-1,2,8,5,4,-1,10,11,14,3,-1,
				                     15,-1,7,-1,8,-1,-1,15,-1,-1,30,-1,26,26,-1,-1,-1,-1,-1,31,0,3};
				_expected = -356.875;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}
			case 3:
			{
				string p1a = "fOai";
				string p1b = "Foai";
				string p2a = "fOAI";
				string p2b = "FOAi";
				int dom[] = {96,21,-34,-81};
				int rec[] = {77,-2,20,25};
				int dependencies[] = {-1,0,-1,-1};
				_expected = 44.5;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}
			/*case 4:
			{
				string p1a = ;
				string p1b = ;
				string p2a = ;
				string p2b = ;
				int dom[] = ;
				int rec[] = ;
				int dependencies[] = ;
				_expected = ;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string p1a = ;
				string p1b = ;
				string p2a = ;
				string p2b = ;
				int dom[] = ;
				int rec[] = ;
				int dependencies[] = ;
				_expected = ;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string p1a = ;
				string p1b = ;
				string p2a = ;
				string p2b = ;
				int dom[] = ;
				int rec[] = ;
				int dependencies[] = ;
				_expected = ;
				_received = _obj.cross(p1a, p1b, p2a, p2b, vector <int>(dom, dom+sizeof(dom)/sizeof(int)), vector <int>(rec, rec+sizeof(rec)/sizeof(int)), vector <int>(dependencies, dependencies+sizeof(dependencies)/sizeof(int))); break;
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
