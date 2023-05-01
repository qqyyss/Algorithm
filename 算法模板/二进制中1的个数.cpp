#include<iostream>
#include<algorithm>

using namespace std;


int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n,t;
    cin >> n;
    while(n--)
    {
        int x,res = 0;
        cin >> x;
        while(x) x-=lowbit(x),res ++;
        cout << res << " ";
    }
    return 0;
}