#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;
  char g[1000][1000];

  vector<pair<int, int>> blacks;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> g[i][j];

      if (g[i][j] == '#')
      {
        blacks.push_back({i, j});
      }
    }
  }

  queue<pair<int, int>> q;

  for (auto black : blacks)
  {
    q.push(black);
  }

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};

  int ans = 0;

  vector<vector<int>> dist(h, vector<int>(w, -1));

  for (auto black : blacks)
  {
    int x = black.first, y = black.second;
    dist[x][y] = 0;
  }

  while (!q.empty())
  {
    auto tmp = q.front();
    q.pop();

    int x = tmp.first, y = tmp.second;

    for (int k = 0; k < 4; k++)
    {
      int nx = x + dx[k], ny = y + dy[k];

      if (!(0 <= nx && nx < h))
        continue;
      if (!(0 <= ny && ny < w))
        continue;

      if (dist[nx][ny] != -1)
        continue;

      q.push({nx, ny});

      dist[nx][ny] = dist[x][y] + 1;

      ans = max(ans, dist[nx][ny]);
    }
  }

  cout << ans << endl;
  return 0;
}