#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 200003;

int h[N],null = 0x3f3f3f3f;

int find(int x)
{
    int k = (x % N + N ) % N;
    while(h[k] != x && h[k] != null)
    {
        k++;
        if(k == N) k = 0;
    }
    return k;
}


int main()
{
    memset(h,0x3f,sizeof(h));
    string s;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> s >> x;
        int k = find(x);
        if(s == "I")
        {
            h[k] = x;
        }
        else
        {
            if(h[k] != null) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
    }
    

    return 0;
}