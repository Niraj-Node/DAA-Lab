#include<bits/stdc++.h>
using namespace std;

//=======================//
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define int long long
#define ll long long
#define llu unsigned long long
#define pii pair<int, int>
#define F first
#define S second
#define pb emplace_back
#define all(a) a.begin(), a.end()

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define fo(i,n) for(int i=0;i<n;i++)
#define refo(i,n) for(int i=n-1;i>=0;i--)
#define fok(i,k,n) for(int i=k;i<n;i++)
#define refok(i,k,n) for(int i=n-1;i>=k;i--)
#define tr(it,a) for(auto it = a.begin(); it != a.end(); it++)
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
    string s;
    cin >> s;
 
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='r')
            cout << i+1 << endl;
    }
   
    for(int i=s.size()-1;i>=0;i--)
        if(s[i]=='l')
            cout << i+1 << endl;
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}