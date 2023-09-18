#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  ll x = 0, k = 0, d = 0;
  cin >> x >> k >> d;

  ll moved = abs(x) - d * min(abs(x / d), k), rest = k - abs(x / d);
  if (rest < 0)
  {
    cout << moved << endl;
    return 0;
  }

  if (rest % 2 == 1)
  {
    moved -= d;
  }

  cout << abs(moved) << endl;
  return 0;
}