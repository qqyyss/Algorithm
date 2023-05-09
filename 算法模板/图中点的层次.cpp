#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int e[N],ne[N],h[N],idx;
int d[N],q[N];
int n,m;

void add(int a,int b)
{
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = 1;
    memset(d,-1,sizeof d);
    d[1] = 0;
    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t];i != -1;i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
                q[++tt] = j;
                d[j] = d[t] + 1;
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n>> m;
    memset(h,-1,sizeof h);
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    cout << bfs();
    return 0;
}