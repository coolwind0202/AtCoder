#include <iostream>

using namespace std;

int main(void)
{
  int a = 0, b = 0, c = 0, k = 0;
  cin >> a >> b >> c >> k;

  int ans = 0;

  int rest = k - min(a, k);
  ans += min(a, k);
  rest = rest - min(b, rest);
  ans -= min(c, rest);

  cout << ans << endl;
  return 0;
}