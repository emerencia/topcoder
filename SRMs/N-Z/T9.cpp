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

class T9 {
 public:
  map<string,vector<string> > dictmap;
  string lookup(const vector<string>& part, char c) {
    for (int i=0;i<part.size();i++)
      if (part[i].find(c) != string::npos)
        return string(1,'1'+i);
    return "0";
  }
  string readword(const string& s, int& idx) {
    if (s[idx] == '0') {
      idx++;
      return " ";
    }
    int state = 0;
    int suffix = 0;
    string num;
    while (idx < s.size() && s[idx] != '0') {
      if (state == 0) {
        if (s[idx] == '#') {
          state = 1;
          suffix = 1;
        } else if (s[idx] == '*') {
          state = 1;
          suffix = 5;
        } else {
          num += s[idx];
        }
      } else {
        if (s[idx] == '#') {
          suffix++;
        } else if (s[idx] == '*') {
          suffix+=5;
        } else {
          break;
        }
      }
      ++idx;
    }
    if (!num.size()) {
      cout << "Warning: num is empty" << endl;
      return ""; // does this ever happen?
    }
    if (!dictmap.count(num)) {
      cout << "Warning: num not found in dictionary: " << num << ", idx: " << idx << endl;
      return ""; // this shoudln't happen
    }
    if (suffix > dictmap[num].size()) {
       cout << "Error: suffix: " << suffix << ", "
        << "dictmapnumsize " << dictmap[num].size() << ", num " << num << endl;
       return "";
    }
    return dictmap[num][suffix];
  }
  string message(vector <string> part, vector <string> dict, vector <string> keystr) {
    string s = accumulate(keystr.begin(),keystr.end(),string(""));
    dictmap.clear();
    for (int i=0;i<dict.size();i++) {
      string num;
      for (int j=0;j<dict[i].size();j++)
        num += lookup(part,dict[i][j]);
      if (dictmap.count(num)) {
        dictmap[num].push_back(dict[i]);
        sort(dictmap[num].begin(),dictmap[num].end());
      } else
        dictmap[num] = vector<string>(1,dict[i]);
    }
    /*
    for (map<string,vector<string> >::iterator i=dictmap.begin();i!=dictmap.end();i++) {
      cout << i->first << ": ";
      for (int j = 0;j<i->second.size();j++)
        cout << i->second[j] << ", ";
      cout << endl;
    }
    */
    string r;
    for (int i=0;i<s.size();) {
      r += readword(s,i);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing T9 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407353632;
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
		T9 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string part[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
				string dict[] = {"bad"};
				string keystr[] = {"2230223"};
				_expected = "bad bad";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			case 1:
			{
				string part[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
				string dict[] = {"the", "tie"};
				string keystr[] = {"0843#000843#000"};
				_expected = " tie   tie   ";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			case 2:
			{
				string part[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
				string dict[] = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"};
				string keystr[] = {"223#02", "23*#00843#0"};
				_expected = "aae bad  tie ";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			case 3:
			{
				string part[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
				string dict[] = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"};
				string keystr[] = {"84300223#02", "23#*"};
				_expected = "the  aae bad";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			case 4:
			{
				string part[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
				string dict[] = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"};
				string keystr[] = {"223#02", "23######"};
				_expected = "aae bad";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			case 5:
			{
				string part[] = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"};
				string dict[] = {"xktgmfmoqlmivm", 
				                 "hmthr", 
				                 "tpjgmnmaremiwm", 
				                 "tpjcmnmyrlmhvm", 
				                 "xkpnmgmzqdmhsm", 
				                 "wqopvvmiig", 
				                 "melbcbqeeg", 
				                 "jkxnmbmardmhwm", 
				                 "kpxnmcmyqlmism", 
				                 "wrztvsmhhf", 
				                 "srztssmiic", 
				                 "pxtgmfmyrdmhwm", 
				                 "vqoxswmiin", 
				                 "wryksvmihb", 
				                 "ptjfmbmoremhvm"};
				string keystr[] = {"00", 
				                   "7246779885##00000089682000007246779885##0000724677", 
				                   "9885#000089682000093355523350066659594239879###000"};
				_expected = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   ";
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}
			/*case 6:
			{
				string part[] = ;
				string dict[] = ;
				string keystr[] = ;
				_expected = ;
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string part[] = ;
				string dict[] = ;
				string keystr[] = ;
				_expected = ;
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string part[] = ;
				string dict[] = ;
				string keystr[] = ;
				_expected = ;
				_received = _obj.message(vector <string>(part, part+sizeof(part)/sizeof(string)), vector <string>(dict, dict+sizeof(dict)/sizeof(string)), vector <string>(keystr, keystr+sizeof(keystr)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
