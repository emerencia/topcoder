#include <vector>
#include <string>
#include <sstream>

using namespace std;

class WordFind {
  public:
  vector<string> findWords(vector<string> grid, vector<string> wordList) {
    vector<bool> found;
    vector<string> r;
    for (int i=0;i<wordList.size();++i) { r.push_back(""); found.push_back(false); }
    for (int i=0;i<grid.size();++i) {
      for (int j=0;j<grid[i].length();++j) {
        vector<string> words;
        // right
        string right = "";
        for (int jj=j;jj<grid[i].length();++jj) {
          right += string(1,grid[i][jj]);
        }
        if (right.length() > 0) { words.push_back(right); }
        // down
        string down = "";
        for (int ii=i;ii<grid.size();++ii) {
          down += string(1,grid[ii][j]);
        }
        if (down.length() > 0) { words.push_back(down); }
        // downright
        string downr = "";
        for (int ii=i,jj=j;ii<grid.size() && jj<grid[i].length();++ii,++jj) {
          downr += string(1,grid[ii][jj]);
        }
        if (downr.length() >0) { words.push_back(downr); }
        
        for (int k=0;k<wordList.size();++k) {
          if (found[k]) { continue; }
          for (int l=0;l<words.size();++l) {
            if (words[l].find(wordList[k]) == 0) {
              found[k] = true;
              ostringstream a;
              a << i << " " << j;
              r[k] = a.str();
              break;
            }
          }
        }
      }
    }
    return r;
  }
};
