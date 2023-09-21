#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  ll h = 0;

  cin >> h;

  auto search = [&](auto search, ll x) -> ll
  {
    if (x == 1LL)
    {
      return 1LL;
    }
    return 1 + 2 * search(search, x / 2);
  };

  cout << search(search, h) << endl;

  return 0;
}