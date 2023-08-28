#include <iostream>
#include <set>
using namespace std;

set<int> followee[100];
set<int> follower[100];

int main(void)
{
  int n = 0, q = 0;
  cin >> n >> q;

  for (int i = 0; i < q; i++)
  {
    int t = 0, a = 0, b = 0;
    cin >> t >> a;
    a--;
    if (t == 1)
    {
      cin >> b;
      b--;
      followee[a].insert(b); // a がフォローしている人 に b が加わる
      follower[b].insert(a); // b をフォローしている人 に a が加わる
    }
    else if (t == 2)
    {
      for (auto m : follower[a])
      {
        followee[a].insert(m);
        follower[m].insert(a);
      }
    }
    else
    {
      set<int> follow_target;
      for (auto m : followee[a])
      {
        for (auto l : followee[m])
        {
          if (l == a)
            continue;
          /*
            注意！
            ループ対象配列に対する変更はループ外で行う
          */
          follow_target.insert(l);
        }
      }

      for (auto l : follow_target)
      {
        followee[a].insert(l);
        follower[l].insert(a);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (followee[i].find(j) != followee[i].end())
      {
        cout << "Y";
      }
      else
      {
        cout << "N";
      }
    }
    cout << endl;
  }

  return 0;
}