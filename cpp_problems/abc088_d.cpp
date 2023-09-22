#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;

  char m[50][50] = {};

  int black_cnt = 0;
  queue<pair<int, int>> todo;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> m[i][j];
      if (m[i][j] == '#')
      {
        black_cnt++;
      }
    }
  }

  int way[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1}};

  vector<vector<int>> dist(h, vector<int>(w, -1));

  dist[0][0] = 0;
  todo.push({0, 0});

  while (!todo.empty())
  {
    auto i = todo.front();
    todo.pop();

    if (i.first + 1 == h && i.second + 1 == w)
    {
      break;
    }

    for (int j = 0; j < 4; j++)
    {

      int x = i.first + way[j][0], y = i.second + way[j][1];
      if (!(0 <= x && x < h))
        continue;
      if (!(0 <= y && y < w))
        continue;

      if (dist[x][y] != -1)
        continue;
      if (m[x][y] != '.')
        continue;

      todo.push({x, y});
      dist[x][y] = dist[i.first][i.second] + 1;
    }
  }

  if (todo.empty() && dist[h - 1][w - 1] == -1)
  {
    cout << "-1" << endl;
    return 0;
  }

  cout << h * w - black_cnt - dist[h - 1][w - 1] - 1 << endl;
  return 0;
}