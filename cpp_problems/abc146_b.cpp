#include <iostream>
using namespace std;

int main(void)
{
  int N = 0;
  string S;

  cin >> N >> S;

  for (auto c : S)
  {
    cout << (char)((((c + N) - 'A') % ('Z' - 'A' + 1)) + 'A');
  }
  cout << endl;
  return 0;
}