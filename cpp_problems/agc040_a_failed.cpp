#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int min_a = 0, a = 0;
  ll ans = 0LL;
  size_t length = 0;
  string s;
  cin >> s;
  length = s.length();
  vector<int> l(length + 1);
  l[0] = 0;

  for (int i = 0; i < length; i++)
  {
    char c = s[i];
    if (c == '>')
    {
      a--;
    }
    else
    {
      a++;
    }
    l[i + 1] = a;
    min_a = min(a, min_a);
  }

  for (auto b : l)
  {
    ans += (b - min_a);
  }

  cout << ans << endl;

  return 0;
}