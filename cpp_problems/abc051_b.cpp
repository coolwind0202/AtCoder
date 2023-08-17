#include <iostream>

using namespace std;

int main(void)
{
  int k = 0, s = 0, cnt = 0;
  cin >> k >> s;

  for (int x = 0; x <= k; x++)
  {
    for (int y = 0; y <= k; y++)
    {
      int z = s - x - y;
      if (z < 0 || k < z)
        continue;
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}