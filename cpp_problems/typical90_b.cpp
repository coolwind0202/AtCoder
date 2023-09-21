#include <iostream>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  if (n % 2)
  {
    cout << endl;
    return 0;
  }

  for (int c = 0; c < (1 << n); c++)
  {
    int level = 0, before = 0;
    bool acceptable = true;
    string ans;
    for (int i = n - 1; i >= 0; i--)
    {
      int x = (c >> i) & 1;

      ans += x ? ")" : "(";

      if (x == 0)
      {
        // (
        if (before < n / 2)
        {
          // before < n / 2だと ()(( のようなパターンが発生する
          before++;
          level++;
        }
        else
        {
          acceptable = false;
          break;
        }
      }
      else
      {
        // )
        if (level > 0)
          level--;
        else
        {
          acceptable = false;
          break;
        }
      }
    }

    if (acceptable)
    {

      cout << ans << endl;
    }
  }
}