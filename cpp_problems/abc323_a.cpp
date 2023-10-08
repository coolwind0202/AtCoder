#include <iostream>

using namespace std;

int main(void)
{
  string s;

  cin >> s;

  bool ok = true;

  for (int i = 2; i <= 16; i += 2)
  {
    if (s[i - 1] != '0')
    {
      ok = false;
      break;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}