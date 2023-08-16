#include <iostream>
using namespace std;

int main(void)
{
  int N = 0;
  cin >> N;

  for (int i = 0; i * 7 <= N; i++)
  {
    if ((N - i * 7) % 4 == 0)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}