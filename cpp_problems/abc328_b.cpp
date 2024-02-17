#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

  int n = 0;
  cin >> n;

  vector<int> d(n);

  for (int i = 0; i < n; i++)
  {
    cin >> d[i];
  }

  int month = 1, date = 1;
  int ans = 0;

  for (; month <= n; month++)
  {
    string month_s = to_string(month);

    for (auto c : month_s)
      if (month_s[0] != c)
        goto next_month;

    for (date = 1; date <= d[month - 1]; date++)
    {
      // zorome?
      string date_s = to_string(date);
      for (auto c : date_s)
        if (date_s[0] != month_s[0] || date_s[0] != c)
          goto next_date;
      ans++;
    next_date:;
    }
  next_month:;
  }

  cout << ans << endl;

  return 0;
}