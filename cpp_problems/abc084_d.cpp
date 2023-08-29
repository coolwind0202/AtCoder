#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int q = 0;
  cin >> q;

  set<int> primes;
  primes.insert(2);

  vector<int> prime_count(100000 + 1);

  for (int i = 3; i <= 100000; i++)
  {
    bool is_prime = true;
    for (auto prime : primes)
    {
      if (i % prime == 0)
      {
        is_prime = false;
        break;
      }
      if (prime * prime > i)
        break;
    }
    if (is_prime)
      primes.insert(i);

    /*
      0始まりにする
      累積和更新
    */
    int t = i - 1;
    prime_count[t + 1] = prime_count[t] + (is_prime && (primes.find((i + 1) / 2) != primes.end()));
  }

  for (int i = 0; i < q; i++)
  {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;

    cout << prime_count[r + 1] - prime_count[l] << endl;
  }

  return 0;
}