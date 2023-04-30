#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0;i < A.size() || i < B.size();i++)
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> A,B,ans;
    for(int i = s1.size()-1;i >= 0;i--) A.push_back(s1[i] - '0');
    for(int i = s2.size()-1;i >= 0;i--) B.push_back(s2[i] - '0');
    
    ans = add(A,B);
    
    for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i]; 
    return 0;
}