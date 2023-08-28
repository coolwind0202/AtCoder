#include <iostream>

using namespace std;

int main(void)
{
  int N = 0, H = 0, X = 0, min_H = -1, ans = 0;
  cin >> N >> H >> X;

  for (int i = 1; i <= N; i++)
  {
    int a = 0;
    cin >> a;

    if (a + H >= X)
    {
      if (min_H < 0)
      {
        min_H = a;
        ans = i;
      }
      else if (ans > min_H)
      {
        min_H = a;
        ans = i;
      }
    }
  }

  cout << ans << endl;
}