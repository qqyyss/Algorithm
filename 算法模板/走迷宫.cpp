#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 105;

int n,m;

int d[N][N],g[N][N];
PII q[N * N],p[N][N];;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};


int bfs()
{
    int hh = 0,tt = 0;
    q[0] = {0,0};
    memset(d,-1,sizeof(d));
    d[0][0] = 0;
    while(hh <= tt)
    {
        int x = q[hh].first;
        int y = q[hh].second;
        hh++;
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m  && d[nx][ny] == -1 && g[nx][ny] == 0)
            {
                q[++tt] = {nx,ny};
                d[nx][ny] = d[x][y] + 1;
                p[nx][ny] = {x,y};
            }
        }
    }
    // int x = n-1,y = m-1;
    // while(x || y )
    // {
    //     cout << x << " " << y << endl;
    //     x = p[x][y].first;
    //     y = p[x][y].second;
    // }
    // puts("");
    // for(int i = 0;i < n;i++)
    // {
    //     for(int j = 0;j < m;j++)
    //     {
    //         cout << p[i][j].first << "," <<p[i][j].second << "    " ;
    //     }
    //     cout << endl;
    // }
        
 
    return d[n-1][m-1];
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> g[i][j];
    cout << bfs();
    return 0;
}