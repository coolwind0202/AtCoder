#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0, cnt = 0;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<bool> seen(n);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }

  auto dfs = [&](auto dfs, int v) -> void
  {
    seen[v] = true;
    for (auto nv : g[v])
    {
      if (seen[nv])
        continue;
      dfs(dfs, nv);
    }
  };

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      seen[j] = false;
    dfs(dfs, i);
    for (int j = 0; j < n; j++)
      if (seen[j])
        cnt++;
  }

  cout << cnt << endl;

  return 0;
}