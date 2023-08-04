#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N = 0, count = 0;
  long long D = 0LL;
  cin >> N >> D;

  for (int i = 0; i < N; i++)
  {
    long long X = 0LL, Y = 0LL;
    cin >> X >> Y;

    /* sqrt(X^2 + Y^2) <= D*/
    /* X^2 + Y^2 <= D^2*/

    if ((X * X + Y * Y) <= D * D)
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}