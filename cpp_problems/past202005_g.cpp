#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  x += 201;
  y += 201;

  bool m[403][403] = {};

  for (int i = 0; i < n; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    m[a + 201][b + 201] = true;
  }

  queue<pair<int, int>> q;

  q.push({201, 201});

  int dx[6] = {1, -1, -1, 0, 1, 0};
  int dy[6] = {1, 1, 0, -1, 0, 1};

  vector<vector<int>> dist(403, vector<int>(403, -1));
  dist[201][201] = 0;

  while (!q.empty())
  {
    auto tmp = q.front();
    q.pop();
    int x2 = tmp.first, y2 = tmp.second;

    for (int k = 0; k < 6; k++)
    {
      int nx = x2 + dx[k], ny = y2 + dy[k];

      if (!(0 <= nx && nx < 403))
        continue;
      if (!(0 <= ny && ny < 403))
        continue;

      if (m[nx][ny])
        continue;
      if (dist[nx][ny] != -1)
        continue;

      q.push({nx, ny});

      dist[nx][ny] = dist[x2][y2] + 1;
      if (nx == x && ny == y)
        break;
    }
  }

  cout << dist[x][y] << endl;

  return 0;
}