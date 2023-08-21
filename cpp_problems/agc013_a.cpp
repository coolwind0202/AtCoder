#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
  int n = 0, state = 0, ans = 1;
  cin >> n;
  vector<ll> v(n);

  for (auto &a : v)
  {
    cin >> a;
  }

  for (int i = 0; i < n - 1; i++)
  {
    ll a = v[i], b = v[i + 1];
    if (state == 0)
    {
      /*
        現在は不明
      */
      if (a > b)
        state = -1;
      else if (a < b)
        state = 1;
      else
        state = 0;
    }
    else if (state == 1)
    {

      /*
        現在は非減少
        減少だったときのみ状態を変更する
      */
      if (a > b)
      {
        state = 0;
        ans++;
      }
    }
    else
    {
      /*
        現在は非増加
        増加だったときのみ状態を変更する
      */
      if (a < b)
      {
        state = 0;
        /*
          ここで増加状態になるとは確定しない
        */
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}