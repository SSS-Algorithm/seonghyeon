#include<bits/stdc++.h>
using namespace std;

int map[9][9];
vector<pair<int, int>> v;
bool f = false;

bool promissing(int sx, int sy)
{
  for(int i = 0; i < 9; i++)
  {
    if(sy != i && map[sx][sy] == map[sx][i]) return false;
    if(sx != i && map[sx][sy] == map[i][sy]) return false;
  }

  int nx = 3*(sx/3);
  int ny = 3*(sy/3);

  for(int i = nx; i < nx + 3; i++)
    for(int j = ny; j < ny + 3; j++)
      if(j != sy && i != sx && map[sx][sy] == map[i][j]) return false;

  return true;
}

void sudoku(int x)
{
  if(x == v.size()) 
  {
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        cout << map[i][j] << ' ';
      cout << '\n';
    }
    f = true;
    return;
  }

  for(int i = 1; i < 10; i++)
  {
    map[v[x].first][v[x].second] = i;

    if(promissing(v[x].first, v[x].second))
      sudoku(x + 1);
        
    if(f) return;
  }
  
  map[v[x].first][v[x].second] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
      {
        cin >> map[i][j];
        if(map[i][j] == 0) v.push_back({i, j});
      }
    }

    sudoku(0);

    return 0;
}