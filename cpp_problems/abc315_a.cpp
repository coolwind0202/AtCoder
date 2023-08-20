#include <iostream>
using namespace std;

int main(void)
{
  string s;
  cin >> s;

  for (auto c : s)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      continue;
    cout << c;
  }

  cout << endl;
  return 0;
}