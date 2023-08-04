#include <iostream>
using namespace std;

int main(void)
{
  int K, A, B;
  int i = 1;
  cin >> K >> A >> B;

  while (K * i <= B)
  {
    if (A <= K * i)
    {
      cout << "OK" << endl;
      return 0;
    }
    i++;
  }

  cout << "NG" << endl;

  return 0;
}