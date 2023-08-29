#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0, k = 0, ans = 0;
  cin >> n >> m;
  vector<int> s(n);

  for (int i = 1; i < n; i++)
  {
    int a = 0;
    cin >> a;
    s[i] = s[i - 1] + a;
  }

  for (int i = 0; i < m; i++)
  {
    int p = 0;
    cin >> p;

    /*
      edit 1: s[x] % 100000 -> s[x]
    */
    ans += abs(s[k + p] - s[k]);
    ans %= 100000;

    k += p;
  }

  /*
    edit 2: ans % 100000 -> ans
  */
  cout << ans << endl;
  return 0;
}