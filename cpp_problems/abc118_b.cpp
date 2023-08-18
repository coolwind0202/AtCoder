#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int N = 0, M = 0, K = 0, buf = 0, cnt = 0;
  cin >> N >> M;
  vector<int> l(M);

  for (int i = 0; i < N; i++)
  {
    cin >> K;
    for (int j = 0; j < K; j++)
    {
      cin >> buf;

      if (++l[buf - 1] == N)
        cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}