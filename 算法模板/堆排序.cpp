#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;

int n,m,s;

int heap[N];

void down(int u)
{ 
    int t = u; 
    if(2 * u <= s && heap[t] > heap[2 * u]) t = 2 * u;
    if(2 * u + 1 <= s && heap[t] > heap[2 * u + 1]) t = 2 * u + 1;
    if(t != u)
    {
        swap(heap[u],heap[t]);
        down(t);
    }
}


int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> heap[i];
    s = n;
    
    for(int i = n / 2;i;i--) down(i);
    
    while(m--)
    {
        cout << heap[1] << ' ';
        heap[1] = heap[s];
        s --;
        down(1);
    }
    
    return 0;
}