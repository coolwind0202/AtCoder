#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, a = 0, ans = 0;
  vector<vector<int>> l(101);
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> a;

    for (int j = 0; j <= a; j++)
    {
      l[j].push_back(i);
    }
  }

  for (int h = 1; h <= 100; h++)
  {
    vector<int> t = l[h];
    int length = t.size(), i = 1, cnt = 1;
    if (length == 0)
      continue;

    for (; i < length; i++)
    {
      if (t[i] != t[i - 1] + 1)
        cnt++;
    }
    ans += cnt;
  }

  cout << ans << endl;
  return 0;
}