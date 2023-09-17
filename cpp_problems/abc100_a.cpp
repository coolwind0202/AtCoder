#include <iostream>

using namespace std;

int main(void)
{
  int a = 0, b = 0;
  cin >> a >> b;

  /*
    1個飛ばしに取っていき8個取るのが最適なので、8個以上は取れない
    8個以下であれば、1個飛ばしのうち任意の切片を飛ばせばよい。
  */
  cout << (a <= 8 && b <= 8 ? "Yay!" : ":(") << endl;
  return 0;
}