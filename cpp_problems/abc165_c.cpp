#include <iostream>

using namespace std;

struct Q
{
  int a;
  int b;
  int c;
  int d;
};

int main(void)
{
  int n = 0, m = 0, q = 0;
  int a[11] = {};
  struct Q qs[50] = {};
  cin >> n >> m >> q;

  for (int i = 0; i < q; i++)
  {
    struct Q &query = qs[i];
    cin >> query.a >> query.b >> query.c >> query.d;
  }

  auto search = [&](auto search, int i, int min_a)
  {
    if (i > n)
    {
      int ans = 0;
      for (int j = 0; j < q; j++)
      {
        struct Q query = qs[j];
        if (a[query.b] - a[query.a] == query.c)
          ans += query.d;
      }
      return ans;
    }
    int max_score = 0, score = 0;

    for (int j = min_a; j <= m; j++)
    {
      a[i] = j;

      score = search(search, i + 1, j);
      if (max_score < score)
      {
        max_score = score;
      }
    }
    return max_score;
  };
  cout << search(search, 1, 1) << endl;
  return 0;
}