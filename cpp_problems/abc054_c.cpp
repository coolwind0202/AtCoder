#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> seen(n);

  auto dfs = [&](auto dfs, int i) -> int
  {
    bool ok = true;

    for (int j = 0; j < n; j++)
    {
      if (!seen[j] && i != j)
      {
        ok = false;
        break;
      }
    }

    if (ok)
      return 1;

    if (seen[i])
      return 0;

    int ans = 0;
    seen[i] = true;

    for (auto next : g[i])
    {
      ans += dfs(dfs, next);
    }

    seen[i] = false;
    return ans;
  };

  cout << dfs(dfs, 0) << endl;

  return 0;
}