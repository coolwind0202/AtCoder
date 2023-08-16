#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> Datum;

int main(void)
{
  int N = 0, M = 0;
  cin >> N >> M;

  vector<vector<Datum>> l(N);
  string answer[M];

  for (int i = 0; i < M; i++)
  {
    int p = 0, y = 0;
    cin >> p >> y;

    l[p - 1].push_back({y, i});
  }

  for (int i = 0; i < N; i++)
  {
    sort(l[i].begin(), l[i].end());
    int count = 1;

    for (auto &a : l[i])
    {
      char buf[13];
      sprintf(buf, "%06d%06d", i + 1, count);
      answer[a.second] = string(buf);
      count++;
    }
  }

  for (auto a : answer)
  {
    cout << a << endl;
  }
  return 0;
}