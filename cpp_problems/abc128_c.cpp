#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> switches(m);

  for (int i = 0; i < m; i++)
  {
    int k = 0;
    cin >> k;

    switches[i].resize(k);

    for (auto &a : switches[i])
    {
      cin >> a;
      a--;
    }
  }

  vector<int> p(m);

  for (auto &a : p)
  {
    cin >> a;
  }

  int ans = 0;

  // c: どのスイッチを on にするか？
  for (int c = 0; c < (1 << n); c++)
  {
    bool all_light = true;
    for (int i = 0; i < m; i++)
    {
      int switch_cnt = 0;
      for (auto &a : switches[i])
      {
        if (((c >> a) & 1) == 1)
        {
          switch_cnt++;
        }
      }

      if (switch_cnt % 2 != p[i])
      {
        all_light = false;
      }
    }

    if (all_light)
      ans++;
  }

  cout << ans << endl;

  return 0;
}