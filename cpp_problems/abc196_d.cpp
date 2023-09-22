#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

  int h = 0, w = 0, a = 0, b = 0;

  cin >> h >> w >> a >> b;

  vector<vector<bool>> m(h, vector<bool>(w, false));

  // x: 1次元目の index に使う
  // y: 2次元目の index に使う
  auto dfs = [&](auto dfs, int x, int y, int restA, int restB) -> int
  {
    if (x + 1 == h && y + 1 == w)
    {
      // 右下のマス
      // cout << restA << " " << restB << endl;

      if (m[x][y])
      {
        // 敷き詰めが完了している
        return 1;
      }
      if (restB)
      {
        // 最後に半畳を詰めれば完了
        return 1;
      }
      return 0;
    }

    int nextX = (y + 1 != w) ? x : x + 1;
    int nextY = (y + 1 != w) ? y + 1 : 0;

    if (m[x][y])
    {
      return dfs(dfs, nextX, nextY, restA, restB);
    }

    int ans = 0;

    // 半畳
    if (restB)
    {
      m[x][y] = true;

      ans += dfs(dfs, nextX, nextY, restA, restB - 1);
      m[x][y] = false;
    }

    if (x + 1 != h)
    {
      // 下端を見ているわけではないので、縦2を選べる
      if (restA)
      {
        m[x][y] = true;
        m[x + 1][y] = true;
        ans += dfs(dfs, nextX, nextY, restA - 1, restB);
        m[x][y] = false;
        m[x + 1][y] = false;
      }
    }
    if (y + 1 != w)
    {
      // 現在右端でないマスを見ているので、横2を選べる

      if (restA && !m[x][y + 1])
      {
        m[x][y] = true;
        m[x][y + 1] = true;

        ans += dfs(dfs, nextX, nextY, restA - 1, restB);
        m[x][y] = false;
        m[x][y + 1] = false;
      }
    }

    // もし埋められなければ ans = 0

    return ans;
  };

  cout << dfs(dfs, 0, 0, a, b) << endl;

  return 0;
}