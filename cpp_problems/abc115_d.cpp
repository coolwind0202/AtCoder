#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  /*
    最大のレベルを求める
  */

  int n = 0;
  ll x = 0;
  cin >> n >> x;

  ll length[51] = {1};
  ll patty[51] = {1};

  for (int i = 1; i <= n; i++)
  {
    length[i] = 2 * length[i - 1] + 3;
    patty[i] = 2 * patty[i - 1] + 1;
  }

  auto search = [&](auto search, int level, ll position) -> ll
  {
    if (level == 0)
    {
      return 1LL;
    }
    if (position == 1LL)
    {
      return 0LL;
    }
    if (position <= length[level - 1] + 1)
    {
      return search(search, level - 1, position - 1);
    }

    if (position == length[level - 1] + 2)
    {
      return patty[level - 1] + 1;
    }

    if (position <= 2 * length[level - 1] + 2)
    {
      return search(search, level - 1, position - length[level - 1] - 2) + patty[level - 1] + 1;
    }

    if (position == 2 * length[level - 1] + 3)
    {
      return 2 * patty[level - 1] + 1;
    }

    return 0;
  };

  cout << search(search, n, x) << endl;

  return 0;
}