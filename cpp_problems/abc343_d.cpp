#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0, t = 0;
  cin >> n >> t;

  // relation of point and count
  map<ll, ll> point_count;
  vector<ll> points(n);

  point_count[0] = n;

  for (int i = 0; i < t; i++)
  {
    ll a = 0, b = 0;
    cin >> a >> b;

    a--;
    ll before = points[a];
    ll after = points[a] += b;

    point_count[after]++;

    // cout << "+" << after << endl;
    // cout << "-" << before << endl;

    if ((--point_count[before]) == 0)
    {
      point_count.erase(before);
      // cout << "delete " << before << endl;
      // cout << point_count.size() << endl;
    }

    cout << point_count.size() << endl;
  }

  return 0;
}