#include <cstdlib>
#include <iostream>

using namespace std;
char s[101][101];

void dfs(int x , int y){
  if(s[x][y] == '*')
    return;
  s[x][y] = '*';
  dfs(x - 1 , y - 1);
  dfs(x - 1 , y);
  dfs(x - 1 , y + 1);
  dfs(x , y - 1);
  dfs(x , y + 1);
  dfs(x + 1 , y - 1);
  dfs(x + 1 , y);
  dfs(x + 1 , y + 1);
}

int main(int argc, char *argv[]) {
  int m, n, w;
  while(cin >> m >> n) {
    if ( m == 0 && n == 0)
      break;
    w = 0;
    for(int i = 0; i < m + 2; i++)
      for(int j = 0; j < n + 2; j++)
        s[i][j] = '*';
    for(int i = 1; i <= m; i++)
      for(int j = 1;j <= n; j++)
        cin >> s[i][j];
    for(int i = 1; i <= m; i++)
      for(int j = 1; j <= n; j++)
        if(s[i][j] == '@') {
          dfs(i,j);
          w++;
        }
    cout << w << endl;
  }
  //system("PAUSE");
  return EXIT_SUCCESS;
}
