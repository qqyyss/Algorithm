#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10,M = 31 * N;

int son[M][2],idx;
int a[N],res;

void insert(int x)
{
    int p = 0;
    for(int i = 30;i >= 0;i--)
    {
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0,res = 0;
    for(int i = 30;i >= 0;i--)
    {
        int u = x >> i & 1;
        if(son[p][!u])
        {
            res = res * 2 + 1;
            p = son[p][!u];
        }
        else 
        {
            res = res * 2 + 0;
            p = son[p][u];
        }
    }
    return res;
}


int main()
{
    int n;
    cin  >> n;
    for(int i =0;i < n;i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for(int i = 0;i < n;i++)
    {
        res = max(res,query(a[i]));
    }
    cout << res;
    return 0;
}