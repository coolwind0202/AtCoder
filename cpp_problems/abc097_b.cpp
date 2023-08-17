#include <iostream>

using namespace std;

int main(void)
{
  int b = 2, buf = 0, x = 0, ans = 1;
  cin >> x;

  while (true)
  {
    buf = b * b;
    if (buf > x)
      break;

    while (true)
    {
      if (buf > ans)
        ans = buf;

      buf *= b;
      if (buf > x)
        break;
    }
    b++;
  }
  cout << ans << endl;
  return 0;
}