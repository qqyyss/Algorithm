#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int stk[N],tt;



int main()
{
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout<<stk[tt]<<' ';
        else cout << -1 <<' ';
        stk[++tt] = x;
    }
    return 0;
}