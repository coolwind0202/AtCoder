#include <iostream>

using namespace std;

int main(void)
{
  int a[3][3];
  int N = 0;
  bool b[3][3] = {{false, false, false}, {false, false, false}, {false, false, false}};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> a[i][j];
    }
  }

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int buf = 0;
    cin >> buf;

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        if (a[x][y] == buf)
        {
          b[x][y] = true;
          break;
        }
      }
    }
  }

  /*
    ビンゴの存在確認
  */
  /*
    行について
  */
  for (int row = 0; row < 3; row++)
  {
    int column = 0;
    for (; column < 3; column++)
    {
      if (b[row][column] == false)
        break;
    }
    if (column == 3)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  /*
    列について
  */
  for (int column = 0; column < 3; column++)
  {
    int row = 0;
    for (; row < 3; row++)
    {
      if (b[row][column] == false)
        break;
    }
    if (row == 3)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  /*
    斜めについて
  */
  {
    int x = 0;
    for (; x < 3; x++)
    {
      if (b[x][x] == false)
        break;
    }
    if (x == 3)
    {
      cout << "Yes" << endl;
      return 0;
    }

    for (x = 0; x < 3; x++)
    {
      if (b[x][2 - x] == false)
        break;
    }
    if (x == 3)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}