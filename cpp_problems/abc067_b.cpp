#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0, K = 0, answer = 0;

  cin >> N >> K;

  vector<int> l(N);

  for (auto &a : l)
  {
    cin >> a;
  }

  sort(l.begin(), l.end(), greater<int>());

  for (int i = 0; i < K; i++)
  {
    answer += l[i];
  }

  cout << answer << endl;
  return 0;
}