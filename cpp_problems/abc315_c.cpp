#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
  int N = 0;
  cin >> N;
  vector<vector<ll>> l(N + 1);
  vector<ll> max_flavor;
  ll buf = 0LL, ans = 0LL;

  for (int i = 0; i < N; i++)
  {
    int f = 0;
    ll s = 0LL;

    cin >> f >> s;
    l[f].push_back(s);
  }

  for (int i = 1; i <= N; i++)
  {
    int size = l[i].size();
    if (size < 1)
      continue;

    sort(l[i].begin(), l[i].end(), greater<ll>());

    max_flavor.push_back(l[i][0]);
    if (size >= 2)
      ans = max(ans, l[i][0] + l[i][1] / 2);
  }

  sort(max_flavor.begin(), max_flavor.end(), greater<ll>());

  if (max_flavor.size() <= 1)
  {
    cout << ans << endl;
  }
  else
  {
    cout << max(ans, max_flavor[0] + max_flavor[1]) << endl;
  }

  return 0;
}