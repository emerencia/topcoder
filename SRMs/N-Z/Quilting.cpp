#include <string>
#include <vector>
using namespace std;

struct quilt {
  int color;
  int nexti;
  int nextj;
  quilt(): color(-1),nexti(-1),nextj(-1) {}
};

class Quilting {
  public:
  
  string lastPatch(int length, int width, vector<string> colorList) {
    
    // initialize quilt
    vector< vector<quilt> > q(length);
    quilt a;
    a.color = -1;
    a.nexti = -1;
    a.nextj = -1;
    
    for (int i =0;i < length;++i) {
      //vector<quilt> a(width);
      for (int j=0;j < width;++j) {
        q.at(i).push_back(a);
      }
    }
    
    // set quilt directions
    int starti = length/2;
    int startj = width/2;
    
    int ni = starti;
    int nj = startj;
    if (ni > 0) {
      q[ni][nj].nexti = ni-1;
      q[ni][nj].nextj = nj;
      ni = ni-1;
    }
    int lastdir = 0; // 0 = up, 1 = left, 2 = down, 3 = right
    while(true) {
      switch(lastdir) {
        case 0 : // up
          // last dir was up and we can go left
          if (nj > 0 && q[ni][nj-1].nexti == -1) {
            q[ni][nj].nexti = ni;
            q[ni][nj].nextj = nj-1;
            lastdir = 1;
          } else if (ni > 0 && q[ni-1][nj].nexti == -1) {
            // otherwise keep going up
            q[ni][nj].nexti = ni-1;
            q[ni][nj].nextj = nj;
          }
          break;
        case 1 : // left
          // try to go down
          if (ni+1 < length && q[ni+1][nj].nexti == -1) {
            q[ni][nj].nexti = ni+1;
            q[ni][nj].nextj = nj;
            lastdir = 2;
          } else if (nj > 0 && q[ni][nj-1].nexti == -1) {
            // continue going left
            q[ni][nj].nexti = ni;
            q[ni][nj].nextj = nj-1;
          }
          break;
        case 2 : // down
          // try to go right
          if (nj+1 < width && q[ni][nj+1].nexti == -1) {
            q[ni][nj].nexti = ni;
            q[ni][nj].nextj = nj+1;
            lastdir = 3;
          } else if (ni+1 < length && q[ni+1][nj].nexti == -1) {
            // keep going down
            q[ni][nj].nexti = ni+1;
            q[ni][nj].nextj = nj;
          }
          break;
        case 3 : // right
          // try to go up
          if (ni > 0 && q[ni-1][nj].nexti == -1) {
            q[ni][nj].nexti = ni-1;
            q[ni][nj].nextj = nj;
            lastdir = 0;
          } else if (nj+1 < width && q[ni][nj+1].nexti == -1) {
            // continue going right
            q[ni][nj].nexti = ni;
            q[ni][nj].nextj = nj+1;
          }
          break;
      }
      if (q[ni][nj].nexti == -1) { break; }
      int oni = ni;
      int onj = nj;
      ni = q[oni][onj].nexti;
      nj = q[oni][onj].nextj;
    }
    
    // apply colors
    ni = starti;
    nj = startj;
    q[ni][nj].color = 0;
    while(q[ni][nj].nexti != -1) {
      int tni = q[ni][nj].nexti;
      int tnj = q[ni][nj].nextj;    
      ni = tni;
      nj = tnj;
      q[ni][nj].color = determineColor(q,ni,nj,colorList.size(),length,width);
    }
      
    return colorList.at(q[ni][nj].color);
  }
  
  int determineColor(vector<vector<quilt> > q,int i,int j,int colsize,int length,int width) {
    // minimizes number of neighbours of same color
    vector<int> coluses(colsize);
    for (int k =0;k <colsize;++k) { coluses[k] = 0; }
    for (int ii = i-1;ii < i+2;++ii) {
      for (int jj = j-1;jj < j+2;++jj ) {
        if (i == ii && j == jj) { continue; }
        if (ii < 0 || ii >= length || jj < 0 || jj >= width) { continue; }
        if (q[ii][jj].color == -1) { continue; }
        coluses[q[ii][jj].color]++;
      }
    }
    int colmin = -1;
    vector<int> colindices;
    for (int k = 0;k<colsize;++k) {
      if (colmin == -1 || coluses[k] < colmin) {
        colindices.clear();
        colindices.push_back(k);
        colmin = coluses[k];
      } else if (coluses[k] == colmin) {
        colindices.push_back(k);
      }
    }
    
    if (colindices.size() == 1) { return colindices[0]; }
    
    // choose color that has been used least often by previous patches
    for (int k =0;k <colsize;++k) { coluses[k] = 0; }
    int ni = length/2;
    int nj = width/2;
    while(ni != i || nj != j) {
      coluses[q[ni][nj].color]++;
      int tni = q[ni][nj].nexti;
      int tnj = q[ni][nj].nextj;
      ni = tni;
      nj = tnj;
    }
    colmin = -1;
    vector<int> colind;
    for (int k=0;k<colindices.size();++k) {
      int colidx = colindices[k];
      if (colmin == -1 || coluses[colidx] < colmin) {
        colind.clear();
        colind.push_back(colidx);
        colmin = coluses[colidx];
      } else if (coluses[colidx] == colmin) {
        colind.push_back(colidx);
      }
    }
    
    if (colind.size() == 1) { return colind[0]; }
    
    // choose lowest color index
    sort(colind.begin(),colind.end());
    
    return colind[0];
  }
};
