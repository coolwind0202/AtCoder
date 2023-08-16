#include <iostream>

using namespace std;

int main(void)
{
  int A = 0, B = 0, C = 0, X = 0, a, b, c, count = 0;

  cin >> A >> B >> C >> X;

  for (a = 0; a <= A; a++)
  {
    for (b = 0; b <= B; b++)
    {
      for (c = 0; c <= C; c++)
      {
        if (500 * a + 100 * b + 50 * c == X)
          count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}