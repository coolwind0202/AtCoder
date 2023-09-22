#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> g(n);
  queue<int> todo;

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> way(n, -1);

  todo.push(0);
  way[0] = 0;

  while (!todo.empty())
  {
    int i = todo.front();
    todo.pop();

    for (auto nv : g[i])
    {
      if (way[nv] != -1)
        continue;

      todo.push(nv);
      way[nv] = i;
    }
  }

  bool ok = true;

  for (int i = 0; i < n; i++)
  {
    if (way[i] == -1)
    {
      ok = false;
      break;
    }
  }

  if (!ok)
  {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for (int i = 1; i < n; i++)
  {
    cout << way[i] + 1 << endl;
  }

  return 0;
}