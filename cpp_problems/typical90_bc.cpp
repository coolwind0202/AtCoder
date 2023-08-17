#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  long long n = 0LL, p = 0LL, q = 0LL, buf = 0LL;
  int cnt = 0;
  cin >> n >> p >> q;
  vector<long long> l(n);

  for (auto &x : l)
  {
    cin >> buf;
    x = buf % p;
  }

  for (int a = 0; a < n; a++)
  {
    for (int b = a + 1; b < n; b++)
    {
      for (int c = b + 1; c < n; c++)
      {
        for (int d = c + 1; d < n; d++)
        {
          for (int e = d + 1; e < n; e++)
          {
            buf = ((((l[a] * l[b]) % p * l[c]) % p * l[d]) % p * l[e]) % p;
            if (buf == q)
              cnt++;
          }
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}