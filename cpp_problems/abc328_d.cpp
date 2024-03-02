#include <iostream>

using namespace std;

int main(void)
{
  string s;
  cin >> s;

  size_t len = s.length();
  string ans;

  for (int i = 0; i < len; i++)
  {
    ans += s[i];
    size_t ans_len = ans.length();
    if (ans_len >= 3 && ans.substr(ans_len - 3) == "ABC")
    {
      ans = ans.substr(0, ans_len - 3);
    }
  }

  cout << ans << endl;

  return 0;
}