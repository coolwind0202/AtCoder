#include <iostream>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++)
  {
    int j = 1;
    for (; j <= 9; j++)
    {
      if (n % j == 0 && (i == 0 || i % (n / j) == 0))
      {
        cout << j;
        break;
      }
    }
    if (j > 9)
    {
      cout << "-";
    }
  }
  cout << endl;

  return 0;
}