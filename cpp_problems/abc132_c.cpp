#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0, min = 0, max = 0;
  cin >> N;
  vector<int> d(N);

  for (auto &a : d)
  {
    cin >> a;
  }

  sort(d.begin(), d.end());

  min = d[(N / 2) - 1];
  max = d[N / 2];

  cout << max - min << endl;

  return 0;
}