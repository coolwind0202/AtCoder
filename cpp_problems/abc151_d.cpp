#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;

  char m[20][20] = {};

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> m[i][j];
    }
  }

  int DX[4] = {-1, 0, 1, 0};
  int DY[4] = {0, -1, 0, 1};

  auto bfs = [&](int x, int y) -> int
  {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));

    q.push({x, y});
    dist[x][y] = 0;

    int ans = 0;

    while (!q.empty())
    {
      auto tmp = q.front();
      q.pop();

      int x2 = tmp.first, y2 = tmp.second;

      for (int k = 0; k < 4; k++)
      {
        int nx = x2 + DX[k], ny = y2 + DY[k];

        if (!(0 <= nx && nx < h))
          continue;
        if (!(0 <= ny && ny < w))
          continue;

        if (dist[nx][ny] != -1)
          continue;

        if (m[nx][ny] == '#')
          continue;

        q.push({nx, ny});
        dist[nx][ny] = dist[x2][y2] + 1;
        ans = max(dist[nx][ny], ans);
      }
    }

    return ans;
  };

  int ans = 0;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (m[i][j] == '#')
        continue;
      ans = max(ans, bfs(i, j));
    }
  }

  cout << ans << endl;
  return 0;
}