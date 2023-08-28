#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, m = 0, cnt = 0;
  cin >> n >> m;

  vector<long long> h(n);
  vector<bool> good(n, true);

  for (auto &a : h)
  {
    cin >> a;
  }

  for (int i = 0; i < m; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;

    if (h[a] <= h[b])
    {
      /*
        展望台aは、展望台b以下だから、aは良い展望台ではなくなった
      */
      good[a] = false;
    }
    if (h[b] <= h[a])
    {
      good[b] = false;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (good[i])
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}