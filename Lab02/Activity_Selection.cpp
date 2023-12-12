/*
Test 0: 
11
1 3 0 5 3 5 6 8 8 2 12
4 5 6 7 8 9 10 11 12 13 14
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
    vector<int> start,finish;
    vecin(start,n);
    vecin(finish,n);
    
    int last = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(start[i] >= last)
        {
            last = finish[i];
            cout << "A" << i+1 << " ";
        }
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