#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int q[N];
int hh = 0,tt = -1;

void push(int x)
{
    q[++tt] = x;
}

int pop()
{
    int tmp = q[hh];
    hh++;
    return tmp;
}

bool empty()
{
    if(hh > tt) return true;
    return false;
}

int query()
{
    return q[hh];
}

int main()
{
    int M;
    string q;
    cin >> M;
    while(M--)
    {
        cin >> q;
        if(q == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if(q == "pop") pop();
        else if(q == "empty") if(empty()) cout << "YES" <<endl; else cout << "NO" <<endl;
        else cout << query() <<endl;
    }
    return 0;
}
