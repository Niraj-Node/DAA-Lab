/*
Test 0: 
4
60
280 100 120 120
40 10 20 24
*/

#include<bits/stdc++.h>
using namespace std;

//=======================//
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
//=======================//

void vecin(vector<int>& v,int n)
{
    for(int i=0;i<n;i++) 
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void vecp(vector<int>& v)
{
    for(int i=0;i<(int)v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    int cap;
    cin >> cap;
    vector<int> profit,weight;
    vecin(profit,n);
    vecin(weight,n);
    map<double,int> ratio;

    for(int i=0;i<n;i++)
    {
        ratio[profit[i]/weight[i]] = i;
    }

    int ans = 0;
    for(auto it = ratio.rbegin(); it != ratio.rend(); it++)
    {
        if(cap <= 0) break;
        int idx = it->second;
        if(weight[idx] <= cap) ans += profit[idx], cap -= weight[idx];
        else ans += cap*(it->first), cap = 0; 
    }

    cout << ans << endl;
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}