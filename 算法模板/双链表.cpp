#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100000 + 10;

int e[N],l[N],r[N],idx;

void init()
{
    idx = 2;
    r[0] = 1;
    l[1] = 0;
}


void add(int k,int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}



void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    int M;
    cin >> M;
    while(M--)
    {
        string op;
        cin >> op;
        if(op == "L")
        {
            int x;
            cin >> x;
            add(0,x);
        }
        else if(op == "R")
        {
            int x;
            cin >> x;
            add(l[1],x);
        }
        else if(op == "D") 
        {
            int k;
            cin >> k;
            remove(k+1);
        }
        else if(op == "IL")
        {
            int k,x;
            cin >> k >> x;
            add(l[k+1],x);
        }
        else
        {
            int k,x;
            cin >> k >> x;
            add(k+1,x);
        }
    }
    for(int i = r[0];i != 1;i = r[i]) cout << e[i] << " ";
    
    return 0;
}