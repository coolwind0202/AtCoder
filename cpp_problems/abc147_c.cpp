#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<vector<pair<int, bool>>> msg(n, vector<pair<int, bool>>());

  for (int i = 0; i < n; i++)
  {
    int a = 0;
    cin >> a;
    msg[i].resize(a);

    for (auto &j : msg[i])
    {
      int x = 0, y = 0;
      cin >> x >> y;
      x--;

      j.first = x;
      j.second = y == 1;
    }
  }

  int ans = 0;

  for (int c = 0; c < (1 << n); c++)
  {
    int msg_honest_cnt = 0;
    bool acceptable = true;
    for (int j = 0; j < n; j++)
    {
      if (((c >> j) & 1) == 0)
      {
        /*
          不親切と仮定したので、無視する
        */
        continue;
      }

      msg_honest_cnt++;

      for (auto l : msg[j])
      {
        bool is_expected_honest = ((c >> l.first) & 1) == 1;

        if (is_expected_honest)
        {
          /*
            この者を正直者と仮定している
          */
          if (l.second == 0)
          {
            /*
              正直者と仮定したのにも関わらず、証言者は不親切と言った
            */
            acceptable = false;
            break;
          }
        }
        else
        {
          /*
            この者を不親切だと仮定している
          */
          if (l.second == 1)
          {
            /*
              不親切と仮定したのにも関わらず、証言者は正直者だと言った
            */
            acceptable = false;
            break;
          }
        }
      }
      if (!acceptable)
        break;
    }
    if (!acceptable)
      continue;

    if (ans < msg_honest_cnt)
      ans = msg_honest_cnt;
  }
  cout << ans << endl;

  return 0;
}