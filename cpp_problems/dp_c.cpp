#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(3));

  for (int i = 0; i < 3; i++)
  {
    int x = 0;
    cin >> x;
    dp[0][i] = x;
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int x = 0;
      cin >> x;
      dp[i][j] = x + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
    }
  }

  int ans = 0;

  for (int i = 0; i < 3; i++)
  {
    ans = max(ans, dp[n - 1][i]);
  }

  cout << ans << endl;

  return 0;
}