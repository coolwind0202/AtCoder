#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
  string s;
  cin >> s;
  int n = s.length() + 1;
  long long ans = 0;
  vector<int> l(n);

  for (int i = 0; i < n - 1; i++)
  {
    /*
     */
    if (s[i] == '<')
    {
      l[i + 1] = max(l[i + 1], l[i] + 1);
    }
  }

  for (int i = n - 2; i >= 0; i--)
  {
    if (s[i] == '>')
    {
      l[i] = max(l[i], l[i + 1] + 1);
    }
  }

  for (auto b : l)
  {
    ans += b;
  }

  cout << ans << endl;

  return 0;
}