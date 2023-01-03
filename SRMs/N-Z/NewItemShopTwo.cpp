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

class NewItemShopTwo {
 public:
  struct Event {
    int time;
    int cost;
    int prob;
    bool operator<(const Event& o) const {
      return time < o.time;
    }
  };
  vector<Event> getEvents(string s) {
    vector<Event> r;
    stringstream a(s);
    while (!a.eof()) {
      string t;
      a >> t;
      string sofar = "";
      vector<int> values;
      for (int i=0;i<t.size();i++) {
        if (t[i] == ',') {
          stringstream b(sofar);
          int v;
          b >> v;
          values.push_back(v);
          sofar = "";
          continue;
        }
        sofar+=t[i];
      }
      if (sofar.size()) {
        stringstream b(sofar);
        int v;
        b >> v;
        values.push_back(v);
        sofar = "";
      }
      if (values.size() == 3) {
        r.push_back((Event){values[0],values[1],values[2]});
      } else cout << "error" << endl;
    }
    return r;
  }
  double expectedvalat(int curhour, const vector<Event>& e) {
    double r = 0;
    double denom = 1;
    for (int i=0;i<e.size();i++) {
      if (e[i].time > curhour)
        r+= e[i].prob/(100.0*denom)*e[i].cost;
      else
        denom -= e[i].prob/100.0;
    }
    return r;
  }
  double getMaximum(vector <string> customers) {
    vector<Event> e1 = getEvents(customers[0]);
    sort(e1.begin(),e1.end());
    vector<Event> e2 = getEvents(customers[1]);
    sort(e2.begin(),e2.end());
    double r = 0;
    int i1 = 0, i2 = 0;
    double p1 = 1, p2 = 1;
    for (int h=0;h<24;h++) {
      if (i1 < e1.size() && e1[i1].time == h) {
        r+= e1[i1].prob/100.0*p2*max(double(e1[i1].cost),expectedvalat(h,e2));
        p1-=e1[i1].prob/100.0;
        ++i1;
      }
      if (i2 < e2.size() && e2[i2].time == h) {
        r+= e2[i2].prob/100.0*p1*max(double(e2[i2].cost),expectedvalat(h,e1));
        p2-=e2[i2].prob/100.0;
        ++i2;
      }
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing NewItemShopTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397137320;
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
		NewItemShopTwo _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string customers[] = { "8,1,80 16,100,11", "12,10,100" };
				_expected = 19.0;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 1:
			{
				string customers[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" };
				_expected = 19.4;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 2:
			{
				string customers[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
				_expected = 90.0;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 3:
			{
				string customers[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" };
				_expected = 95.0;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 4:
			{
				string customers[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
				                       "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" };
				_expected = 3.0692999999999997;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			/*case 5:
			{
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
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
