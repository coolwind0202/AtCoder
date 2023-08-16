#include <iostream>

using namespace std;

bool equal(string a, string b)
{
  size_t i = 0;

  if (a.length() != b.length())
    return false;

  while (i < a.length() && i < b.length())
  {
    if (a[i] != b[i])
      return false;

    i++;
  }

  return true;
}

int main(void)
{
  string s, t;
  cin >> s;
  t = string("Hello,World!");

  cout << (equal(s, t) ? "AC" : "WA") << endl;

  return 0;
}