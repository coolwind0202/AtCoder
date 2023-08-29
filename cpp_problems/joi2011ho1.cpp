#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<vector<int>> j_count(n + 1, vector<int>(m + 1));
  vector<vector<int>> o_count(n + 1, vector<int>(m + 1));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;

      j_count[i + 1][j + 1] = j_count[i][j + 1] + j_count[i + 1][j] - j_count[i][j] + (c == 'J');
      o_count[i + 1][j + 1] = o_count[i][j + 1] + o_count[i + 1][j] - o_count[i][j] + (c == 'O');
    }
  }

  for (int i = 0; i < k; i++)
  {
    int a = 0, b = 0, c = 0, d = 0, j_sum = 0, o_sum = 0;
    cin >> a >> b >> c >> d;

    a--;
    b--;
    c--;
    d--;

    j_sum = j_count[c + 1][d + 1] - j_count[a][d + 1] - j_count[c + 1][b] + j_count[a][b];
    o_sum = o_count[c + 1][d + 1] - o_count[a][d + 1] - o_count[c + 1][b] + o_count[a][b];

    cout << j_sum << " " << o_sum << " " << (d - b + 1) * (c - a + 1) - (o_sum + j_sum) << endl;
  }

  return 0;
}