#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
  ll a = 0, b = 0;
  cin >> a >> b;

  if (a <= 0 && 0 <= b)
  {
    cout << "Zero" << endl;
    return 0;
  }

  if (a > 0)
  {
    cout << "Positive" << endl;
    return 0;
  }

  cout << ((-a + b + 1) % 2 == 0 ? "Positive" : "Negative") << endl;
  return 0;
}