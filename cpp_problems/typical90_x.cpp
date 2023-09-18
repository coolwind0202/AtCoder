#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0;
  cin >> n;

  ll sum = 0LL, k = 0LL;
  cin >> k;

  vector<int> a(n), b(n);

  for (auto &x : a)
  {
    cin >> x;
  }

  for (auto &x : b)
  {
    cin >> x;
  }

  for (int i = 0; i < n; i++)
  {
    sum += abs(a[i] - b[i]);
  }

  if (k < sum)
  {
    cout << "No" << endl;
    return 0;
  }

  cout << ((k - sum) % 2 == 0 ? "Yes" : "No") << endl;
  return 0;
}