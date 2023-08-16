#include <iostream>

using namespace std;

int main(void)
{
  int H = 0, W = 0;
  string buf;
  cin >> H >> W;

  for (int i = 0; i < H; i++)
  {
    cin >> buf;
    cout << buf << endl
         << buf << endl;
  }

  return 0;
}