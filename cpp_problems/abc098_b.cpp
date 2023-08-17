#include <iostream>
#include <set>

using namespace std;

int main(void)
{
  int n = 0, ans = 0;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; i++)
  {
    set<char> l;
    for (int x = 0; x < i; x++)
    {
      for (int y = i; y < n; y++)
      {
        if (s[x] != s[y])
          continue;
        /*
          両方に含まれる文字を発見
        */
        l.insert(s[x]);
      }
    }
    if (l.size() > ans)
      ans = l.size();
  }
  cout << ans << endl;
  return 0;
}