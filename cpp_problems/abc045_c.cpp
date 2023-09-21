#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main(void)
{
  string s;
  cin >> s;

  int len = (int)s.length();
  vector<int> base(len);

  for (int i = 0; i < len; i++)
  {
    base[i] = s[i] - '1' + 1;
  }

  ll ans = 0LL;

  for (int c = 0; c < (1 << (len - 1)); c++)
  {
    ll digit = 1LL;
    for (int i = 0; i < len - 1; i++)
    {
      ans += base[len - 1 - i] * digit;
      /*
        この穴に+を入れないのであれば
      */
      if (((c >> i) & 1) == 0)
      {
        digit *= 10LL;
      }
      else
      {
        digit = 1LL;
      }
    }
    ans += base[0] * digit;
  }

  cout << ans << endl;
  return 0;
}