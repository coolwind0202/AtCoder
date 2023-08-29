#include <iostream>

#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;
  vector<ll> s(n + 1);

  for (int i = 0; i < n; i++)
  {
    ll a = 0;
    cin >> a;

    s[i + 1] = s[i] + a;
  }

  /*
    edit 2: kは、n以下なので、 < ではなく <=
  */
  for (int k = 1; k <= n; k++)
  {
    /*
      長さ k の区間における区間和を考える
    */
    ll ans = 0;

    /*
      edit 1: k + i < nを、k + i < n + 1にする。
    */
    for (int i = 0; k + i < n + 1; i++)
    {
      /*
        a[i + k - 1] から a[i]の和
      */
      ll val = s[k + i] - s[i];
      if (val > ans)
        ans = val;
    }
    cout << ans << endl;
  }
  return 0;
}