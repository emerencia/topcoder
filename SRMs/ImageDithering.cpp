#include <vector>
#include <string>

using namespace std;

class ImageDithering {
  public:
  int count(string dithered, vector<string> screen) {
    int cnt =0;
  	for (int i=0;i<screen.size();++i) {
  	for (int j=0;j<screen[i].length();++j) {
  	  if (dithered.find(screen[i][j]) != -1) {
  	  	cnt++;
  	  }
  	 }
  	 }
  	 return cnt;
  }
};
