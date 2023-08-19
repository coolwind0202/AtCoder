#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<char, int> m;

int main(void)
{
  // 各文字の、文字列における登場回数の最小値を更新していく
  // 最後に足し合わせる

  int N = 0;
  string buf;
  cin >> N;

  cin >> buf;

  for (auto c : buf)
  {
    m[c]++;
  }

  for (int i = 1; i < N; i++)
  {
    cin >> buf;

    // 最初の文字列に存在しない文字が、存在したとしたら、それは無視すべき
    // 最初の文字列に存在し、かつこの文字列にも存在する文字は、維持すべき
    // 最初の文字列に存在したが、この文字列に存在しない文字は、無視すべき

    map<char, int> cnt;

    for (auto c : buf)
    {
      cnt[c]++;
    }

    vector<char> target_del;

    for (auto e : m)
    {
      if (cnt.find(e.first) == cnt.end())
      {
        // 最初の文字列に存在したが、この文字列に存在しないので削除
        target_del.push_back(e.first);
        continue;
      }

      m[e.first] = min(m[e.first], cnt[e.first]);
    }
    for (auto c : target_del)
    {
      m.erase(c);
    }

    // このループで処理されなかった文字は、最初の文字列に存在しなかったが、この文字列には存在する文字
  }

  for (auto e : m)
  {
    for (int i = 0; i < e.second; i++)
    {
      cout << e.first;
    }
  }
  cout << endl;

  return 0;
}