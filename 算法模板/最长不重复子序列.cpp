#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 1e5 + 10;
int a[N],s[N];

int main()
{
    int n,res = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0,j = 0;i < n;i++)
    {
        s[a[i]] ++;
        while(s[a[i]] > 1) 
        {
            s[a[j]] --;
            j ++;
        }
        res = max(res,i - j + 1);
    }
    cout << res;
    return 0;
}