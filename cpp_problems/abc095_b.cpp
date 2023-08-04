#include <iostream>

using namespace std;

int INF = INT32_MAX;

int main(void)
{
  int N = 0, X = 0, min = INF;

  cin >> N >> X;

  for (int i = 0; i < N; i++)
  {
    int m = 0;
    cin >> m;
    X -= m;
    if (m < min)
      min = m;
  }

  cout << N + (X / min) << endl;

  return 0;
}