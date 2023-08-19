#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0, current = -1, cnt = 0, ans = 0;
  cin >> n;

  vector<int> l(n);

  for (auto &a : l)
  {
    cin >> a;
  }

  sort(l.begin(), l.end());
  current = l[0];

  for (auto a : l)
  {
    if (current != a)
    {
      current = a;

      if (cnt < a)
      {
        // 実際に存在する数が、その数値よりも小さければ、すべて取り除かなければならない
        ans += cnt;
      }
      else
      {
        // 数値よりも、多く存在している場合は、差を取り除く
        ans += (cnt - a);
      }
      cnt = 0;
    }

    cnt++;
  }
  cout << ans << endl;
  return 0;
}