#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, m = 0, x = 0;
  cin >> n >> m >> x;

  int books[12][12] = {};
  int book_price[12] = {};

  for (int i = 0; i < n; i++)
  {
    cin >> book_price[i];
    for (int j = 0; j < m; j++)
    {
      cin >> books[i][j];
    }
  }

  int algorithms[12] = {};

  auto search = [&](auto search, int i, int price) -> int
  {
    if (i == n)
    {
      bool all_x = true;
      for (int j = 0; j < m; j++)
      {
        if (algorithms[j] < x)
        {
          all_x = false;
          break;
        }
      }

      if (all_x)
        return price;
      else
        return -1;
    }

    int not_buy = search(search, i + 1, price);

    for (int j = 0; j < m; j++)
    {
      algorithms[j] += books[i][j];
    }

    int buy = search(search, i + 1, price + book_price[i]);

    for (int j = 0; j < m; j++)
    {
      /*
        呼び出し前の状態に戻す
      */
      algorithms[j] -= books[i][j];
    }

    return (buy > 0 && not_buy > 0) ? min(buy, not_buy) : max(buy, not_buy);
  };

  cout << search(search, 0, 0) << endl;
  return 0;
}