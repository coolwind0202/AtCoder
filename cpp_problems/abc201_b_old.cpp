#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> Data;

int main(void)
{
  int N = 0;
  cin >> N;

  vector<Data> data(N);

  for (auto &a : data)
  {
    cin >> a.first >> a.second;
  }

  sort(data.begin(), data.end(), [](Data a, Data b)
       { return a.second > b.second; });
  cout << data[1].first << endl;
}