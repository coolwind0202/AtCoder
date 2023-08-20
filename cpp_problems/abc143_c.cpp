#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, cnt = 1;
  string s;
  cin >> n >> s;

  for (int i = 1; i < n; i++)
  {
    if (s[i] != s[i - 1])
      cnt++;
  }

  cout << cnt << endl;
  return 0;
}