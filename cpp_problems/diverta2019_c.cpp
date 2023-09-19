#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, x = 0, y = 0, z = 0, ans = 0;
  cin >> n;

  string s;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    char first = s[0], last = s[s.length() - 1];

    if (first == 'B' && last == 'A')
      z++;

    else if (first == 'B')
      x++;
    else if (last == 'A')
      y++;

    for (int j = 0; j + 1 < (int)s.length(); j++)
    {
      if (s[j] == 'A' && s[j + 1] == 'B')
      {
        ans++;
        j++;
      }
    }
  }
  /*
    AB組み合わせの加算
  */

  if (z == 0)
  {
    ans += min(x, y);
  }
  else
  {
    ans += z - 1;
    if (x > 0)
    {
      ans++;
      x--;
    }
    if (y > 0)
    {
      ans++;
      y--;
    }

    ans += max(min(x, y), 0);
  }

  cout << ans << endl;
  return 0;
}