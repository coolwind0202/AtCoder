#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, x = 0;
  cin >> n >> x;

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int s = 0;
    cin >> s;

    if (s <= x)
      ans += s;
  }

  cout << ans << endl;

  return 0;
}