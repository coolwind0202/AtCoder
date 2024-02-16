#include <iostream>

using namespace std;

int main(void)
{
  string s;
  cin >> s;

  int i = 0;

  for (i = 0; i < s.length() - 1; i++)
  {
    cout << s[i] << " ";
  }

  cout << s[i] << endl;
  return 0;
}