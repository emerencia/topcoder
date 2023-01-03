#include <string>
using namespace std;

class SemiPerfectSquare {
 public:
 string check(int N) {
   for (long a = 1;a <= N;++a) {
     for (long b = a+1;a*b*b <= N;++b) {
       if (a*b*b == N) {
         return "Yes";
       }
     }
   }
   return "No";
 }
};
