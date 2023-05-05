#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 1e6 + 10;

int m,n;
char S[N],P[N];
int ne[N];
int main()
{
    cin >> n >> P + 1 >> m>> S + 1;
    
    for(int i = 2,j = 0;i <= m;i++)
    {
        while(j && P[i] != P[j+1]) j = ne[j];
        if(P[i] == P[j + 1]) j++;
        ne[i] = j;
    }
    
    for(int i = 1,j = 0;i <= m;i++)
    {
        while(j && S[i] != P[j + 1]) j = ne[j];
        if(S[i] == P[j + 1]) j++;
        if(j == n)
        {
            printf("%d ",i - n);
            j = ne[j];
        }
    }
    
    return 0;
}