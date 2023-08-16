#include <iostream>

using namespace std;

int main(void)
{
  int N = 0;
  cin >> N;
  for (int x = 1; x <= 9; x++)
  {
    for (int y = 1; y <= 9; y++)
    {
      if (x * y == N)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}