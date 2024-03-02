#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> g(n, vector<int>());
  vector<int> x(n, -1);

  vector<int> a(m);
  vector<int> b(m);

  for (auto &c : a)
  {
    cin >> c;
    c--;
  }

  for (auto &c : b)
  {
    cin >> c;
    c--;
  }

  // making graph
  for (int i = 0; i < m; i++)
  {
    // cout << a[i] << "/" << b[i] << endl;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  // search graph
  auto dfs = [&](auto dfs, int n, int value) -> bool
  {
    // cout << n << " " << value << endl;
    if (x[n] == -1)
    {
      x[n] = value;
    }
    else
    {
      return x[n] == value;
    }

    for (int next : g[n])
    {
      // cout << next << endl;
      if (!dfs(dfs, next, !value))
        return false;
    }
    return true;
  };

  for (int i = 0; i < n; i++)
  {
    if (x[i] == -1 && !dfs(dfs, i, 0))
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}