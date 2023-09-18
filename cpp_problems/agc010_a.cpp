#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;
  bool ok = true;
  ll a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;

    if (a % 2 == 1)
      ok = !ok;
  }

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}