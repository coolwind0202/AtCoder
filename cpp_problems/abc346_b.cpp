#include <iostream>

using namespace std;

int main(void)
{
  int w = 0, b = 0;
  cin >> w >> b;

  int w_count[200] = {}, b_count[200] = {};

  string s;
  for (int i = 0; i < 16; i++)
  {
    s += "wbwbwwbwbwbw";
  }

  // make kukanwa
  for (int i = 1; i < 200; i++)
  {
    w_count[i] = w_count[i - 1] + (s[i] == 'w');
    b_count[i] = b_count[i - 1] + (s[i] == 'b');
    // cout << w_count[i] << " " << b_count[i] << endl;
  }

  // check w + b
  for (int i = w + b; i < 200; i++)
  {
    int ws = w_count[i] - w_count[i - (w + b)];
    int bs = b_count[i] - b_count[i - (w + b)];

    if (ws == w && bs == b)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

/**
 *
 * wbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw
 * wbwbwwbwbwbw
 */