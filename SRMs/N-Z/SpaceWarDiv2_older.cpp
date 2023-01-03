#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class SpaceWarDiv2 {
  public:
   struct enemy {
     int strength;
     int count;
   };
   static bool compareByStrength(const enemy &a, const enemy &b) {
    return a.strength > b.strength;
   }
   int minimalFatigue(vector<int> mgs, vector<int>es, vector<int> ec) {
     int numgirls = mgs.size();
     int nume = es.size();
     vector<enemy> e(es.size());
     for (int i=0;i<nume;++i) {
       e[i].strength = es[i];
       e[i].count = ec[i];
     }
     sort(e.begin(),e.end(),compareByStrength);
     //cout << "after:" << endl;
     //for (int i=0;i<nume;++i) {
     //  cout << e[i].strength << " " << e[i].count << endl;
     //}
     sort(mgs.begin(),mgs.end());
     vector<int> fat(numgirls);
     for (int i=0;i<numgirls;++i) {
       fat[i] = 0;
     }
     for (int i=0;i<nume;++i) {
       int ess = e[i].strength;
       for (int j=0;j<e[i].count;++j) {
         int minfat = -1;
         int minfati = -1;
         for (int k=0;k<numgirls;++k) {
           if (mgs[k] >= ess) {
             if (minfati == -1 || fat[k] < minfat) {
               minfat = fat[k];
               minfati = k;
             }
           }
         }
         if (minfati == -1) { return -1; }
         fat[minfati]++;
       }
     }
     int f = 0;
     for (int i=0;i<numgirls;++i) {
       if (fat[i] > f) {
         f = fat[i];
       }
     }
     return f;
   }
 };
