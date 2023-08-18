#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int N = 0;
  string buf;
  map<char, int> x, y;
  vector<map<char, int>> l(N);

  for (auto &a : l)
  {
    cin >> buf;
    for (auto c : buf)
    {
      a[c]++;
    }
  }

  for (int i = 0; i < N; i++)
  {
    x = l[i];
    for (int j = i + 1; j < N; j++)
    {
      y = l[j];
    }
  }
  return 0;
}