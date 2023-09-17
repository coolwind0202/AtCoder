#include <iostream>

using namespace std;

int main(void)
{
  int a = 0, b = 0;
  cin >> a >> b;
  cout << (((a * b) % 2 != 0) ? "Yes" : "No") << endl;
  return 0;
}