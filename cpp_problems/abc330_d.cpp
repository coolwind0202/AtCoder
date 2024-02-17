#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  vector<int> row_counts(n);
  vector<int> column_counts(n);
  vector<string> input(n);

  // update row counts
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];

    for (int j = 0; j < n; j++)
    {
      if (input[i][j] == 'o')
        row_counts[i]++;
    }
  }

  // update column counts

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (input[j][i] == 'o')
        column_counts[i]++;
    }
  }

  long long ans = 0LL;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (input[i][j] == 'o')
        // how many 3-pair?
        ans += (row_counts[i] - 1) * (column_counts[j] - 1);
    }
  }

  cout << ans << endl;

  return 0;
}