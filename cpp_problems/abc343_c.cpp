#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{
  ll n = 0;
  cin >> n;

  ll x = 1;

  for (int i = 0; i < 6; i++)
    x *= 10;

  for (; x >= 1; x--)
  {
    // power 3
    ll sq = x * x * x;

    // judge kaibun
    string s = to_string(sq);
    int len = s.length();

    for (int i = 0, j = len - 1; i <= j; i++, j--)
    {
      if (s[i] != s[j])
        goto end;
    }

    if (sq <= n)
    {
      cout << sq << endl;
      // cout << "matched" << endl;
      // cout << n << endl;
      return 0;
    }

  end:;
  }

  return 0;
}