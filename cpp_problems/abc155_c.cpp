#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> t;

int main(void)
{
  int N = 0, max_cnt = -1;
  string buf;
  map<string, int> l;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    l[buf]++;
  }

  vector<t> r;

  for (auto e : l)
  {
    r.push_back(e);
  }

  sort(r.begin(), r.end(), [](t a, t b)
       { return a.second > b.second; });

  vector<string> ans;

  for (auto e : r)
  {
    if (max_cnt < 0)
    {
      // r の最初のエントリに対する処理
      max_cnt = e.second;
    }

    if (max_cnt != e.second)
    {
      // 投票数最大の範囲から外れた
      break;
    }

    // 投票数最大のものに対する処理
    ans.push_back(e.first);
  }

  sort(ans.begin(), ans.end());

  for (auto s : ans)
  {
    cout << s << endl;
  }

  return 0;
}