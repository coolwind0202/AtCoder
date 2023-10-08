#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;
  string s[100];

  vector<pair<int, int>> cnt(n);

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    cnt[i] = {0, i};
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (i == j)
        continue;
      if (s[i][j] == 'o')
      {
        cnt[i] = {cnt[i].first + 1, i};
      }
      else
      {
        cnt[j] = {cnt[j].first + 1, j};
      }
    }
  }

  auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool
  {
    if (a.first != b.first)
      return a.first > b.first;
    else
      return a.second < b.second;
  };

  sort(cnt.begin(), cnt.end(), cmp);

  for (int i = 0; i < n; i++)
  {
    cout << cnt[i].second + 1;
    if (i + 1 != n)
      cout << " ";
  }
  cout << endl;

  return 0;
}