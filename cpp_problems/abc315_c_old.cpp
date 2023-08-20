#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, ll> t;

int main(void)
{
  int N = 0;
  ll x = -1LL, y = -1LL;
  cin >> N;

  vector<t> l(N);
  for (auto &a : l)
  {
    cin >> a.first;
    cin >> a.second;
  }

  sort(l.begin(), l.end(), [](t a, t b)
       {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second > b.second; });

  for (int i = 1; i < N; i++)
  {
    if (l[0].first != l[i].first)
    {
      // 味が異なる
      x = l[0].second + l[i].second;
      break;
    }
  }

  for (int i = 1; i < N; i++)
  {
    // 味が同じ
    if (l[0].first == l[i].first)
    {
      y = l[0].second + l[i].second / 2;
      break;
    }
  }

  cout << max(x, y) << endl;
  return 0;
}