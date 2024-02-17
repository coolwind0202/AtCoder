#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0;

  cin >> n >> m;

  auto max_vote = make_pair(1, 0);

  vector<int> count(200001);

  for (int i = 0; i < m; i++)
  {
    int a = 0;
    cin >> a;

    count[a]++;

    if (count[a] > max_vote.second)
    {
      max_vote.first = a;
      max_vote.second = count[a];
    }

    if (count[a] == max_vote.second)
    {
      max_vote.first = min(max_vote.first, a);
    }

    cout << max_vote.first << endl;
  }

  return 0;
}