#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 505,INF = 0x3f3f3f3f;

int g[N][N],dist[N];
bool st[N];
int n,m;


int prime()
{
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    for(int  i = 0;i < n;i++)
    {
        int t = -1;
        for(int j = 1;j <= n;j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        if(i && dist[t] == INF ) return INF;
        
        if(i) res += dist[t];
        
        for(int j = 1;j <= n;j++) dist[j] = min(dist[j],g[t][j]);
        st[t] = true;
    }
    return res;
}

int main()
{
    memset(g,0x3f,sizeof g);
    cin >> n >> m;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v],w);
    }
    int t = prime();
    if(t == INF) puts("impossible");
    else cout << t;
    return 0;
}