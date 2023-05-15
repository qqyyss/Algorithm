#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int M = 10000 + 10,N = 510;
int n,m,k;
int d[N],backup[N];

struct Edge{
    int a,b,w;
}edges[M];

bool bellman_ford()
{
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    for(int i = 0;i < k;i++)
    {
        memcpy(backup,d,sizeof d);
        for(int j = 0;j < m;j++)
        {
            int a = edges[j].a,b = edges[j].b,w = edges[j].w;
            d[b] = min(d[b],backup[a] + w);
        }
    }
    if(d[n] > 0x3f3f3f3f / 2) return false;
    return true;
}



int main()
{
    cin >> n >> m >> k;
    
    for(int i = 0;i < m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        edges[i] = {x,y,z};
    }
    
    if(!bellman_ford()) cout << "impossible";
    else cout << d[n];
    return 0;
}