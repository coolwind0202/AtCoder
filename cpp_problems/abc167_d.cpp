#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  ll k = 0;
  cin >> n >> k;
  vector<int> l(n);
  vector<bool> seen(n, false);
  vector<int> order(n);

  for (auto &a : l)
  {
    cin >> a;
    a--;
  }

  /*
    i: 現在見ている町、
    j: 現在のorder index
  */
  int i = 0, j = 0;

  for (; j < k; j++)
  {
    if (seen[i])
    {
      for (int p = 0; p < n; p++)
      {
        if (order[p] == i)
        {
          int t = j - p;
          int x = k - t * ((k - p) / t);
          cout << order[x] + 1 << endl;
          return 0;
        }
      }
    }
    order[j] = i;
    int next = l[i];
    seen[i] = true;
    i = next;
  }

  cout << i + 1 << endl;
  return 0;
}