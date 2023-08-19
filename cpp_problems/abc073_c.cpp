#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int main(void)
{
  int N = 0, cnt = 0;
  ll buf = 0LL;
  map<ll, int> l;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    l[buf]++;
  }

  for (auto a : l)
  {
    if (a.second % 2 == 0)
      continue;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}