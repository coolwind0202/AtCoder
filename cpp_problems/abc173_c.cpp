#include <iostream>

using namespace std;

int main(void)
{
  int h = 0, w = 0, k = 0, ans = 0;
  char m[6][6] = {};

  cin >> h >> w >> k;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> m[i][j];
    }
  }

  for (int row_choice = 0; row_choice < (1 << h); row_choice++)
  {
    for (int column_choice = 0; column_choice < (1 << w); column_choice++)
    {
      int cnt = 0;
      for (int row = 0; row < h; row++)
      {
        if (((row_choice >> row) & 1) == 1)
        {
          continue;
        }

        for (int column = 0; column < w; column++)
        {
          if (((column_choice >> column) & 1) == 1)
          {
            continue;
          }

          if (m[row][column] == '#')
            cnt++;
        }
      }
      if (cnt == k)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}