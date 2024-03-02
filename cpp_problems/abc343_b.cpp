#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int a = 0;
      cin >> a;

      if (a == 1)
      {
        g[i].push_back(j + 1);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    int len = g[i].size();

    int j = 0;
    for (j = 0; j < len - 1; j++)
    {
      cout << g[i][j] << " ";
    }

    cout << g[i][j] << endl;
  }

  return 0;
}