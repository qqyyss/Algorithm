#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int A[N],B[N];

int main()
{
    int n,m,x;
    cin >> n >> m >> x;
    for(int i = 0;i < n;i++) cin >> A[i];
    for(int i = 0;i < m;i++) cin >> B[i];
    
    for(int i = 0,j = m-1;i < n;i ++)
    {
        while(A[i] + B[j] > x) j--;
        if(A[i] + B[j] == x) cout << i << " " << j;
    }
    return 0;
}