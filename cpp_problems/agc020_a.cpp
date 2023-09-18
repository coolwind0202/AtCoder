#include <iostream>

using namespace std;

int main(void)
{
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  cout << ((b - a - 1) % 2 == 0 ? "Borys" : "Alice") << endl;
  return 0;
}