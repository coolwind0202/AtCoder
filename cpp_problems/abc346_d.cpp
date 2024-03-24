#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  // 2次元目は連続があれば1、連続がなければ0
  ll cost[200000];
  for (int i = 0; i < n; i++)
  {
    cin >> cost[i];
  }

  // i文字目とi + 1文字目だけを00または11にする方法を考える
  ll even_0_cost[200000] = {};
  ll even_1_cost[200000] = {};
  ll odd_0_cost[200000] = {};
  ll odd_1_cost[200000] = {};

  even_0_cost[0] = (s[0] == '0') ? cost[0] : 0;
  even_1_cost[0] = (s[0] == '1') ? cost[0] : 0;
  // cout << even_0_cost[0] << " " << even_1_cost[0] << endl;

  for (int i = 1; i < n; i++)
  {
    if (i % 2 == 0)
    {
      even_0_cost[i] = even_0_cost[i - 1] + ((s[i] == '0') ? cost[i] : 0);
      even_1_cost[i] = even_1_cost[i - 1] + ((s[i] == '1') ? cost[i] : 0);
      odd_0_cost[i] = odd_0_cost[i - 1];
      odd_1_cost[i] = odd_1_cost[i - 1];
    }
    else
    {
      odd_0_cost[i] = odd_0_cost[i - 1] + ((s[i] == '0') ? cost[i] : 0);
      odd_1_cost[i] = odd_1_cost[i - 1] + ((s[i] == '1') ? cost[i] : 0);
      even_0_cost[i] = even_0_cost[i - 1];
      even_1_cost[i] = even_1_cost[i - 1];
      // cout << odd_0_cost[i] << " " << odd_1_cost[i] << endl;
    }
    // cout << even_0_cost[i] << " " << even_1_cost[i] << " " << odd_0_cost[i] << " " << odd_1_cost[i] << endl;
  }

  ll ans = 2LL << 60;

  // i文字目とi + 1文字目をkにする
  for (int i = 0; i < n - 1; i++)
  {
    for (int k = 0; k < 2; k++)
    {
      if (i % 2 == 0)
      {
        if (k == 0)
        {
          // 左側のeven、右側のoddは0でなければならない
          ans = min(ans, even_1_cost[i] + odd_0_cost[i] + (odd_1_cost[n - 1] - odd_1_cost[i]) + (even_0_cost[n - 1] - even_0_cost[i]));
        }
        else
        {
          ans = min(ans, even_0_cost[i] + odd_1_cost[i] + (odd_0_cost[n - 1] - odd_0_cost[i]) + (even_1_cost[n - 1] - even_1_cost[i]));
          // ans = min(ans, even_0_cost[i] + (odd_0_cost[n - 1] - odd_0_cost[i]));
        }
      }
      else
      {
        if (k == 0)
        {
          // 左側のodd、右側のevenは0でなければならない
          // ans = min(ans, odd_1_cost[i] + (even_1_cost[n - 1] - even_1_cost[i]));
          ans = min(ans, odd_1_cost[i] + even_0_cost[i] + (even_1_cost[n - 1] - even_1_cost[i]) + (odd_0_cost[n - 1] - odd_0_cost[i]));
        }
        else
        {
          // ans = min(ans, odd_0_cost[i] + (even_0_cost[n - 1] - even_0_cost[i]));
          ans = min(ans, odd_0_cost[i] + even_1_cost[i] + (even_0_cost[n - 1] - even_0_cost[i]) + (odd_1_cost[n - 1] - odd_1_cost[i]));
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}