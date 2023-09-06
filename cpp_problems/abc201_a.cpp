#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
  int a1 = 0, a2 = 0, a3 = 0;
  cin >> a1 >> a2 >> a3;

  auto check = [&]()
  {
    if (a2 - a1 == a3 - a2)
    {
      cout << "Yes" << endl;
      exit(0);
    }
  };

  auto swapcheck = [&](int &x, int &y)
  {
    swap(x, y);
    check();
    swap(x, y);
  };

  /*
    a1 と a2 を入れ替える
  */
  swapcheck(a1, a2);

  swapcheck(a2, a3);

  swapcheck(a1, a3);
  cout << "No" << endl;
  return 0;
}