#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int M = 0, sum = 0, middle = 0, cnt = 0, i = 1;
  cin >> M;

  vector<int> d(M);

  for (auto &a : d)
  {
    cin >> a;
    sum += a;
  }

  middle = (sum + 1) / 2;

  for (auto &a : d)
  {
    if (cnt <= middle && middle <= cnt + a)
    {
      // この月の中に、真ん中が存在する
      // 分からないこういう問題
      cout << i << " " << middle - cnt << endl;
      break;
    }
    cnt += a;
    i++;
  }

  return 0;
}