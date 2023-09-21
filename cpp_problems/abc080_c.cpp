#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;
  ll ans = LLONG_MIN;

  vector<vector<bool>> stores(n, vector<bool>(10, false));
  vector<vector<int>> prices(n, vector<int>(11, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int f = 0;
      cin >> f;
      stores[i][j] = f == 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= 10; j++)
    {
      cin >> prices[i][j];
    }
  }

  for (int c = 0; c < (1 << 10); c++)
  {
    ll score = 0LL;
    bool check_any_open = false;
    for (int i = 0; i < n; i++)
    {

      int store_battle_times = 0;

      for (int j = 0; j < 10; j++)
      {
        // todo: 1つ以上の時間帯では open していることを確認する

        if ((c >> j) & 1)
        {
          check_any_open = true;
          if (!stores[i][j])
            continue;

          store_battle_times++;
        }
      }

      score += prices[i][store_battle_times];
    }

    if (!check_any_open)
      continue;

    if (ans < score)
      ans = score;
  }

  cout << ans << endl;
  return 0;
}