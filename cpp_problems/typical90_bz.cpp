#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0, cnt = 0;
  cin >> n >> m;

  vector<set<int>> g(n);

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    a--;
    b--;

    if (a > b)
    {
      g[a].insert(b);
    }
    else if (b > a)
      g[b].insert(a);
  }

  for (int i = 0; i < n; i++)
  {
    if (g[i].size() == 1)
      cnt++;
  }

  cout << cnt << endl;
  return 0;
}