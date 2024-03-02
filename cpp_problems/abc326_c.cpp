#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    auto it = lower_bound(a.begin(), a.end(), a[i] + m);
    ans = max(ans, (int)distance(a.begin() + i, it - 1) + 1);
  }

  cout << ans << endl;

  return 0;
}