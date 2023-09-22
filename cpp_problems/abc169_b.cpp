#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ll;

int main(void)
{
  int n = 0;
  cin >> n;

  ll ans = 1LL;
  ll max = pow(10LL, 18LL);

  vector<ll> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];

    if (v[i] == 0LL)
    {
      cout << "0" << endl;
      return 0;
    }
  }

  for (auto a : v)
  {
    if (a > max / ans)
    {
      cout << "-1" << endl;
      return 0;
    }

    ans *= a;
  }

  cout << ans << endl;

  return 0;
}