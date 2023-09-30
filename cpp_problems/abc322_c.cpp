#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<bool> input(n);
  vector<int> next_day(n, 0);

  for (int i = 0; i < m; i++)
  {
    int x = 0;
    cin >> x;

    input[x - 1] = true;
  }
  int cnt = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (input[i])
    {
      cnt = 0;
    }
    else
    {
      cnt++;
    }

    next_day[i] = cnt;
  }

  for (int i = 0; i < n; i++)
  {
    cout << next_day[i] << endl;
  }

  return 0;
}