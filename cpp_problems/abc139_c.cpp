#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0, cnt = 0, max_cnt = 0, a = 0, b = 0;
  cin >> n;
  cin >> a;

  for (int i = 1; i < n; i++)
  {
    cin >> b;
    if (b <= a)
    {
      cnt++;
    }
    else
    {
      cnt = 0;
    }
    max_cnt = max(max_cnt, cnt);

    a = b;
  }
  cout << max_cnt << endl;

  return 0;
}