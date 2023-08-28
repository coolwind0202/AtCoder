#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;
  vector<int> l(n);

  for (int i = 0; i < n; i++)
  {
    cin >> l[i];
  }

  sort(l.begin(), l.end());

  for (int i = 0; i < n - 1; i++)
  {
    if (l[i] + 1 != l[i + 1])
    {
      /*
        これが段飛ばし
      */
      cout << l[i + 1] - 1 << endl;
      break;
    }
  }

  return 0;
}