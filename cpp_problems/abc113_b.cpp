#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, float> Data;

int main(void)
{
  int N = 0, T = 0, A = 0;
  cin >> N >> T >> A;

  vector<Data> diff(N);

  for (int i = 0; i < N; i++)
  {
    float H = 0, temp = 0;
    cin >> H;

    temp = (float)T - H * 0.006;

    auto &a = diff[i];
    a.first = i;
    a.second = abs(temp - A);
  }

  sort(diff.begin(), diff.end(), [](Data a, Data b)
       { return a.second < b.second; });

  cout << diff[0].first + 1 << endl;
}