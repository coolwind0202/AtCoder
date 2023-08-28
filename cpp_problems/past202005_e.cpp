#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N = 0, M = 0, Q = 0;
  cin >> N >> M >> Q;
  string s;

  vector<vector<int>> G(N);
  vector<int> colors(N);

  for (int i = 0; i < M; i++)
  {
    int u = 0, v = 0;
    cin >> u >> v;

    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  for (int i = 0; i < N; i++)
  {
    int c = 0;
    cin >> c;
    colors[i] = c;
  }

  for (int i = 0; i < Q; i++)
  {
    int q = 0, x = 0;
    cin >> q >> x;
    cout << colors[x - 1] << endl;

    if (q == 1)
    {
      // 起動する
      vector<int> targets;
      targets = G[x - 1];
      for (auto a : targets)
      {
        colors[a] = colors[x - 1];
      }
    }
    else
    {
      int y = 0;
      cin >> y;
      colors[x - 1] = y;
    }
  }
}