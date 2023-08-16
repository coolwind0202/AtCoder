#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0, K = 0;
  long long hmin = 0LL, hmax = 0LL, answer = __LONG_LONG_MAX__, diff = 0LL;

  cin >> N >> K;

  vector<long long> h(N);

  for (auto &a : h)
  {
    cin >> a;
  }

  sort(h.begin(), h.end());

  for (int i = 0; i < N; i++)
  {
    if (i + K - 1 == N)
      break;

    hmin = h[i];
    hmax = h[i + K - 1];

    diff = hmax - hmin;

    if (answer > diff)
      answer = diff;
  }

  cout << answer << endl;
}