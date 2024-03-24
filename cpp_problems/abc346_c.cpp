#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;

  ll k = 0LL;
  cin >> k;

  set<ll> a;

  for (int i = 0; i < n; i++)
  {
    ll x = 0;
    cin >> x;
    if (x > k)
      continue;
    a.insert(x);
  }

  ll ans = k * (k + 1) / 2;

  for (auto x : a)
  {
    ans -= x;
  }

  cout << ans << endl;

  return 0;
}