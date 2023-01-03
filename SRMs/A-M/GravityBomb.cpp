#include <string>
#include <vector>
using namespace std;

class GravityBomb {
  public:
  vector<string> aftermath(vector<string> board) {
    vector<string> newboard;
    for (int i=0;i<board.size();++i) {
      newboard.push_back(string(board[0].length(),'.'));
    }
   
    for (int coli =0;coli<board[0].length();++coli) {
      int nrx = 0;
      for (int rowi =0;rowi<board.size();++rowi) { 
        if (board[rowi].at(coli) == 'X') {
          nrx++;
        }
      }
      for (int i=0;i<nrx;++i) {
        // test if youcan also use .at(coli) below
        newboard[board.size()-i-1][coli] = 'X';
      }
    }
    
    // descend
    while(newboard.back() == string(board[0].length(),'X')) {
      newboard.insert(newboard.begin(),string(board[0].length(),'.'));
      newboard.pop_back();
    }
   
    return newboard;
    
  }
};
