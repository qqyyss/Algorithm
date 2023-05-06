#include<iostream>
#include<algorithm>

using namespace std;

const int N = 50000 + 10;

int p[N],d[N];

int n,k,res;


int find(int x)
{
    if(p[x] != x) 
    {
        int tmp = find(p[x]);
        d[x] += d[p[x]];
        p[x] = tmp;
    }
    return p[x];
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) p[i] = i;
    while(k--)
    {
        int D,x,y;
        scanf("%d%d%d",&D,&x,&y);
        if(x > n || y > n) res++;
        else
        {
            int px = find(x),py = find(y);
            if(D == 1)
            {
                if(px == py && (d[x] - d[y]) % 3 !=0) res ++;
                elseif(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if(px == py && (d[x] -d[y] - 1) % 3 != 0) res++; 
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] -d[x] + 1; 
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}