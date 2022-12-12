#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;

bool hasAtTail(string s) {
  for (int i=0;i<s.size();i++)
    if (s[i] == '@')
      return true;
  return false;
}

int main() {
  ifstream a("/Users/ando/Documents/test.txt");
  ofstream b("/Users/ando/Documents/test_out.txt");
  set<string> emails;
  while (a.good()) {
    string c;
    getline(a,c);
    if (hasAtTail(c)) {
      emails.insert(c);
    }
  }
  cout << emails.size() << endl;
  b << "a = [";
  for (set<string>::iterator i=emails.begin();i!=emails.end();i++) {
    if (i != emails.begin()) b << ',' << endl;
    b << '"' << *i << '"';
  }
  b << "];";
  a.close();
  b.close();
}
