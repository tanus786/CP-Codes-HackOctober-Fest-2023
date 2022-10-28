#include <bits/stdc++.h>
using namespace std;

void problemSolution1649587302()
{
  long long a, b;
  cin >> a >> b;
  long long temp1 = a;
  long long temp2 = b;
  long long cnt = 0;
  long long another = 0;
  if(a % 3 == 0 || b % 3 == 0 || a == 0 || b == 0) cout << 0 << "\n";
  else
  {
    while(true)
    {
      a = abs(a - b);
      cnt++;
      if(a % 3 == 0 || a == 0) break;
      b = abs(a - b);
      cnt++;
      if(b % 3 == 0 || b == 0) break;
    }
    while(true)
    {
      temp2 = abs(temp1 - temp2);
      another++;
      if(temp2 % 3 == 0 || temp2 == 0) break;
      temp1 = abs(temp1 - temp2);
      another++;
      if(temp1 % 3 == 0 || temp1== 0) break;
    }
    cout << min(cnt, another) << "\n";
  }
}

void testCases4952876301()
{
  long long tt5914682730;
  cin >> tt5914682730;
  for(long long i9731546820 = 0; i9731546820 < tt5914682730; i9731546820++)
  {
    problemSolution1649587302();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  testCases4952876301();
  // problemSolution1649587302();
  return 0;
}
