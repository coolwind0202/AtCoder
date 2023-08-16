#include <iostream>

using namespace std;

int main(void)
{
  int min_diff_count = INT32_MAX;
  size_t s_len = 0, t_len = 0;
  string S, T;
  cin >> S >> T;

  s_len = S.length();
  t_len = T.length();

  for (size_t a = 0; a < s_len; a++)
  {
    // a を開始地点として、部分文字列になるように範囲を広げる
    int diff_count = 0;
    size_t i = 0;
    for (i = 0; i < t_len && a + i < s_len; i++)
    {
      // 長さ i として考える
      if (S[a + i] != T[i])
        diff_count++;
    }
    if (i != t_len)
      continue;
    if (diff_count < min_diff_count)
      min_diff_count = diff_count;
  }

  cout << min_diff_count << endl;
}