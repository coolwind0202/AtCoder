#include <iostream>

using namespace std;

int main(void)
{
  int k = 0;
  cin >> k;

  int a = 7 % k;

  for (int i = 1; i <= k; i++)
  {
    if (a == 0)
    {
      cout << i << endl;
      return 0;
    }

    a = (a * 10 + 7) % k;
  }

  cout << "-1" << endl;
  return 0;
}