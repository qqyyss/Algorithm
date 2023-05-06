#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int h[N],ph[N],hp[N],siz;

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void up(int u)
{
    while(u/2 && h[u] < h[u / 2])
    {
        heap_swap(u,u/2);
        u = u / 2;
    }
}


void down(int u)
{
    int t = u;
    if(u * 2 <= siz && h[2 * u] < h[t]) t = 2 * u;
    if(u * 2 + 1 <= siz && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if(t != u) 
    {
        heap_swap(u,t);
        down(t);
    }
}


int main()
{
    int n,idx = 0;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if(s == "I")
        {
            int x;
            cin >> x;
            idx ++;
            siz ++;
            ph[idx] = siz;
            hp[siz] = idx;
            h[siz] = x;
            up(siz);
        }
        else if(s == "PM")
        {
            cout << h[1] << endl;
        }
        else if(s == "DM" )
        {
            heap_swap(1,siz);
            siz--;
            down(1);
        }
        else if(s == "D")
        {
            int k;
            cin >>k;
            k = ph[k];
            heap_swap(k,siz);
            siz--;
            up(k),down(k);
        }
        else if(s == "C")
        {
            int k,x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k),down(k);
        }
        
    }
    return 0;
}

