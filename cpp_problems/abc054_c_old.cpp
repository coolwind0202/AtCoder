#include <iostream>
#include <vector>
using namespace std;

vector<int> g[8];
int n = 0;

int dfs(int v, vector<bool> &seen)
{
  bool end = true;
  for (int i = 0; i < n; i++)
  {
    if (!seen[i] && i != v)
      end = false;
  }
  if (end)
  {
    return 1;
  }
  int ans = 0;

  seen[v] = true;
  for (auto next : g[v])
  {
    if (seen[next])
      continue;
    ans += dfs(next, seen);
  }

  seen[v] = false;

  return ans;
}

int main(void)
{
  int m = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> seen(n, false);

  cout << dfs(0, seen) << endl;
}