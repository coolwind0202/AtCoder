#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0, q = 0;
  cin >> n;

  vector<int> s1(n + 1);
  vector<int> s2(n + 1);

  for (int i = 0; i < n; i++)
  {
    int c = 0, p = 0;
    cin >> c >> p;

    /*
      edit 1: 1組の情報でなかった場合でも、区間和は、「前の要素と同じにする」という形で更新する
      元々 if で書いていたが、三項演算子のほうが綺麗
    */
    s1[i + 1] = s1[i] + (c == 1 ? p : 0);
    s2[i + 1] = s2[i] + (c == 2 ? p : 0);
  }
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;

    /*
      両端を含む和を取りたい。
      a[r - 1]までの和になってしまうから、r + 1が必要
    */
    cout << s1[r + 1] - s1[l] << " " << s2[r + 1] - s2[l] << endl;
  }

  return 0;
}