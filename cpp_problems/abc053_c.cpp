#include <iostream>
using namespace std;

typedef long long ll;

int main(void)
{
  ll x = 0;
  cin >> x;

  cout << (x - 1) / 11 * 2 + (((x - 1) % 11 >= 6) ? 2 : 1) << endl;
  return 0;
}