#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, k = 0;
  double ans = 0;
  cin >> n >> k;

  /*
    edit 2: float -> double
  */
  vector<double> s(n + 1);

  for (int i = 0; i < n; i++)
  {
    double p = 0;
    cin >> p;

    s[i + 1] = s[i] + (p + 1) / 2;
  }

  for (int i = k; i <= n; i++)
  {
    /*
      edit 1: 上と同じループで処理すると、n + 1を含む選び方が最も大きいときに探索しきれない
    */
    double t = s[i] - s[i - k];
    if (t > ans)
      ans = t;
  }

  printf("%.10f\n", ans);
  return 0;
}