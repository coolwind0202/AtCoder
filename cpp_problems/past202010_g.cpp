#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;

  char g[10][10] = {};

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> g[i][j];
    }
  }

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};

  auto search = [&](int i, int j) -> bool
  {
    queue<pair<int, int>> q;

    q.push({i, j});

    bool seen[10][10] = {};
    seen[i][j] = true;

    while (!q.empty())
    {
      auto tmp = q.front();
      q.pop();

      int x = tmp.first, y = tmp.second;

      for (int k = 0; k < 4; k++)
      {
        int x2 = x + dx[k], y2 = y + dy[k];

        if (!(0 <= x2 && x2 < h))
          continue;
        if (!(0 <= y2 && y2 < w))
          continue;

        if (g[x2][y2] == '#')
          continue;

        if (seen[x2][y2])
          continue;
        q.push({x2, y2});

        seen[x2][y2] = true;
      }
    }

    /*
      始点0からすべてのマスに移動できるのが必要十分条件
    */

    for (int x = 0; x < h; x++)
    {
      for (int y = 0; y < w; y++)
      {
        if (g[x][y] == '#')
          continue;
        if (!seen[x][y])
          return false;
      }
    }

    return true;
  };

  int ans = 0;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (g[i][j] == '#')
      {
        g[i][j] = '.';
        if (search(i, j))
          ans++;
        g[i][j] = '#';
      }
    }
  }

  cout << ans << endl;

  return 0;
}