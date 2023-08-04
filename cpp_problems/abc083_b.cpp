#include <iostream>

using namespace std;

int sum_digit(int x)
{
  int ans = 0;
  int i = 0;

  for (i = 0; i < 5; i++)
  {
    ans += x % 10;
    x /= 10;
  }

  return ans;
}

int main(void)
{
  int N, A, B;
  int i, sum;
  long long total = 0LL;

  cin >> N >> A >> B;

  for (i = 1LL; i <= N; i++)
  {
    sum = sum_digit(i);
    if (A <= sum && sum <= B)
      total += i;
  }

  cout << total << endl;

  return 0;
}