#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int H = 0, W = 0;
  cin >> H >> W;

  vector<string> l(H);
  set<int> white_rows;
  set<int> white_columns;

  for (int i = 0; i < H; i++)
  {
    bool is_white_row = true;
    cin >> l[i];
    /*
      行の探索
    */
    for (auto c : l[i])
    {
      if (c == '#')
      {
        /*
          この行はすべてが . というわけではない
        */
        is_white_row = false;
        break;
      }
    }

    if (is_white_row)
      white_rows.insert(i);
  }

  /*
    列の探索
  */

  for (int c = 0; c < W; c++)
  {
    bool is_white_column = true;
    for (int i = 0; i < H; i++)
    {
      if (l[i][c] == '#')
      {
        is_white_column = false;
        break;
      }
    }
    if (is_white_column)
      white_columns.insert(c);
  }

  for (int r = 0; r < H; r++)
  {
    if (white_rows.find(r) != white_rows.end())
    {
      /*
        この行はすべて .
      */
      continue;
    }
    for (int c = 0; c < W; c++)
    {
      if (white_columns.find(c) != white_columns.end())
      {
        /*
          この列はすべて .
        */
        continue;
      }
      cout << l[r][c];
    }
    cout << endl;
  }
  return 0;
}