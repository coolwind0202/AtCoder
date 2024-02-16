#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> ans(n);

  for (int i = 0; i < n; i++)
  {
    int a = 0;
    cin >> a;

    if (a <= l)
      ans[i] = l;
    else if (r <= a)
      ans[i] = r;
    else
      ans[i] = a;
  }
  int i = 0;

  for (i = 0; i < n - 1; i++)
  {
    cout << ans[i] << " ";
  }

  cout << ans[i] << endl;

  return 0;
}