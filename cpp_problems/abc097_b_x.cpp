#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int X = 0, max_n = 0;
  cin >> X;

  for (int b = 31; b >= 1; b--)
  {
    for (int p = 9; p >= 2; p--)
    {
      int n = pow((float)b, (float)p);
      if (!(1 <= n && n <= X))
        continue;

      if (max_n < n)
        max_n = n;
    }
  }

  cout << max_n << endl;

  /*
    b の制約
      32^2 = 1024
      1^2  = 1
    1 <= b < 32

    p の制約
      2^10 = 1024
    2 <= p < 10
  */
  return 0;
}