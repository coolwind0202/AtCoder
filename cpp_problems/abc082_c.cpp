#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

map<ll, ll> l;

int main(void)
{
  int N = 0;
  ll buf = 0, ans = 0;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    l[buf]++;
  }

  for (auto e : l)
  {
    ll num = e.first;
    ll count = e.second;

    if (num == count)
      continue;
    if (num > count)
    {
      // すべて取り除かなければならない
      ans += count;
    }
    else
    {
      ans += count - num;
    }
  }
  cout << ans << endl;
  return 0;
}