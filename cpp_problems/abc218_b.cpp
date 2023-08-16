#include <iostream>
using namespace std;

int main(void)
{
  int i = 0, in = 0;

  for (i = 0; i < 26; i++)
  {
    cin >> in;
    cout << (char)('a' + (in - 1));
  }
  cout << endl;

  return 0;
}