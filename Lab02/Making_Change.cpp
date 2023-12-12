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
    vector<int> denomination = {100, 50, 20, 10, 5, 2, 1};
    int n = denomination.size();
    int amt;
    cin >> amt;

    for(int i=0;i<n;i++)
    {
        if(amt <= 0) break;
        int no_note = amt/denomination[i];
        amt -= no_note*denomination[i];

        cout << denomination[i] << ":" << no_note << endl;
    }
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}