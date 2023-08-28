#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> l(50);
vector<bool> seen(50, false);
vector<pair<int, int>> paths(50);

void dfs(int v, int start, int goal)
{
  seen[v] = true;
  for (auto nv : l[v])
  {
    if (v == start && nv == goal)
      // 今見ている次の頂点は、橋かを検証したい辺の端点
      continue;
    if (seen[nv])
      continue;
    dfs(nv, start, goal);
  }
}

int main(void)
{
  int n = 0, m = 0, cnt = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    a--;
    b--;
    l[a].push_back(b);
    l[b].push_back(a);
    paths[i] = make_pair(a, b);
  }

  /*
    橋の条件
    非連結
    ある頂点から探索したときに、
    その橋を通過する場合を除き、
    橋の先の頂点に達することができないときに、
    橋であるという。
    探索は、毎回O(N + M) = O(50 + 50) = 10^2
    そして、各辺に対して探索するから、50 * 10^2 = 5 * 10^3
  */

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      seen[j] = false;
    dfs(paths[i].first, paths[i].first, paths[i].second);
    // seen[paths[i].second]ではない（それだと、辺自身が存在しなくてもたどり着けるような辺、つまり橋以外を数えてしまう）
    if (!seen[paths[i].second])
      cnt++;
  }

  cout << cnt << endl;
  return 0;
}