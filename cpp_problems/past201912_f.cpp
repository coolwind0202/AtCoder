#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
  string s, buf;
  cin >> s;
  vector<string> v;
  int length = s.length(), i = 0;

  while (i < length)
  {
    int j = 1;
    for (; i + j < length; j++)
    {
      if (isupper(s[i + j]))
        break;
    }
    buf = s.substr(i, j + 1);
    buf[0] = tolower(buf[0]);
    buf.back() = tolower(buf.back());

    v.push_back(buf);

    i = i + j + 1;
  }

  sort(v.begin(), v.end());

  for (string &s : v)
  {
    s[0] = toupper(s[0]);
    s.back() = toupper(s.back());
    cout << s;
  }
  cout << endl;
  return 0;
}