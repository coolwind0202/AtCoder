#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, m = 0, p = 0;
  cin >> n >> m >> p;
  if (n < m)
  {
    cout << 0 << endl;
  }
  else
    cout << (n - m) / p + 1 << endl;
  return 0;
}