#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0, K = 0, buf = 0, ans = 0;
  map<int, int> l;
  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    cin >> buf;

    l[buf]++;
  }

  vector<int> values;

  for (auto e : l)
  {
    values.push_back(e.second);
  }

  sort(values.begin(), values.end());

  for (int i = 0; i < (int)values.size() - K; i++)
  {
    ans += values[i];
  }

  cout << ans << endl;
  return 0;
}