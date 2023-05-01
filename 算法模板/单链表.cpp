#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100000 + 10 ;

int e[N],idx,ne[N],head;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void del(int k)
{
    ne[k] = ne[ne[k]];
}

void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

int main()
{
    init();
    int M;
    cin >> M;
    while(M--)
    {
        char c;
        cin >> c;
        if(c == 'H') 
        {
            int x;
            cin >> x;
            add_to_head(x);
        }
        else if(c == 'D')
        {
            int k;
            cin >> k;
            if(!k) 
                head = ne[head];
            else
                del(k - 1);
        }
        else
        {
            int k,x;
            cin >> k >> x;
            add(k-1,x);
        }
    }
    for(int i = head;i != -1;i = ne[i]) cout << e[i] << " ";
    
    return 0;
}