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
typedef pair<string,int> PSI;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int kMax = 1e9;

class MakingPotions {
 public:
  vector<pair<string,map<string,LL> > > convertrecipes(const vector<string>& recipes) {
    vector<pair<string,map<string,LL> > > r;
    // add all recipes for something
    for (int i=0;i<recipes.size();i++) {
      map<string,LL> ingredients;
      int state = 0;
      string tomake;
      string ingred;
      LL ingredcount;
      for (int j=0;j<recipes[i].size();j++) {
        if (state == 0) {
          if (recipes[i][j] == '=') {
            state = 1;
          } else {
            tomake += recipes[i][j];
          }
        } else {
          if (recipes[i][j] >= '1' && recipes[i][j] <= '9') {
            ingredcount = recipes[i][j]-'0';
          } else if (recipes[i][j] != '+') {
            ingred += recipes[i][j];
          }
          if (j+1 == recipes[i].size() || recipes[i][j] == '+') {
            if (ingredients.count(ingred))
              ingredients[ingred] += ingredcount;
            else
              ingredients[ingred] = ingredcount;
            ingred = "";
          }
        }
      }
      r.push_back(make_pair(tomake,ingredients));
    }
    return r;
  }
  int getCost(vector <string> marketGoods, vector <int> cost, vector <string> recipes) {
    map<string,LL> costs;
    for (int i=0;i<marketGoods.size();i++)
      if (costs.count(marketGoods[i]))
        costs[marketGoods[i]] = min(costs[marketGoods[i]],(LL)cost[i]);
      else
        costs[marketGoods[i]] = cost[i];
    vector<pair<string,map<string,LL> > > crecipes = convertrecipes(recipes);
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i=0;i<crecipes.size();i++) {
        string tomake = crecipes[i].first;
        map<string,LL> ingreds = crecipes[i].second;
        bool good = true;
        LL tcost = 0;
        for (map<string,LL>::iterator it=ingreds.begin();it!=ingreds.end();it++) {
          if (!costs.count((*it).first)) {
            good = false;
            break;
          }
          tcost += (*it).second * costs[(*it).first];
        }
        if (!good) continue;
        if (tcost > kMax) tcost = kMax+1;
        if (costs.count(tomake) && costs[tomake] > tcost) {
          changed = true;
          costs[tomake] = min(costs[tomake],tcost);
        } else if (!costs.count(tomake)) {
          changed = true;
          costs[tomake] = tcost;
        }
      }
    }
    if (!costs.count("LOVE")) return -1;
    return costs["LOVE"];
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
		cout << "Testing MakingPotions (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393942512;
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
		MakingPotions _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string marketGoods[] = {"LOVE", "WATER", "HONEY"};
				int cost[] = {100, 1, 30};
				string recipes[] = {"LOVE=5WATER+3HONEY"};
				_expected = 95;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 1:
			{
				string marketGoods[] = {"WATER", "HONEY", "HOP"};
				int cost[] = {2, 6, 9};
				string recipes[] = {"LOVE=2WATER+4HONEY+2BEER", "BEER=1HOP+3WATER+1HOP"};
				_expected = 76;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 2:
			{
				string marketGoods[] = {"ORANGEJUICE", "APPLEJUICE"};
				int cost[] = {6, 4};
				string recipes[] = {"JUICEMIX=1ORANGEJUICE+1APPLEJUICE"};
				_expected = -1;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 3:
			{
				string marketGoods[] = {"WATER", "HONEY", "HOP"};
				int cost[] = {1,22,17};
				string recipes[] = {"LOVE=7WATER+3HONEY", "LOVE=2HONEY+2HOP"};
				_expected = 73;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 4:
			{
				string marketGoods[] = {"OIL", "WATER"};
				int cost[] = {60, 70};
				string recipes[] = {"FIRSTPOTION=1OIL+1SECONDPOTION", "SECONDPOTION=4WATER+1FIRSTPOTION", "LOVE=1FIRSTPOTION+1SECONDPOTION"};
				_expected = -1;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 5:
			{
				string marketGoods[] = {"HONEYBIT"};
				int cost[] = {100};
				string recipes[] = {"LOVE=6HONEYMEGABYTE","HONEYMEGABYTE=2HONEYFIFTYTWELVEKBYTES",
				                   "HONEYFIFTYTWELVEKBYTES=8HONEYSIXTYFOURKBYTES","HONEYSIXTYFOURKBYTES=8HONEYEIGHTKBYTES",
				                   "HONEYEIGHTKBYTES=8HONEYKBYTE","HONEYKBYTE=2EIGHTBYEIGHTWORDS","EIGHTBYEIGHTWORDS=8EIGHTWORDS",
				                   "EIGHTWORDS=8HONEYWORD","HONEYWORD=8HONEYBYTE","HONEYBYTE=8HONEYBIT"};
				_expected = 1000000001;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 6:
			{
				string marketGoods[] = {"WATER"};
				int cost[] = {1};
				string recipes[] = {"LOVE=1LOVE"};
				_expected = -1;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 7:
			{
				string marketGoods[] = {"MILK","WATER","HOP"};
				int cost[] = {6,1,14};
				string recipes[] = {"NECTAR=4HOP+2MILK","LOVE=5MILK+3BEER","LOVE=2WATER+1LOVE","LOVE=2MIX+1NECTAR",
				                   "MIX=1MILK+1WATER+1HOP","BEER=5WATER+2HOP","LOVE=1NECTAR+3WATER+3HOP","NECTAR=3BEER+1MILK+2MILK"};
				_expected = 110;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			case 8:
			{
				string marketGoods[] = {"SE", "VB", "GZ", "VZ", "JI", "EJ", "OI", "VK"};
				int cost[] = {45, 25, 10, 51, 19, 74, 82, 68};
				string recipes[] = {"VK=4EN+6GZ+8IG", "EN=3VZ", "IG=8VZ+2GZ", "JZ=7IG+9SE+2VZ+4EN+1EJ", "VZ=8VB", "VK=1GZ+6SE+5VK+7JZ+8EJ", "SE=4JI+6VB+9VB+4HB+8EN", "EN=3HB+8VB+3EJ+1GZ+8VB", "IG=1IG+2EN+7JI+1GZ+5EJ", "VB=6HB+9VK+2VB+1HB+9VK", "VB=2JZ+4OI+3GZ+4HB+8JI", "GZ=8OI+5VZ+5HB+2VZ+9EJ", "GZ=1EJ+1JI+2HB+4JZ+9JZ", "GZ=5JI+1VZ", "EN=7OI+5VZ+6HB+6GZ+6JI", "GZ=9GZ+5EJ+2HB+6HB+2JI", "GZ=7JI+7HB+7HB+9JZ+4JZ", "IG=1EJ+3SE+4VB+4HB+3EN", "LOVE=2EN+2JZ+3GZ", "IG=4VB+8SE+4GZ+4JI+4GZ", "VB=1VK+2VK+3JI+6JZ+7OI", "VK=3HB+8JZ+2EJ+3SE+7GZ", "SE=8OI+5SE+2HB+8JI+3EN", "JZ=6EN+7EJ+1IG+9EJ+4VZ", "IG=2EJ+4VB+6VB", "VK=1VZ+7SE+6VZ+5JI+3JZ", "VZ=5HB+1EJ"};
				_expected = 5744;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}
			/*case 9:
			{
				string marketGoods[] = ;
				int cost[] = ;
				string recipes[] = ;
				_expected = ;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string marketGoods[] = ;
				int cost[] = ;
				string recipes[] = ;
				_expected = ;
				_received = _obj.getCost(vector <string>(marketGoods, marketGoods+sizeof(marketGoods)/sizeof(string)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), vector <string>(recipes, recipes+sizeof(recipes)/sizeof(string))); break;
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
