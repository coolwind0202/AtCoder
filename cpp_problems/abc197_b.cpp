#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
  int H = 0, W = 0, X = 0, Y = 0;

  cin >> H >> W >> X >> Y;
  X -= 1;
  Y -= 1;

  vector<string> l(H);
  set<pair<int, int>> a;

  for (auto &b : l)
  {
    cin >> b;
  }

  for (int z = 0; z <= Y; z++)
  {
    // 距離 z に対して
    // 左側
    if (l[X][Y - z] == '#')
      break;

    a.insert(make_pair(X, Y - z));
  }

  for (int z = 0; z < W - Y; z++)
  {
    // 右側
    if (l[X][Y + z] == '#')
      break;
    a.insert(make_pair(X, Y + z));
  }

  for (int z = 0; z <= X; z++)
  {
    if (l[X - z][Y] == '#')
      break;
    a.insert(make_pair(X - z, Y));
  }

  for (int z = 0; z < H - X; z++)
  {
    if (l[X + z][Y] == '#')
      break;
    a.insert(make_pair(X + z, Y));
  }

  cout << a.size() << endl;
  return 0;
}