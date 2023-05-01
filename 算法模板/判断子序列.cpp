#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n,m,t;
int a[N],b[N];

int main()
{
    
    cin >> n >> m;
    for(int i = 0;i < n;i ++) cin >> a[i];
    for(int i = 0;i < m;i ++) cin >> b[i];
    for(int j = 0;j < m;j ++)
    {
        if(b[j] == a[t] && t < n) t++;
    }
    if(t == n) cout << "Yes";
    else cout << "No";
    return 0;
}