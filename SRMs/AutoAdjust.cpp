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

class AutoAdjust {
 public:
  double makevalid(double a) {
    if (a < 32) return 32;
    if (a > 95) return 95;
    return a;
  }
  vector <string> adjust(vector <string> image) {
    double g = 63.5;
    set<int> chrs;
    for (int i=0;i<image.size();i++)
      for (int j=0;j<image[0].size();j++)
        chrs.insert(image[i][j]);
    vector<int> chars(chrs.begin(),chrs.end());
    for (int c=100;c<=20000;c++)
      for (int b=0;b<=100;b++)
        for (int s=-1;s<=1;s+=2) {
          bool darkest = false;
          bool brightest = false;
          for (int i=0;i<chars.size();i++) {
            int a = round(makevalid((makevalid(chars[i]+b*s)-g)*c/100.0+g));
            if (a == 32) darkest = true;
            if (a == 95) brightest = true;
          }
          if (!darkest || !brightest) continue;
          vector<string> im2 = image;
          for (int i=0;i<im2.size();i++)
            for (int j=0;j<im2[0].size();j++) {
              im2[i][j] = round(makevalid((makevalid(im2[i][j]+b*s)-g)*c/100.0+g));
            }
          return im2;
        }
    return image;
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
		cout << "Testing AutoAdjust (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398432893;
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
		AutoAdjust _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string image[] = {"------------",
				                  "--TTT--CCC--",
				                  "---T---C----",
				                  "---T---CCC--",
				                  "------------"};
				string __expected[] = { "            ",  "  ___  CCC  ",  "   _   C    ",  "   _   CCC  ",  "            " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 1:
			{
				string image[] = {"            ",
				                  "  ___  CCC  ",
				                  "   _   C    ",
				                  "   _   CCC  ",
				                  "            "};
				string __expected[] = { "            ",  "  ___  CCC  ",  "   _   C    ",  "   _   CCC  ",  "            " };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 2:
			{
				string image[] = {"AB"};
				string __expected[] = { " _" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 3:
			{
				string image[] = {"LKJEBGLKJBGRDE"};
				string __expected[] = {"JFB- 5JFB 5_)-"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			case 4:
			{
								string image[] = {"^\\\\]\\]\\^^]\\^]]^^]\\^^^^^]]\\]^]\\^]]^^]", "]\\]\\^^]^\\]^]^]\\^^\\]\\^\\\\]]\\^]]]\\\\]]\\\\", "]^\\]]^^]^]]]]]]^]]^^^\\\\]]^]\\\\^\\]\\]\\]", "\\\\\\^]\\]^^]]]]]\\\\\\]]]\\\\^^\\\\^]^^\\^^^]]", "^^]\\]\\\\\\]]\\\\\\^^]^^^^^^\\]^]\\^^^]\\\\\\^\\", "\\^^]\\\\^\\]\\]\\]\\^\\^\\\\\\^^\\^^^]\\^]^]\\\\\\\\", "\\]^^]\\^^\\\\]]\\\\]]^]\\]\\\\]\\\\]\\]\\\\^]\\]]\\", "^]\\]]]\\]]]]\\]^]]^^]]]^\\^]\\^\\\\]]\\^]^^", "^\\]\\]]]]\\]^^]^^]]^\\^^\\]]\\]\\^]^\\\\^\\]^", "]]^\\^]]]]^^^\\]\\^^\\]^]\\\\^\\]\\^\\]^\\^]]\\", "^^]^\\]^\\^^]^^\\^^]\\^\\\\\\]^]]\\]^^\\^\\\\\\]", "^\\^]^]\\]\\^]\\^^\\^\\]]\\^^\\\\\\^]]]^\\]\\\\^\\", "^^]^^\\\\]^^\\^^^]]]\\\\^]^]^\\^^\\\\\\]]^^^\\", "^\\\\^\\]]\\\\]\\\\^\\\\]\\\\]\\^\\\\]\\]\\^\\^^\\^]\\^", "^]]]\\\\]]\\]\\\\]\\]^\\\\\\^]^\\\\\\]^]]^]^^^]^", "\\^]]\\^\\]^]]]^^^^]]\\^]]\\]]^\\]]]]^\\^^]", "^\\^^]^\\]^\\^^]]\\]]^^^]^]^^\\\\]]]^\\\\\\]^", "]]^^\\^\\\\]^]]]^\\]\\^\\]\\]^]]^\\]]]]\\\\^^^", "\\^\\\\]^^\\\\\\\\]]]\\\\\\\\^^^^^\\\\\\\\]^\\]]\\\\]\\", "\\]^^\\^]]\\^^^\\\\\\\\\\^\\\\]^^]\\]^\\]\\\\\\^\\\\^"};
				string __expected[] = {"_  ! ! __! _!!__! _____!! !_! _!!__!", "! ! __!_ !_!_! __ ! _  !! _!!!  !!  ", "!_ !!__!_!!!!!!_!!___  !!_!  _ ! ! !", "   _! !__!!!!!   !!!  __  _!__ ___!!", "__! !   !!   __!______ !_! ___!   _ ", " __!  _ ! ! ! _ _   __ ___! _!_!    ", " !__! __  !!  !!_! !  !  ! !  _! !! ", "_! !!! !!!! !_!!__!!!_ _! _  !! _!__", "_ ! !!!! !__!__!!_ __ !! ! _!_  _ !_", "!!_ _!!!!___ ! __ !_!  _ ! _ !_ _!! ", "__!_ !_ __!__ __! _   !_!! !__ _   !", "_ _!_! ! _! __ _ !! __   _!!!_ !  _ ", "__!__  !__ ___!!!  _!_!_ __   !!___ ", "_  _ !!  !  _  !  ! _  ! ! _ __ _! _", "_!!!  !! !  ! !_   _!_   !_!!_!___!_", " _!! _ !_!!!____!! _!! !!_ !!!!_ __!", "_ __!_ !_ __!! !!___!_!__  !!!_   !_", "!!__ _  !_!!!_ ! _ ! !_!!_ !!!!  ___", " _  !__    !!!    _____    !_ !!  ! ", " !__ _!! ___     _  !__! !_ !   _  _"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
			}
			/*case 5:
			{
				string image[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.adjust(vector <string>(image, image+sizeof(image)/sizeof(string))); break;
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
