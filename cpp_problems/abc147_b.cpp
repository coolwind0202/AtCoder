#include <iostream>

using namespace std;

int main(void)
{
  int count = 0;
  size_t i = 0;
  string s;
  cin >> s;

  for (i = 0; i < s.length() / 2; i++)
  {
    if (s[i] != s[s.length() - 1 - i])
      count++;
  }

  cout << count << endl;
  return 0;
}