#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  string s;
  cin >> s;

  map<char, int> count;

  int current_count = 1;

  for (int i = 0; i < n; i++)
  {
    if (i > 0)
    {
      if (s[i - 1] == s[i])
        current_count++;
      else
        current_count = 1;
    }

    count[s[i]] = max(count[s[i]], current_count);
  }

  int ans = 0;

  for (char c = 'a'; c <= 'z'; c++)
  {
    ans += count[c];
  }

  cout << ans << endl;
  return 0;
}