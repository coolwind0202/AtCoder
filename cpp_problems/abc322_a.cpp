#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 0; i + 2 < n; i++)
  {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
    {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}