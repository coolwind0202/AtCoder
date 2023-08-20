#include <iostream>
#include <vector>

using namespace std;

vector<string> b;

/*
  □□□□
*/
int dfs_row(int x, int y, int columns, int rows)
{
  /*
    行はどこまで続くのか.
  */
  char value = b[y][x];
  int begin = x, end = x;

  for (int i = x - 1; i >= 0; i--)
  {
    if (b[y][i] != value)
    {
      begin = i + 1;
    }
  }

  for (int i = x + 1; i < columns; i++)
  {
    if (b[y][i] != value)
    {
      end = i - 1;
    }
  }

  if (begin == x && end == x)
  {
    return 0;
  }

  for (int i = 0; i < begin; i++)
  {
    return dfs_column(i, y, columns, rows);
  }

  for (int i = end + 1; i < columns; i++)
  {
    return dfs_column(i, y, columns, rows);
  }
}

/*
  □
  □
  □
  □
*/
int dfs_column(int x, int y, int columns, int rows)
{
  dfs_row(x1, x2);
}

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;

  vector<string> b(h), k;
  for (auto &r : b)
  {
    cin >> r;
  }

  return 0;
}