#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>
using namespace std;

typedef tuple<int, int, long long> Datum;
typedef tuple<int, int> Result;

int main(void)
{
  int N = 0, M = 0, current_p = 0, count = 0, i = 0;

  vector<Datum> l(N);
  vector<Result> result(N);

  for (auto &a : l)
  {
    cin >> get<1>(a) >> get<2>(a);
    get<0>(a) = i;
    i++;
  }

  sort(l.begin(), l.end(), [](Datum a, Datum b)
       {
    if (get<1>(a) == get<1>(b)) {
      return get<2>(a) < get<2>(b);
    }
    return get<1>(a) < get<1>(b); });

  for (auto &a : l)
  {
    if (current_p != get<1>(a))
    {
      current_p = get<1>(a);
      count = 0;
    }

    cout << setfill('0') << right << setw(6) << get<1>(a) << count << endl;
    count++;
  }

  return 0;
}