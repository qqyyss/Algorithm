#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100003;

int h[N],ne[N],idx,e[N];


void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++; 
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k];i != -1;i = ne[i])
    {
        if(e[i] == x) return true;
    }
    return false;
}

int main()
{
    memset(h,-1,sizeof(h));
    string s;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> s >> x;
        if(s == "I")
        {
            insert(x);
        }
        else
        {
            if(find(x)) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
    }
    

    return 0;
}