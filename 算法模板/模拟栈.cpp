#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100000 + 10;

int stk[N];
int tt = 0;

void push(int x)
{
    stk[++tt] = x;
}

int pop()
{
    int tmp = stk[tt];
    tt--;
    return tmp;
}

bool empty()
{
    if(tt == 0) return true;
    return false;
}

int query()
{
    return stk[tt];
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