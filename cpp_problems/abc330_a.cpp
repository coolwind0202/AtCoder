#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, l = 0, ans = 0;
  cin >> n >> l;

  for (int i = 0; i < n; i++)
  {
    int a = 0;
    cin >> a;

    if (a >= l)
      ans++;
  }

  cout << ans << endl;

  return 0;
}