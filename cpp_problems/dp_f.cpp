#include <iostream>
#include <string>

using namespace std;
int dp[3001][3001];

int main(void)
{
  string s, t;
  cin >> s >> t;

  int s_len = s.length(), t_len = t.length();

  for (int i = 1; i <= s_len; i++)
  {
    for (int j = 1; j <= t_len; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        // それぞれの1つ前の文字が同じなので、部分列に含める
        // 貪欲的な選択？
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  int ans_len = dp[s_len][t_len], i = s_len, j = t_len;
  char ans[3000] = "";

  while (ans_len > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      // 部分列に貪欲的に含めていくので、このs[i](=t[j])は部分列に含まれる
      // dpが1始まりで文字列が0始まりな都合上、文字列のindexは1を引く
      ans_len--;
      ans[ans_len] = s[i - 1];
      i--;
      j--;
    }
    else if (dp[i][j - 1] == dp[i][j])
    {
      j--;
    }
    else
    {
      i--;
    }
  }

  cout << ans << endl;
  return 0;
}