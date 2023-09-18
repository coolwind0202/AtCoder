#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<ll> v(n);
  ll ans = 0LL;

  for (auto &a : v)
  {
    cin >> a;
  }

  sort(v.begin(), v.end());
  int i = 0;

  for (i = 0; i + 1 < n; i += 2)
  {
    ll op = v[i] + v[i + 1];
    if (op >= 0)
      ans += op;
    else
      ans -= op;
  }

  /*
    奇数個だった場合
  */
  if (i + 1 == n)
  {
    ans += v[i];
  }

  cout << ans << endl;

  return 0;
}