#include <iostream>
using namespace std;

typedef long long ll;

int main(void)
{
  ll a = 0, b = 0, n = 0;
  cin >> a >> b >> n;

  cout << (a * min(n, b - 1)) / b << endl;
  return 0;
}