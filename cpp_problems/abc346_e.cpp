#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main(void)
{
  ll h = 0, w = 0, m = 0;
  cin >> h >> w >> m;

  vector<int> t(m);
  vector<int> a(m);
  vector<int> x(m);

  vector<bool> hs(h);
  vector<bool> ws(w);

  ll hc = h, wc = w;

  map<int, ll> color_count;

  for (int i = 0; i < m; i++)
  {
    cin >> t[i] >> a[i] >> x[i];
    a[i]--;
  }

  for (int i = m - 1; i >= 0; i--)
  {
    if (t[i] == 1)
    {
      if (!hs[a[i]])
      {
        hs[a[i]] = true;
        if (wc > 0)
          color_count[x[i]] += wc;
        hc--;
      }
    }
    else
    {
      if (!ws[a[i]])
      {
        ws[a[i]] = true;
        if (hc > 0)
          color_count[x[i]] += hc;
        wc--;
      }
    }
  }
  if (hc * wc > 0)
    color_count[0] += hc * wc;

  cout << color_count.size() << endl;
  for (auto p : color_count)
  {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}