#include <iostream>

#include <vector>
using namespace std;

int main(void)
{
  int n = 0, a = 0, b = 0, c = 0;
  cin >> n >> a >> b >> c;

  int length[8] = {};

  for (int i = 0; i < n; i++)
  {
    cin >> length[i];
  }

  char choice[8] = {};

  auto search = [&](char type, int goal) -> int
  {
    vector<int> items;
    for (int i = 0; i < n; i++)
    {
      if (choice[i] == type)
      {
        items.push_back(length[i]);
      }
    }

    int len = (int)items.size();
    int ans = INT16_MAX;

    for (int c = 1; c < (1 << len); c++)
    {
      int length_sum = 0, use_item_cnt = 0;
      int mp = 0;

      for (int i = 0; i < len; i++)
      {
        if ((c >> i) & 1)
        {
          length_sum += items[i];
          use_item_cnt++;
        }
      }

      if (use_item_cnt > 1)
      {
        mp += (use_item_cnt - 1) * 10;
      }

      mp += abs(length_sum - goal);

      if (ans > mp)
        ans = mp;
    }

    return ans;
  };

  auto choose = [&](auto choose, int i) -> int
  {
    if (i == n)
    {
      return search('a', a) + search('b', b) + search('c', c);
    }

    int ans = INT16_MAX;

    choice[i] = 'a';
    int a = choose(choose, i + 1);
    ans = min(a, ans);

    choice[i] = 'b';
    int b = choose(choose, i + 1);
    ans = min(b, ans);

    choice[i] = 'c';
    int c = choose(choose, i + 1);
    ans = min(c, ans);

    return ans;
  };

  cout << choose(choose, 0) << endl;
  return 0;
}