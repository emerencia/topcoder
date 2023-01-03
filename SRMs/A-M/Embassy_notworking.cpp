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
    int mn = INT_MAX;
    set<int> times;
    {
      int j = 0;
      int time = j;
      int ttime = 0;
      for (int i=0;i<forms.size();i++) {
        time+=forms[i];
        while (time >= dayLength) {
          ttime+=dayLength;
          time-=dayLength;
        }
        times.insert(forms[i]%dayLength);
        times.insert((forms[i]+1)%dayLength);
        times.insert((forms[i]-1)%dayLength);
        times.insert(dayLength-(forms[i]%dayLength));
        times.insert((1+dayLength-(forms[i]%dayLength))%dayLength);
        times.insert((-1+dayLength+dayLength-(forms[i]%dayLength))%dayLength);
        times.insert(time);
        times.insert((time+1)%dayLength);
        times.insert((time-1+dayLength)%dayLength);
        times.insert(dayLength-time);
        times.insert((dayLength-time+1)%dayLength);
        times.insert((dayLength-time-1+dayLength)%dayLength);
        if (time > openTime) {
          ttime+=dayLength;
          time = 0;
        }
      }
      mn = min(mn,ttime+time-j);
    }
    for (set<int>::iterator k=times.begin();k!=times.end();k++) {
      int j = (*k);
      int time = j;
      int ttime = 0;
      for (int i=0;i<forms.size();i++) {
        time+=forms[i];
        while (time >= dayLength) {
          ttime+=dayLength;
          time-=dayLength;
        }
        if (time > openTime) {
          ttime+=dayLength;
          time = 0;
        }
      }
      mn = min(mn,ttime+time-j);
    }
    return mn;
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
			/*case 5:
			{
				int forms[] = ;
				int dayLength = ;
				int openTime = ;
				_expected = ;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
			}*/
			/*case 6:
			{
				int forms[] = ;
				int dayLength = ;
				int openTime = ;
				_expected = ;
				_received = _obj.visaApplication(vector <int>(forms, forms+sizeof(forms)/sizeof(int)), dayLength, openTime); break;
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
