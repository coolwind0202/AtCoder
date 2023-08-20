#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  string s;
  int length = 0, i = 0;
  cin >> s;

  length = s.length();

  while (i < length)
  {
    int j = 1;
    for (; i + j < length; j++)
    {
      if (s[i + j] != s[i + j - 1])
      {
        cout << s[i] << j;
        break;
      }
    }
    /*
      いま、 s[i + j] != s[i + j - 1]である
    */

    if (i + j == length)
    {
      /*
        s[i + j] == s[i + j - 1]のまま終端
      */
      cout << s[i] << j;
    }

    i = i + j;
  }
  cout << endl;

  return 0;
}