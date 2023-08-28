#include <iostream>
#include <vector>

using namespace std;

vector<int> g[50];

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    a--;
    b--;

    g[b].push_back(a);
    g[a].push_back(b);
  }

  for (int i = 0; i < n; i++)
  {
    cout << g[i].size() << endl;
  }

  return 0;
}