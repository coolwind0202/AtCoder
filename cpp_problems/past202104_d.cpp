#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0, k = 0;
  cin >> n >> k;
  vector<ll> s(n + 1);

  for (int i = 0; i < n; i++)
  {
    ll a = 0LL;
    cin >> a;
    s[i + 1] = s[i] + a;
  }

  for (int x = 0; x <= n - k; x++)
  {
    cout << s[x + k] - s[x] << endl;
  }

  return 0;
}