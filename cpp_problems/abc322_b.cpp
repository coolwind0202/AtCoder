#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;
  bool head = true, tail = true;
  ;

  string s, t;
  cin >> s >> t;

  for (int i = 0; i < n; i++)
  {
    if (s[i] != t[i])
    {
      head = false;
    }

    if (s[n - i - 1] != t[m - i - 1])
    {
      tail = false;
    }
  }

  if (head && tail)
  {
    cout << 0 << endl;
  }
  else if (head)
  {
    cout << 1 << endl;
  }
  else if (tail)
  {
    cout << 2 << endl;
  }
  else
  {
    cout << 3 << endl;
  }
  return 0;
}