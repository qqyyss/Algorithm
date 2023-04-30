#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> mul(vector<int> a,int b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size() || t;i++)
    {
        if(i < a.size()) t += b * a[i];
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main()
{
    string a;
    int b;
    cin >> a >>b;
    vector<int> A,ans;
    for(int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
    ans = mul(A,b);
    for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i];
        
    return 0;
}