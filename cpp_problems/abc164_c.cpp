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
    l.insert(buf);
  }

  cout << l.size() << endl;
  return 0;
}