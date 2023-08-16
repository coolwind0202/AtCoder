#include <iostream>

using namespace std;

int main(void)
{
  int N = 0, H = 0, max = 0, count = 0;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> H;

    if (H >= max)
    {
      max = H;
      count++;
    }
  }

  cout << count << endl;

  return 0;
}