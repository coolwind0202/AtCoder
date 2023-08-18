#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  int N = 0;
  long long cnt = 0, t = 0;
  string buf;
  map<string, long long> l;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    sort(buf.begin(), buf.end());
    l[buf]++;
  }

  for (auto entry : l)
  {
    if (entry.second < 2)
      continue;
    t = entry.second;

    cnt += t * (t - 1) / 2;
  }

  cout << cnt << endl;
  return 0;
}