#include <iostream>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  int before = 0, current = 0;
  cin >> before;

  for (int i = 1; i < n; i++)
  {
    cin >> current;
    cout << current * before;

    if (i + 1 < n)
    {
      cout << " ";
    }
    before = current;
  }
  cout << endl;

  return 0;
}