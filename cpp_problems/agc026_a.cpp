#include <iostream>
using namespace std;

int main(void)
{
  int n = 0, cnt = 0, a = 0, b = 0;
  cin >> n;

  cin >> a;

  for (int i = 1; i < n; i++)
  {
    cin >> b;
    if (a == b)
    {
      cnt++;
      a = -1;
    }
    else
    {
      a = b;
    }
  }

  cout << cnt << endl;
  return 0;
}