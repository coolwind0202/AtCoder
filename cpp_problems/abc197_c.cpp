#include <iostream>

using namespace std;

int main(void)
{
  int n = 0;
  int a[20] = {};
  cin >> n;

  int t = n - 1;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int ans = INT32_MAX;

  for (int c = 0; c < (1 << t); c++)
  {
    int buf = 0, xorvalue = 0;
    for (int i = 0; i < t; i++)
    {
      buf |= a[i];

      /*
        区間が終わったら
      */
      if (((c >> i) & 1) == 1)
      {
        xorvalue ^= buf;
        buf = 0;
      }
    }

    buf |= a[t];
    xorvalue ^= buf;

    if (ans > xorvalue)
    {
      ans = xorvalue;
    }
  }

  cout << ans << endl;
  return 0;
}