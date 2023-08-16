#include <iostream>
#include <vector>

using namespace std;

bool is_valid_triangle(int a, int b, int c)
{
  if (a == b || b == c || c == a)
    return false;
  if (a + b <= c || b + c <= a || c + a <= b)
    return false;
  return true;
}

int main(void)
{
  int N = 0, count = 0;
  cin >> N;
  vector<int> l(N);

  for (auto &a : l)
  {
    cin >> a;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        if (is_valid_triangle(l[i], l[j], l[k]))
        {
          count++;
        }
      }
    }
  }

  cout << count << endl;
  return 0;
}