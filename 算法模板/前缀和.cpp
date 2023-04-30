#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010 + 10;

int n,m;

int a[N],s[N];

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        int t;
        cin >> t;
        s[i + 1] += s[i] + t; 
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] <<endl;
    }
    return 0;
}