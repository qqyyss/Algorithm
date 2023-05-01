#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000 + 10;

int a[N],b[N];

void insert(int l,int r, int c)
{
    b[l ] += c;
    b[r + 1] -=c;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) insert(i,i,a[i]);
    while(m--)
    {
        int l,r,c;
        cin >> l >> r >> c;
        insert(l,r,c);
    }
    for(int i = 1;i <= n;i++) a[i] = a[i-1] + b[i];
    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    
    return 0;
}