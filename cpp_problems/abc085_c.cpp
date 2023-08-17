#include <iostream>

using namespace std;

int main(void)
{
  long long N = 0LL, Y = 0LL;
  cin >> N >> Y;

  for (long long a = 0LL; a <= N; a++)
  {
    for (long long b = 0LL; a + b <= N; b++)
    {
      long long c = N - a - b;

      if (c < 0)
        continue;

      long long sum = 10000 * a + 5000 * b + 1000 * c;

      if (sum != Y)
        continue;

      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}