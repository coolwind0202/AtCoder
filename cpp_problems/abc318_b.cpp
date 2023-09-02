#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  vector<vector<bool>> filled(101, vector<bool>(101, false));

  int n = 0, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;

    for (int x = a; x < b; x++)
    {
      /*
        面積を扱う問題は、<= と < の扱いが違う？
      */
      for (int y = c; y < d; y++)
      {
        filled[x][y] = true;
      }
    }
  }

  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++)
    {
      if (filled[i][j])
        cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}