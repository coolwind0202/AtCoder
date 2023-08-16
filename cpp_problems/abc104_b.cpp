#include <iostream>

using namespace std;

bool isAC(string s)
{
  int c_count = 0;
  if (s[0] != 'A')
    return false;
  if (isupper(s[1]))
    return false;

  for (auto c : s.substr(2, (s.length() - 3)))
  {
    if (isupper(c) && c != 'C')
      return false;
    if (c == 'C')
      c_count++;
  }

  if (c_count != 1)
    return false;

  if (isupper(s[s.length() - 1]))
    return false;

  return true;
}

int main(void)
{
  string s;
  cin >> s;

  cout << (isAC(s) ? "AC" : "WA") << endl;
  return 0;
}