#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0, total = 0;
  cin >> N;
  vector<int> a(N);

  for (auto &x : a)
  {
    cin >> x;
  }

  sort(a.begin(), a.end(), greater<int>());

  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0)
    {
      // Alice のTurn
      total += a[i];
    }
    else
    {
      total -= a[i];
    }
  }

  cout << total << endl;

  return 0;
}