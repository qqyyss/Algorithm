#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int,int> PII;

const int N = 150005;
int h[N],ne[N],idx,w[N],e[N];
int n,m;
int d[N];
bool st[N];

void add(int a,int b,int c)
{
    ne[idx] = h[a];e[idx] = b; w[idx]  = c; h[a] = idx++;
}

int dijkstra()
{
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver];i != -1;i = ne[i])
        {
            int j = e[i];
            if(d[j] > w[i] + distance)
            {
                d[j] = w[i] + distance;
                heap.push({d[j],j});
            }
        }
    }
    if(d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}


int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int x,y,z;
        cin >> x>> y >> z;
        add(x,y,z);
    }
    cout << dijkstra();
    return 0;
}