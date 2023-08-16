#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, int> Store;

int main(void)
{
  int N = 0, M = 0, i = 0;
  long long money = 0LL;
  cin >> N >> M;

  vector<Store> s(N);

  for (auto &a : s)
  {
    cin >> a.first >> a.second;
  }

  sort(s.begin(), s.end(), [](Store a, Store b)
       { return a.first < b.first; });

  while (true)
  {
    if (i == N)
    {
      // undefined
      return -1;
    }

    // 先頭から買い占める戦略（お金は無限）

    if (s[i].second < M)
    {
      // 全て買い占めて良い
      M -= s[i].second;
      money += s[i].first * s[i].second;
    }
    else
    {
      // 一部を残して終えるのが最適
      money += s[i].first * M;
      break;
    }

    i++;
  }

  cout << money << endl;
}