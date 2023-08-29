#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, q = 0, ans = 0;
  cin >> n >> q;

  string t;
  cin >> t;

  vector<int> v(n);
  vector<int> s(n + 1);

  for (int i = 1; i < n; i++)
  {
    if (t[i - 1] == 'A' && t[i] == 'C')
    {
      v[i] = 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    s[i + 1] = s[i] + v[i];
  }

  for (int i = 0; i < q; i++)
  {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    // r--;  開区間を扱いたい
    //  A | Cを除くために、区間の左端は 1 増やす
    //  区間の右端は、今回両端を含む閉区間の部分和を考えたいから、1増やす
    //  v[l + 1] + ... + v[r]
    cout << s[min(r + 1, n)] - s[min(l + 1, n)] << endl;
  }
  return 0;
}