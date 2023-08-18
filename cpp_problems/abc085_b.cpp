#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N = 0, buf = 0, count = 0;
  bool exists[101];
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    exists[i] = false;
  }

  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    exists[buf] = true;
  }

  for (int i = 1; i <= 100; i++)
  {
    if (exists[i] == true)
      count++;
  }

  cout << count << endl;
  return 0;
}