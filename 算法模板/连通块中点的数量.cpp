#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n,m,p[N],s[N];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        p[i] = i;
        s[i] = 1;
    }
    char op[5];
    int a,b;
    while(m--)
    {
        scanf("%s",op);
        int a,b;
        if(op[0] == 'C') 
        {
            scanf("%d%d",&a,&b);
            if(find(a) == find(b)) continue;
            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
        }
        else if(op[1] == '1') 
        {
            scanf("%d%d",&a,&b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            scanf("%d",&a);
            printf("%d\n",s[find(a)]);
        }
    }
    return 0;
}