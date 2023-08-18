#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main(void)
{
  int N = 0;
  set<ll> l;
  ll buf;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    if (l.find(buf) != l.end())
    {
      cout << "NO" << endl;
      return 0;
    }

    l.insert(buf);
  }

  cout << "YES" << endl;
  return 0;
}