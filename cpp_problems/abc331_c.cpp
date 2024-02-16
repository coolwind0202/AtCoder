#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, int> SortedArrayEntry;

int main(void)
{

  int n = 0;
  ll sum = 0;
  cin >> n;

  vector<SortedArrayEntry> v(n);
  vector<ll> answer(n);
  map<ll, int> counter;

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first;
    v[i].second = i;
    counter[v[i].first]++;
  }

  auto comp = [](SortedArrayEntry a, SortedArrayEntry b)
  {
    return a.first > b.first;
  };

  sort(v.begin(), v.end(), comp);

  for (int i = 0; i < n; i++)
  {
    if (i > 0 && v[i - 1].first > v[i].first)
    {
      sum += v[i - 1].first * counter[v[i - 1].first];
    }
    answer[v[i].second] = sum;
  }

  int i = 0;

  for (i = 0; i < n - 1; i++)
  {
    cout << answer[i] << ' ';
  }

  cout << answer[i] << endl;

  return 0;
}