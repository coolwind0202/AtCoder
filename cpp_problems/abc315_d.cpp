#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int h = 0, w = 0;
  cin >> h >> w;

  vector<vector<char>> l(h, vector<char>(w));

  for (auto &a : l)
  {
    for (auto &b : a)
    {
      cin >> b;
    }
  }

  /*
    列に含まれる文字の種類別の数を計算
  */
  vector<vector<int>> x(w, vector<int>(26));
  /*
    4 * 10^6
  */
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < h; j++)
    {
      x[i][l[j][i] - 'a']++;
    }
  }

  /*
    行に含まれる文字の種類別の数を計算
  */
  vector<vector<int>> y(h, vector<int>(26));

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      y[i][l[i][j] - 'a']++;
    }
  }

  vector<bool> row_deleted(h, false), column_deleted(w, false);
  int hc = h, wc = w;

  for (int _ = 0; _ < h + w; _++)
  {
    vector<pair<int, int>> row_will_delete, column_will_delete;
    /*
      各行から、1種類の文字しか含まれないものを探す
    */
    for (int i = 0; i < h; i++)
    {
      /*
        既に削除されている行は無視する
      */
      if (row_deleted[i])
        continue;
      for (int j = 0; j < 26; j++)
      {
        if (y[i][j] == wc && wc >= 2)
        {
          /*
            この行を削除しても良い
          */
          row_will_delete.push_back({i, j});
        }
      }
    }

    for (int i = 0; i < w; i++)
    {
      if (column_deleted[i])
        continue;
      for (int j = 0; j < 26; j++)
      {
        if (x[i][j] == hc && hc >= 2)
        {
          /*
            この列を削除しても良い
          */
          column_will_delete.push_back({i, j});
        }
      }
    }

    /*
      削除予約をした行を削除する
    */
    for (auto row : row_will_delete)
    {
      row_deleted[row.first] = true;
      /*
        各列について、その行の色を一つ減らす
      */
      for (int i = 0; i < w; i++)
      {
        x[i][row.second]--;
      }
      hc--;
    }

    /*
      削除予約をした列を削除する
    */
    for (auto column : column_will_delete)
    {
      column_deleted[column.first] = true;
      for (int i = 0; i < h; i++)
      {
        y[i][column.second]--;
      }
      wc--;
    }
  }

  cout << hc * wc << endl;

  return 0;
}