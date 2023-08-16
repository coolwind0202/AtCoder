#include <iostream>

using namespace std;

int main(void)
{
  int s = 0, t = 0, a = 0, b = 0, c = 0, count = 0;
  cin >> s >> t;

  for (int a = 0; a <= s; a++)
  {
    for (int b = 0; a + b <= s; b++)
    {
      for (int c = 0; a + b + c <= s; c++)
      {
        if (a * b * c <= t)
          count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}