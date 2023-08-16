#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int distance_squared(vector<int> a, vector<int> b)
{
  int size = a.size();
  int sum = 0;

  for (int i = 0; i < size; i++)
  {
    int diff = a[i] - b[i];
    sum += diff * diff;
  }

  return sum;
}

bool is_perfect_square(int x)
{
  for (int i = 1; i <= sqrt(x); i++)
  {
    if (i * i == x)
      return true;
  }
  return false;
}

int main(void)
{
  int N = 0, D = 0, count = 0;
  cin >> N >> D;

  vector<vector<int>> l(N);

  for (auto &row : l)
  {
    for (int j = 0; j < D; j++)
    {
      int buf = 0;
      cin >> buf;
      row.push_back(buf);
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      int d = distance_squared(l[i], l[j]);
      if (is_perfect_square(d))
        count++;
    }
  }
  cout << count << endl;

  return 0;
}