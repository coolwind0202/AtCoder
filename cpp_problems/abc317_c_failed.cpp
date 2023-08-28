#include <iostream>
#include<vector>

using namespace std;


int dfs(int i, int l, vector<vector<pair<int, int>>> g) {
  /*
    いまの点から移動できる次の街 g[i].N.first を考える
    いや

    どの街を選ぶか考えるほうが良い
    選ぶ際に、
  */

  
  dfs(i + 1, l + g[i], g);
  dfs(i, l, g);
}

int main(void){
  int n = 0, m = 0; 
  cin >> n >> m;

  // 街, 長さ
  vector<vector<pair<int, int>>> g(n);
  

  for (int i = 0; i < m; i++) {
    int a= 0, b = 0, c = 0;
    cin >> a >> b >> c;
    a--;
    b--;

    g[a].push_back({ b, c});
    g[b].push_back({ a, c});
  }

  /*
    DFS
  */

  dfs(0);
}