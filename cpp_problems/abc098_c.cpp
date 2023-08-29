#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
  int n = 0, ans = INT_MAX;
  cin >> n;

  string s;
  cin >> s;

  vector<int> ve(n + 1);
  vector<int> vw(n + 1);

  for (int i = 0; i < n; i++)
  {
    ve[i + 1] = ve[i] + (s[i] == 'E');
    vw[i + 1] = vw[i] + (s[i] == 'W');
  }

  for (int i = 0; i < n; i++)
  {
    /*
      自分の左側にいるWの数
    */
    /*
      自分の右側にいるEの数
    */
    int cnt = vw[i] + (ve[n] - ve[i + 1]);
    if (cnt < ans)
      ans = cnt;
  }

  cout << ans << endl;
  return 0;
}