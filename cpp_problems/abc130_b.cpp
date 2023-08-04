#include <iostream>

using namespace std;

int main(void)
{
  long long D = 0LL, X = 0LL;
  int N = 0, i = 0;

  cin >> N >> X;

  for (i = 1; i <= N; i++)
  {
    int L = 0;
    cin >> L;

    if (D + L > X)
      break;

    D += L;
  }

  cout << i << endl;

  return 0;
}