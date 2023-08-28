#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<int> l(n);

  for (int i = 1; i < n; i++)
  {
    int a = 0;
    cin >> a;
    a--;

    l[a]++;
  }

  for (auto a : l)
  {
    cout << a << endl;
  }

  return 0;
}