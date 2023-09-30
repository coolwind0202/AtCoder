#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
  char p[3][4][4];

  for (int k = 0; k < 3; k++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> p[k][i][j];
      }
    }
  }

  char tmp[4][4];
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      tmp[i][j] = '.';
    }
  }

  auto dfs = [&](auto dfs, int k, int x, int y, int r, char u[4][4]) -> bool
  {
    if (k == 3)
    {
      // すべて埋まったかを検証する
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (u[i][j] != '#')
            return false;
        }
      }
      return true;
    }

    char m[4][4];

    memcpy(m, u, sizeof(char[4][4]));

    // この置き方がルールを満たすか検証する
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (p[k][i][j] != '#')
          continue;
        int x2 = x + i, y2 = y + j;

        for (int t = 0; t < r; t++)
        {
          int tmp = x2;
          x2 = y2;
          y2 = 3 - tmp;
        }

        if (!(0 <= x2 && x2 < 4))
          return false;
        if (!(0 <= y2 && y2 < 4))
          return false;

        if (m[x2][y2] == '#')
          return false;
        else
          m[x2][y2] = '#';
      }
    }

    for (int i = -4; i <= 4; i++)
    {
      for (int j = -4; j <= 4; j++)
      {
        for (int t = 0; t < 4; t++)
        {
          if (dfs(dfs, k + 1, i, j, t, m))
          {
            return true;
          }
        }
      }
    }
    return false;
  };

  bool ans = true;

  for (int i = -4; i <= 4; i++)
  {
    for (int j = -4; j <= 4; j++)
    {
      for (int t = 0; t < 4; t++)
      {
        if (dfs(dfs, 0, i, j, t, tmp))
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}