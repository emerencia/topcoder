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

class Embassy {
 public:
  int visaApplication(vector <int> forms, int dayLength, int openTime) {
    set<int> starttimes; // at most 50 times to search through
    int curtime = 0;
    for (int i=0;i<forms.size();i++) {
      curtime = (curtime + forms[i])%dayLength;
      starttimes.insert((openTime - curtime + dayLength)%dayLength);
    }
    int res = INT_MAX;
    for (set<int>::iterator it=starttimes.begin(); it != starttimes.end(); it++) {
      int offset = (*it);
      int totaltime = 0;
      curtime = offset;
      for (int i=0;i<forms.size();i++) {
        curtime += forms[i];
        totaltime += (curtime/dayLength)*dayLength;
        curtime = curtime%dayLength;
        if (curtime > openTime) {
          totaltime += dayLength;
          curtime = 0;
        }
      }
      res = min(res, totaltime + curtime - offset);
    }
    return res;
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
		cout << "Testing Embassy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390322566;
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
		Embassy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int forms[] = {4,4,4};
				int dayLength = 24;
				int openTime = 8;
				_expected = 12;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
			case 1:
			{
				int forms[] = {4,4,4,4};
				int dayLength = 24;
				int openTime = 8;
				_expected = 28;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
			case 2:
			{
				int forms[] = {2,2,2,2};
				int dayLength = 24;
				int openTime = 1;
				_expected = 73;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
			case 3:
			{
				int forms[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000};
				int dayLength = 1440;
				int openTime = 360;
				_expected = 16945;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
			case 4:
			{
				int forms[] = {567213, 494175, 41987, 510822, 279719, 889559, 572483, 117704, 641618, 110895, 259588, 721431, 930617, 438350, 184363, 37908, 784347, 842509, 563146, 965103, 966945, 204978, 136741, 308997, 814758, 672822, 774768, 279015, 303415, 142975, 980557, 678292, 354894, 539685, 246801, 649725, 110680, 480112, 286912, 941249, 157936, 208727, 608459, 283950, 983841, 505666, 684633, 863492, 84134, 478601};
				int dayLength = 389114;
				int openTime = 349228;
				_expected = 24712086;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
			case 5:
			{
				int forms[] = {776683, 969160, 400486, 962970, 487737, 385083, 992513, 759662, 538022, 874587, 265161, 948027, 290810, 287310, 260898, 630467, 74485, 494957, 244321, 461746, 403968, 324798, 328582, 654059, 487990, 230073, 871367, 964027, 718179, 105926, 602313, 981155, 37700, 690045, 44187, 157073, 734786, 68387, 27333, 914790, 341243, 736690, 426999, 444913, 316089, 803729, 309783, 111538, 154167, 66327};
				int dayLength = 807671;
				int openTime = 291129;
				_expected = 32146212;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}
		  case 6:
			{
				int forms[] = {97, 51, 87, 84, 93, 23, 65, 71, 45, 90, 11, 9, 31, 8, 53, 78, 7, 61, 57, 31, 67, 61, 31, 66, 10, 13, 23, 16, 51, 64, 40, 68, 38, 87, 42, 98, 63, 87, 39, 4, 60, 9, 73, 83, 38, 56, 5, 18, 15, 93};
				int dayLength = 88;
				int openTime = 72;
				_expected = 2476;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
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
