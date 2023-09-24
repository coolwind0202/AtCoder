#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> h(n);
  vector<int> dp(n);

  for (auto &a : h)
  {
    cin >> a;
  }

  dp[0] = 0;

  for (int i = 1; i < n; i++)
  {
    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
      if (i - j < 0)
        break;
      int cost = dp[i - j] + abs(h[i] - h[i - j]);
      ans = min(ans, cost);
    }
    dp[i] = ans;
  }

  cout << dp[n - 1] << endl;
  return 0;
}