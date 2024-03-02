#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, q = 0;
  cin >> n >> q;

  string s;
  cin >> s;

  // 区間和の計算
  vector<int> sum(n);

  for (int i = 1; i < n; i++)
  {
    sum[i] = sum[i - 1] + (s[i] == s[i - 1]);
  }

  for (int i = 0; i < q; i++)
  {
    int l = 0, r = 0;
    cin >> l >> r;

    l--;
    r--;

    int ans = sum[r] - sum[l];
    cout << ans << endl;
  }

  return 0;
}