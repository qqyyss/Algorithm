#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;


void print(vector<int> c)
{
    for(int i = c.size()-1;i >= 0;i--)
    cout << c[i];
}

bool judge(vector<int> a,vector<int> b)
{
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = a.size() - 1;i >= 0;i--)
    {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}


vector<int> sub(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size();i ++)
    {
        // a[i] -= t;
        // if(i<b.size())
        // a[i] -= b[i];
        // c.push_back((a[i] + 10) %10 );
        // if(a[i] < 0 ) t = 1;
        // else t = 0;
        t = a[i] - t;
        if(i < b.size()) t-=b[i];
        c.push_back((t + 10) %10 );
        if(t < 0) t = 1;
        else t = 0;
    }
    while(c.back() == 0 && c.size() > 1) c.pop_back();
    return c;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> a,b,ans;
    for(int i = s1.size() - 1;i >= 0;i--) a.push_back(s1[i]-'0');
    for(int i = s2.size() - 1;i >= 0;i--) b.push_back(s2[i]-'0');
    if(judge(a,b))
    {
        ans = sub(a,b);
        // print(ans);
        for(int i = ans.size()-1;i >= 0;i--) printf("%d",ans[i]);
    }
    else
    {
        ans = sub(b,a);
        printf("%s","-");
        for(int i = ans.size()-1;i >= 0;i--) printf("%d",ans[i]);
    }

    return 0;
}
