#include <iostream>
#include <set>
using namespace std;
int main(void)
{
  int N = 0;
  string buf;
  set<string> l;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> buf;
    if (l.find(buf) != l.end())
      continue;
    l.insert(buf);
    cout << i + 1 << endl;
  }

  return 0;
}