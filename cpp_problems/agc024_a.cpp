#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  ll a = 0, b = 0, c = 0, ans = 0, k = 0;
  cin >> a >> b >> c >> k;

  ans = a - b;

  if (k % 2LL)
    ans *= -1LL;

  cout << ans << endl;
  return 0;
}