#include <iostream>

using namespace std;

int main(void)
{
  int N, A;
  cin >> N >> A;

  if (N % 500 <= A)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}