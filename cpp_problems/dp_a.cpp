#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<int> h(n);
  vector<int> c(n);

  for (auto &a : h)
  {
    cin >> a;
  }

  c[0] = 0;
  c[1] = abs(h[1] - h[0]);

  for (int i = 2; i < n; i++)
  {
    c[i] = min(abs(h[i] - h[i - 1]) + c[i - 1], abs(h[i] - h[i - 2]) + c[i - 2]);
  }

  cout << c[n - 1] << endl;
  return 0;
}