#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

vector<PII> sec;

void merge(vector<PII> &a)
{
    vector<PII> res;
    sort(a.begin(),a.end());
    int st = -2e9,ed = -2e9;
    for(int i = 0;i < a.size();i++)
    {
        if(ed < a[i].first)
        {
            if(st != -2e9) res.push_back({st,ed});
            st = a[i].first,ed = a[i].second;
        }
        else
        {
            ed = max(ed,a[i].second);
        }
    }
    if(st != -2e9) res.push_back({st,ed});
    a = res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i <  n;i++)
    {
        int l,r;
        cin >> l >> r;
        sec.push_back({l,r});
    }
    merge(sec);
    cout << sec.size();
    return 0;
}