#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<int> v(n);

  for (auto &a : v)
  {
    cin >> a;
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  for (int i = 1; i < n; i++)
  {
    if (v[i - 1] > v[i])
    {
      cout << v[i] << endl;
      return 0;
    }
  }

  return 0;
}