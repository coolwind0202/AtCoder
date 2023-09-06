#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;
  vector<pair<int, string>> v(n);
  for (auto &a : v)
  {
    cin >> a.second >> a.first;
  }

  sort(v.begin(), v.end(), greater<pair<int, string>>());
  cout << v[1].second << endl;
  return 0;
}