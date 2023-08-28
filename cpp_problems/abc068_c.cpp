#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;
  vector<set<int>> g(n);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;

    g[a].insert(b);
    g[b].insert(a);
  }

  n--;

  for (auto i : g[n])
  {
    if (g[i].find(0) != g[i].end())
    {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}