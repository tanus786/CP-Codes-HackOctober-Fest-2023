#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:

    void nonRepeating(string & st, int freq[200]) {
      int i, j;
      int l = st.length();

      for (int i = 0; i < l; i++) {
        freq[i] = 1;
        for (int j = i + 1; j < l; j++) {

          if (st[i] == st[j]) {
            freq[i]++;

            st[j] = '-'; // set st[j] to - to avoid visited character
          }
        }
      }

      for (int i = 0; i < l; ++i) {
        if (freq[i] == 1 && st[i] != ' ' && st[i] != '-') {
          cout << st[i] << " ";
        }
      }
    }
};
int main() {

  string st = "Takeuforward";

  int l = st.length();
  int freq[200] = {
    0
  };

  Solution obj;
  cout << "Non-repeative character:" << "\n";
  obj.nonRepeating(st, freq);

  return 0;
}
