#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
  int n = 0, m = 0, ans = 0;
  cin >> n >> m;

  /*
    もう一方の端点と、重みを保持する
  */
  vector<vector<pair<int, int>>> g(n);
  vector<bool> seen(n);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    a--;
    b--;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }

  auto dfs = [&](auto dfs, int v) -> int
  {
    int max_nv = 0;
    seen[v] = true;
    /*
      この点から伸びている各辺の、長さの最大値を取る
    */
    for (auto nv : g[v])
    {
      if (seen[nv.first])
        continue;
      int length = dfs(dfs, nv.first) + nv.second;
      if (length > max_nv)
        max_nv = length;
    }
    seen[v] = false;
    return max_nv;
  };

  for (int i = 0; i < n; i++)
  {
    int ret = dfs(dfs, i);
    if (ret > ans)
      ans = ret;
  }

  cout << ans << endl;
  return 0;
}