#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<bool> seen(n, false);
  vector<int> a(n);

  for (auto &x : a)
  {
    cin >> x;
    x--;
  }

  int i = 0, cnt = 0;
  while (true)
  {
    if (i == 1)
    {
      cout << cnt << endl;
      return 0;
    }

    int next = a[i];
    if (seen[next])
    {
      cout << "-1" << endl;
      return 0;
    }

    cnt++;
    seen[i] = true;
    i = next;
  }

  return 0;
}