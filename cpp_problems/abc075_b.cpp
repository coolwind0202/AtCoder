#include <iostream>
#include <vector>
using namespace std;

bool isValidIndex(int H, int W, int y, int x)
{
  if (y < 0 || H <= y)
    return false;
  if (x < 0 || W <= x)
    return false;
  return true;
}

int main(void)
{
  int H = 0, W = 0;
  cin >> H >> W;

  vector<string> s(H);
  vector<vector<int>> a(H);

  for (auto &row : s)
  {
    cin >> row;
  }

  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      if (s[h][w] == '#')
      {
        cout << '#';
        continue;
      }

      int bomb_count = 0;
      for (int i = -1; i <= 1; i++)
      {
        for (int j = -1; j <= 1; j++)
        {
          if (i == 0 && j == 0)
            continue;
          if (!isValidIndex(H, W, h + i, w + j))
            continue;
          if (s[h + i][w + j] == '#')
          {
            bomb_count++;
          }
        }
      }
      cout << bomb_count;
    }
    cout << endl;
  }

  return 0;
}