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
int mem[2501][2501];
const int INF = 1e8;

class NameInput {
 public:
  int n,m;
  string predict,name;
  vector<vector<vector<PII> > > dist;
  char tochar(int i) {
    if (i < 26) return 'a'+i;
    if (i < 52) return 'A'+i-26;
    return '0'+i-52;
  }
  int toint(char c) {
    if (c >= 'a' && c <= 'z') return c-'a';
    if (c >= 'A' && c <= 'Z') return c-'A'+26;
    return c-'0'+52;
  }
  int rec(int idx, int pos) {
    int& r = mem[idx][pos];
    if (r != -1) return r;
    if (idx == m) return r = 0;
    int t = INF;
    int c = toint(name[idx]);
    for (int i=0;i<dist[pos][c].size();i++)
      t = min(t,dist[pos][c][i].first+rec(idx+1,dist[pos][c][i].second));
    return r = t;
  }
  int countUpDownKeyPresses(vector <string> predictionSequence, vector <string> nname) {
    predict = accumulate(predictionSequence.begin(),predictionSequence.end(),string(""));
    n = predict.size();
    name = accumulate(nname.begin(),nname.end(),string(""));
    m = name.size();
    dist = vector<vector<vector<PII> > >(n,vector<vector<PII> >(63));
    for (int i=0;i<n;i++)
      for (int j=0;j<63;j++) {
        char c = tochar(j);
        for (int k=0;k*2<=n;k++) {
          int idx1 = (i+k)%n;
          int idx2 = (i-k+n)%n;
          if (predict[idx1] == c)
            dist[i][j].push_back(PII(k,idx1));
          if (idx1 != idx2 && predict[idx2] == c)
            dist[i][j].push_back(PII(k,idx2));
        }
      }
    memset(mem,-1,sizeof(mem));
    int r = rec(0,0);
    return r < INF ? r : -1;
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
		cout << "Testing NameInput (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400858549;
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
		NameInput _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string predictionSequence[] = {"Jjhon"};
				string name[] = {"John"};
				_expected = 5;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 1:
			{
				string predictionSequence[] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789"};
				string name[] = {"Joh","nAndFr","iends"};
				_expected = 186;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 2:
			{
				string predictionSequence[] = {"aaaabbbab","baabbabaabba"};
				string name[] = {"bbaaababba","baababababbb"};
				_expected = 16;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 3:
			{
				string predictionSequence[] = {"john"};
				string name[] = {"John"};
				_expected = -1;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 4:
			{
				string predictionSequence[] = {"4"};
				string name[] = {"4444444444444"};
				_expected = 0;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 5:
			{
				string predictionSequence[] = {"abcABC123","cbaCBA321"};
				string name[] = {"aB32C2AaB3c","c32bA"};
				_expected = 38;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 6:
			{
				string predictionSequence[] = {"89998989998899998889988989999999988888988988999999", "98999999888888999888899888899999988988989898998898", "88999999898999998899989899989998998899898898989988", "89989888888998988999989888999898989998888988889989", "98888888898899889889898899989999988888998999899898", "98999899899988888889899899889989898999998888989999", "98898889999998999999988988888898889888898989899888", "88998999989889888999998889999899888988898888899889", "98999989888989888898988899999998888998898999999899", "89898899988889888999998988889989888888998998988999", "98898998998989899888998898999998999988988899988988", "88999889989998899888988899998899998889889988898888", "98998899899988998989988899998998988899888888888998", "88988989888999899998889999989889889888999888899988", "88989899899899898998989998989988988889999889989988", "89899999998888988989998998898898998988898988889999", "99988988889988888899999888998988888899898998999899", "88999988899989899998888899888999989888899899999899", "89898998899989989889898898889998989899899999889999", "88998989899898988999988999999898998889889898998988", "88899889899998888998989898898899988989888889899989", "99999989988999888989889989899998889889889989988989", "99899999999889889998998889898898888999989999899899", "99888999899898998998989889899889889898988899998899", "abcdefghijklmnopqrstuvwxyz024699899988898898899999", "88989889889989889988898989898889989989899888899989", "98999898988899989989899998989998999999989888998989", "98888899889889898889889989988889899998898899989998", "88898988989899998898989998989998889988988998888899", "88999889899988998888998999888998898988988989989988", "88889888898899998888899989999899989898899998988889", "89998899988898889899999999898998999988899988899889", "98998988999989998999898888999888999899888898888888", "98888889889898888998989888999998898899989898999989", "88899998998989998988899888888899999899889899899989", "98989998898999998888998998988888889899899988988899", "98989989898988899898899888889998899888898899899898", "89988898999988989899889889889899888899989888889999", "89998899899989988998999899899888999998889898989898", "89898898989989888998898988989988888899899888998888", "98998888998899898899888999988899988999999988988989", "88899888999889889898889898998898889888889898888889", "99988998989889989998999988998989888898998999898999", "89889898999999888989889888998888888998989998898989", "88988999999898889989989898989989899898898999898888", "98889989899888889988888989998989988989898998899988", "89999999888998899989889989898999989998899899988988", "98999889999999989988988888898988889899898899889998", "899989999888998898889998988989ABCDEFGHIJKLMNOPQRST", "UVWXYZ1357"};
				string name[] = {"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyY", "zZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsS", "tTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmM", "nNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgG", "hHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aA", "bBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", "0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStT", "uUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnN", "oOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhH", "iIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbB", "cCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01", "23456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuU", "vVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoO", "pPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiI", "jJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcC", "dDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123", "456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvV", "wWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpP", "qQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJ", "kKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdD", "eEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ012345", "6789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwW", "xXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQ", "rRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkK", "lLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeE", "fFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01234567", "89aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX", "yYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrR", "sStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlL", "mMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfF", "gGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789", "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyY", "zZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsS", "tTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmM", "nNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgG", "hHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aA", "bBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", "0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStT", "uUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnN", "oOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhH", "iIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbB", "cCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ01", "23456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuU", "vVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoO", "pPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcCdDeEfFgGhHiI", "jJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789aAbBcC", "dDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123", "456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvV", "wWxXyYzZ0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpP", "qQrRsStTuUvVwWxXyYzZ0123456789"};
				_expected = 2949681;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			case 7:
			{
				string predictionSequence[] = {"W01qVgZpHrEj410PDzPL8Srhx8jRvN6I0AKXF6xNee1d12p6Et", "FDhz6VZ998wzlt8WhNDkga6hFWtzhdDFXtohRAqrSomlEgpqWD", "XRBDB5tvXbkV7eeRxrraLdn8WKaoNbXVxDoKPR54T2qfzVqBSg", "SDn9Ah67VFtwf6vzgZ2H4gAGxDLwGmfbArl1zvqMmW2hwKNlwF", "mQWwrqjIGjMW0b9wHj6eZtZE5Q8LgbIke8TEFX8ZtmPzIWWLEe", "1AmK8VXbQgxPeAA11ZDANwrntImFKMt62EPfBtpS9alEHKpEFj", "VLX1e2LxE6ABnTKNx4E7FF2VQQ2R8jZHNvZ492IR8o8D7KZafg", "1eMIvZDmagQxWAlXFNZNoSv4hL6IVnv9b71V1M1TmrlSd21WMg", "bKtaNBMHPq89610vxpHFNHKKjZIWPITAzIVxntP1vVfvKltWDn", "GbWB4Tj9G48xQKaqtHXj7I02GVj97ngVZaK1Nw2kfaWLZQgvTl", "GSnKLgAV6podlwIFhwtVTdwwlXtx5VmfQPjm5wF58ptwQ2lASS", "ge5QpEEWxTAWvbbwjGGMP6FVF0al1o8HXw52Ir7zb12Tp9BLze", "ADXFQWwH9F9zIqHvXQWgHHmjBHLtfPkGNLwVM8vlA6exr2qGne", "jEvVnS5j9hKaqRtB9lPV2lz5jxLArI8azDgTRDRL2Qezat8Lxk", "drqe5GEdvVoDr1n0hBBHSG2vDaq14FVoDeD7NNZZfrHteZ6g1G", "5qMFGnZDWP2EN6ISpdBlkeTo6vGfe9I9mG9qeSkxmfSHWdZj1B", "1nW6m966TN5eMl2mNLEHEnhgmrmWtH4PPRx6rA8hhob8L1K8FF", "oAdawoIwweP8qL92avTG0MRBLhT5SopbWzEtnRD4d7xVLnxAaX", "LPb1lejQfFQ2kk7FF2QfaH8HI5RwL628dEagFeoqNAlR4EfNkt", "0DDDkxqIwaaomXN6bQx81gl2po78vxnRVfgIH48orN74kIzmGE", "T4vF8S5wSgBDLwXDQrdKmtR5gXe4qS2aMBzheb7SGpSTxvSFrn", "N4g2rWEvfKB2X2f4dHakPkLFA4vM7ILSMS4qKZhjKIfq2VXop1", "2XG6G0zNF6ZQgWfenrG8H9rqARhm4PhweDS7dgElKL9GXMvFZg", "l8ejnK1A0gdhjTP62ZBxbIjT96Xg7FMl0q4qdZEf4MGKrQWDIj", "75wt6BGxobMgPz6aErv2kfLQk5lAxFhVxAxQDpzIAj7hroEMre", "64aIwFtSMpDler4Qe4MMw4zDl4EzlgXdhzNfVVnqzK4n8MmHln", "1aAf4LVGlerIhNZSQwfWkTDG5X87tBQ6xwrZpr699qjwSg6896", "TVoG75TM4DXfxlH8SSE2K5NtGfo78NmoZHn5NrND0lemSEXbWE", "nMkBXGzqSMDwfDQmgEehH1jZVD2tH1kxD14ooIDlV2HQ1KV9TR", "f72TtpBSmzzmEWw7lBzhqRDa2xVVS05nZqpS0kXkvSbgLQgSDo", "k1o412Inexqk8TbzT0frrrEvAatfTd68Z2xWSBZLh69Wv0M7L5", "68l2ad1xoq9vzkbAVhkBlwhkHRAjebgGPD175qtlk28Tph8Wkz", "82ABX4q0S5NIrIhf61QFTLISL9XTv4dZwBvHXaHXq7H4D1EnPv", "KDVELN70S0b94rDFHPIxDHLEKmFQAA6QN9NB7BoBbARhorvbKh", "Ph0PRvahgzIv7b7Ib51BxK69NFNqaqBvT2Q2jprELAjLA1Thx1", "9PgoTalNTaRkoWMHDKBfjMpz71de0ZIGhtw8proQqKTdw9gjFN", "FFhhoej5MNverNbllT9djEq4DB4KWKkMmAGLBr7HT7lqlWIqHt", "wTM0IW07SrEWlF05t0gpDxA29TDNl7o9KqXbHonF9ZR4tnQvmK", "lSEg7dqN9FH0XqKxd0RlaQHnN1Hq4HFTv21844rnmklq8AVZR0", "T4jnHMLtA0E6me2VfVPtfzRQvf59wrmnVkbBr4Xxblraa5SA2F", "Ef5xKxTwbmBWwA6PjEEgmVZHBe1RBP5A1X2vHWd2FfIAKWR1jn", "5xd0mW9HeqeVzm9HHZDTGvf21BhjZ4RL57w2qxLq5eMkbaFdn8", "DEX9qRT72rx0hnNeZRDKfmjbR4KeXNPk512d9dwnjDRPIlbW0L", "lbxqAk5XI5F6KQjLl4GMgGfXMKgTEIbGlovvk6bzPwfGxZzXVS", "qAXZGMKlMKraA74WASZnMNStqVDXPVljDk7Aw4H6htAA5hH8BE", "2zPamHK4hGMDmzGoEewb90v9Hd1IQjSBBkEq6vTbK8hLr12vF9", "NBHDTzAElfPwFRlLlnoLRTIQvgToTdKdl8H0ZZNwGZB4e6jD84", "vSbgRmx91lZMZDexXGvHKd0jMpTfbIH6KtWDIllNAAbpwhqXGL", "4a0f9IpqjLhwTnXtVrjonqrqNLhgN79hV1b4thEVrA9fzkNjMN", "eg02odhMedzkeear9ez6tGZHHLNH0eRaFDH7mNI82E66xZP1wE"};
				string name[] = {"XaZPlTmonWdRtl6ZotpLhbDS487IbVgDhqPom2wTnj4S2tw4nQ", "AAZXp1F4ha4GFrAzbaQhA22r05do4AlX2PvWlnwlvGBZt8RXZB", "hZBoEgpqjZaTz1FqmGI1gGMBadENB0xnZKWbfetkxMz0mGHmIm", "v8EIF1qEb6LQwBHT4GkwzWvjfbvvRVgWQEGtMLMGzLbF0wXzTT", "DXkPLw2r9Mjoz7XFvrMdBEt1DVIWWnZxeKjHZhXZeoIdzrmL71", "29f67FavK2FfgLgLmZo5xZR0ZvnW6GjnKj0ntkdq7TnNNPX97D", "7f8InVjaLWA4wd6DXvIpBorXnTfA29wZkNQT5T0lZtVd4PVZ0l", "xLz1ID9gXq7T2aNbjIE86ShZLG9SF5lfDVgjSTMx4lHmjmPMZA", "jlD0kwH8SeKzV4tMLDwSKlbZNhndEMwB016MKt5ddpjQVMLv8g", "1RvflK9Edz7aEerP5PkZrWqNvmZNH7ttZMlgpagn87jqEbjTvm", "Xlo7dgG2dSdQQxmwG81ED0QSL00twrpSI8NRtrxl4MklakldPz", "Tp65ThbNRA50MKAGrXdXVgKn7j70SVoDMGD6df5Hodae5zmkSf", "Qn8WPoxKDvkBKhETMMFGVM1SotXfSz0rklewL9p0FHjElhgT4o", "Kox0LPMpe0BtFjznQNae8WHZzGfBoKtr555wvfBwTfHFXPrmjL", "Vo1mqPdIqk4qLp9rgtqAR16mk1ZK9pbW1d8aDTP8W2DXnFdtFG", "0vQpHEV6ZXdPhn5ThqMEAtq46pb0H60k4SAMSpPtkjP0mKA27E", "HWjE2IBfhLrpz0N8lE4e6ezQWP9qgbRGbganFZmtoGqgFjwDwv", "FfEbREWPBkP481Z6g6Gvq7A5RzBLH0zDpWI50a8bIeWjKhw0Qp", "G2AxWp0DdrzSgHZwMWASaaw5tIqI9kA22T4dvBFXVzSjvDtZRZ", "w1R1hLNHPbjT2tSFMHb0Pv5XpSBQfb0BzxRd9Gz4D4KrphvexD", "xo0xDbMqa5FvxQmHPxQXSDwPjmqhbpoG68tGvN2w89t7zPzBft", "IgXnFAMXMSg4fF7ZfXWZEGKSFPGBg8QedSZPNbPBw1GHe4rj2P", "h8q8R99oGA6Elt4PIwgkvq6bAE9oPdDNkFbqVQae9pSn8lb5SS", "0jIEawAMLpWQN1XgEPbZdxh7lFDBhQgZ7ZrTPtT7bmST20t9ko", "a7wZwlj5AoMetNkDD76Kjt4mrMK6tR9ZqlbXWvftIpqFPrqhA4", "VFAzSMrEhBW1o7rBlnLA089DkQMpEj0E64ZoV9hqoQv5I5brRx", "SBlfg0bN4kjg5aDf9MZqX87NNXpZznV8m0KjPVA2SqIgeA1wGH", "ES48R5rRzf50wm4k5Qw2gd8PfR2He1NVXffH58DQrkadKA2xXE", "dbGewTqKpgezwBPNQb1waS1tK4K9QZkAnlIS9Dm9wAT906qj5j", "kKQRW8KoqIFF2mZe4kok2l46qDLBVtTRlrm5klk9mN5jo8mPkG", "4rBhrQaZN7qv78tgtov4tq0nd1lwFkdzLGedBlFXB25qoTQwpa", "RQMm0mHpgZRoA6fIHZz79XVbdVg0TGFIeW0tTHBAz0RTRtxqtk", "PwhNbnzjFLSrAqFphKdeXrK1j7G5TtkRpggSH71KaMAMWMVVgq", "rBvTX0EVENerP1pd7DPZn5DtESlmvj5jPmkmrQ0nKQKFPRWlPI", "lrQnVmttHpvB6oPjmI6wddAwmS9vXKfTSTQWVFqXvExr6eQTPq", "6vgrAA9LxH6t5SRAQeAftZh2P4gLQzVgetBjZTIk0FxBWQ2BNe", "rZgxV4PT1bxjexIoHZPZHqNxAjBwPb2oG7B2lrw4FAmtx6jQhv", "95m92gBVmIZfghrakzfPf2vnhEQZhtkQ9aAokj92214XjE4wXF", "jWWaZ5IEXFMWaeqt6gPSA2PG9kfDxP947I9qt9RkG2d0F1fhqR", "ndFVmSDbPp49L47thhBrw274lzPvgf8kdHHHLpEXqMHmII9zm2", "FtrhfGWwj9kFoW1ATnvSMkSkr8KoX8PS0R6xDzbXvtngtPvv6A", "k9hw0zZnEw1NmDLzAqtgAPzegVb0fMZv8QLTzNbDZRxDttZm10", "SR8zPtmKXIFlfqAa1lGtl7wN1Mnn9rhkXo0RS6m9020mVTI2TA", "j4dg5KAHgxDBgWtpWKGX154PBFZNgHXpZjVjLTFBIS0hNGoVwP", "pIR4BZ4dMxAStQ82ef2HNgTVvfHTlQv7h2Hvf6lT8zvKoNIdKW", "IE9m49BjI4nlPSa9HkBXBnFAQgGLLkgeAa1RDGHKwlzTaIPtFv", "Q5oD8XB8KHKhdZDR5hVr1t5eWgonINawMh90bQNBawLDRg7hdK", "RnV86KoLIhv5gwQ1qMKmHp87wjNAZE49HMezHnLFw5GXeLFjPf", "N0DgE8GG1ozjTbv8rKoGgqekKNmAfpjgGf0kPnljX8FKmM181N", "d2hngNorWNS8zaf6PqoLESlWQReSHHjd7H8Vwd8IQBZHtPLDQ6"};
				_expected = 43040;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
			}
			/*case 8:
			{
				string predictionSequence[] = ;
				string name[] = ;
				_expected = ;
				_received = _obj.countUpDownKeyPresses(vector <string>(predictionSequence, predictionSequence+sizeof(predictionSequence)/sizeof(string)), vector <string>(name, name+sizeof(name)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
