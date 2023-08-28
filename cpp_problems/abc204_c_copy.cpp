/*
  ほぼ写経したもの
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> seen;

void dfs(int v)
{
  seen[v] = true;
  for (auto nv : g[v])
  {
    if (seen[nv])
      continue;
    dfs(nv);
  }
  // seen[v] = false;
}

int main(void)
{
  int n = 0, m = 0, ans = 0;
  cin >> n >> m;

  g.assign(n, vector<int>());
  seen.assign(n, false);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    a--;
    b--;
    g[a].push_back(b);
  }

  for (int i = 0; i < n; i++)
  {
    /*
      新しい頂点から探索を始めるので、seenはリセットする
    */
    for (int j = 0; j < n; j++)
      seen[j] = false;
    /*
      探索を開始
    */
    dfs(i);
    /*
      到達した場所を加算
    */
    for (int j = 0; j < n; j++)
      if (seen[j])
        ans++;
  }

  cout << ans << endl;
  return 0;
}