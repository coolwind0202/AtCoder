#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> ans;
vector<bool> seen;
vector<vector<int>> g;

void dfs(int i, int start)
{
  /*
    暫定、この枝では i は探索済とする
  */
  seen[i] = true;
  ans.insert({start + 1, i + 1});
  for (auto next : g[i])
  {
    if (seen[next])
    {
      continue;
    }
    dfs(next, start);
  }
  /*
    戻るので、i の探索済をフラグを外す
  */
  seen[i] = false;
}

int main(void)
{
  int n = 0, m = 0;
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
    dfs(i, i);

  cout << ans.size() << endl;
  return 0;
}