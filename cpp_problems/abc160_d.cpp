#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{

  int n = 0, x = 0, y = 0;

  cin >> n >> x >> y;
  x--;
  y--;

  vector<vector<int>> g(n);

  for (int i = 0; i < n - 1; i++)
  {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }

  g[x].push_back(y);
  g[y].push_back(x);

  vector<int> ans(n - 1, 0);

  auto bfs = [&](int i) -> void
  {
    queue<int> q;
    q.push(i);

    vector<int> dist(n, -1);
    dist[i] = 0;

    while (!q.empty())
    {
      int x = q.front();
      q.pop();

      for (auto nv : g[x])
      {
        if (dist[nv] != -1)
          continue;

        q.push(nv);

        dist[nv] = dist[x] + 1;
        if (nv > i)
          ans[dist[nv] - 1]++;
      }
    }
  };

  for (int i = 0; i < n; i++)
  {
    bfs(i);
  }

  for (int i = 0; i < n - 1; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}