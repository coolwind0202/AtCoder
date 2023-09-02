#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int main(void)
{
  int n = 0, d = 0;
  ll p = 0, sum = 0, ans = 0;
  cin >> n >> d >> p;

  vector<ll> f(n);
  for (auto &a : f)
  {
    cin >> a;
  }

  sort(f.begin(), f.end(), greater<ll>());

  /*
    高いものから、D枚見て、合計がP「より大きかったら」、P円足す。
    そうでなければ、ansには、暫定の合計値を足し、暫定の合計値をリセットする。
    なぜなら高いものを帳消ししたほうが、最小値が小さくなるから。
  */
  for (int i = 0, cnt = 0; i < n; i++, cnt++)
  {
    if (cnt == d)
    {
      ans += min(p, sum);
      cnt = 0;
      sum = 0;
    }
    sum += f[i];
  }
  ans += min(p, sum);

  cout << ans << endl;

  return 0;
}