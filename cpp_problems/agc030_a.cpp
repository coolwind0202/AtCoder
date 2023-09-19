#include <iostream>

using namespace std;

int main(void)
{
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  int eat_poison = min(a + b + 1, c);

  cout << b + eat_poison << endl;
}