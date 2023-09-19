#include <iostream>

typedef long long ll;
using namespace std;

int main(void)
{
  ll a = 0, b = 0, k = 0;
  cin >> a >> b >> k;

  cout << a - min(k, a) << " " << b - min((k - min(k, a)), b) << endl;
  return 0;
}