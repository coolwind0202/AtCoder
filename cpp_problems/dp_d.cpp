#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(void)
{
  int n = 0, wmax = 0;
  cin >> n >> wmax;

  vector<pair<int, ll>> items(n);

  for (auto &item : items)
  {
    cin >> item.first >> item.second;
  }

  vector<vector<ll>> dp(n, vector<ll>(wmax + 1, 0LL));

  dp[0][0] = 0LL;
  dp[0][items[0].first] = items[0].second;

  for (int i = 1; i < n; i++)
  {
    for (int w = 0; w <= wmax; w++)
    {
      // 取らない
      dp[i][w] = max(dp[i][w], dp[i - 1][w]);

      int ifget = w + items[i].first;

      // 取る
      if (ifget <= wmax)
      {
        dp[i][ifget] = max(dp[i][ifget], dp[i - 1][w] + items[i].second);
      }
    }
  }

  ll ans = 0LL;

  for (int w = 0; w <= wmax; w++)
  {
    ans = max(ans, dp[n - 1][w]);
  }

  cout << ans << endl;

  return 0;
}