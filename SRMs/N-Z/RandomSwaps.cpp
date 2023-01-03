#line 93 "RandomSwaps.cpp"
#include <string>
#include <vector>
using namespace std;

class RandomSwaps {
	public:
	double getProbability(int arrayLength, int swapCount, int a, int b) {
		vector<int> m(arrayLength*arrayLength);
		for (int i=0;i<arrayLength;++i) {
			for (int j=i+1;j<arrayLength;++j) {
				m[i*arrayLength+j] = i;
			}
		}
		for (int i=0;i<arrayLength;++i) {
			for (int j=i+1;j<arrayLength;++j) {
				int t = m[i*arrayLength+j];
				m[i*arrayLength+j] = m[j*arrayLength+i];
				m[j*arrayLength+i] = t;
			}
		}
		int c = 0;
		int d = 0;
      	for (int j=0;j<arrayLength;++j) {
			if (m[a*arrayLength+j] == b) {
				c++;
			}
			d++;
		}
		return c*1.0/d;

	}
};


// Powered by FileEdit
