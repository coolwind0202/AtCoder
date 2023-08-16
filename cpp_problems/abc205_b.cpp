#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N = 0;
  cin >> N;

  vector<int> A(N);

  for (auto &a : A)
  {
    cin >> a;
  }

  sort(A.begin(), A.end());

  for (int i = 0; i < N; i++)
  {
    if (A[i] != (i + 1))
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}