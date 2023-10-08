#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int n = 0, m = 0;
  cin >> n >> m;

  bool solved[100][100];

  vector<pair<int, int>> points(m);
  int player_p[100];

  for (int i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;
    points[i] = {tmp, i};
  }

  int max_p = 0;

  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;

    int p_i = i;

    for (int j = 0; j < m; j++)
    {
      if (tmp[j] == 'o')
      {
        solved[i][j] = true;
        p_i += points[j].first;
      }
      else
        solved[i][j] = false;
    }

    max_p = max(max_p, p_i);
    player_p[i] = p_i;
  }

  sort(points.begin(), points.end(), greater<pair<int, int>>());

  for (int i = 0; i < n; i++)
  {
    int rest = max_p - player_p[i];
    int cnt = 0;

    for (int j = 0; j < m && rest > 0; j++)
    {
      if (solved[i][points[j].second])
        continue;

      rest -= points[j].first;
      cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}