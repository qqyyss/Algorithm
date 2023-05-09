#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


const int N = 100010;
int n,m;
int e[N],h[N],ne[N],idx,d[N];
int q[N];


void add(int a,int b)
{
    e[idx] = b;ne[idx] = h[a];h[a] = idx ++;d[b]++;
}

bool bfs()
{
    int hh = 0,tt = -1;
    
    for(int i = 1;i <= n;i++)
        if(d[i] == 0)
            q[++tt] = i;
            
    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t];i != -1;i = ne[i])
        {
            int j = e[i];
            d[j] --;
            if(d[j] == 0)
                q[++tt] = j;
        }
    }
    return tt == n -1;
}

int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i =0 ;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    
    if(!bfs()) cout << -1;
    else
    {
        for(int i = 0;i < n;i++) cout << q[i] <<" ";
    }
    return 0;
}