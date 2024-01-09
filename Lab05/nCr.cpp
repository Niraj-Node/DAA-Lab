//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution{
public:
    int nCr(int n, int r)
    {
        int cof[n+1][r+1] = {0};

        for(int i=0;i<=n;i++)
            cof[i][0] = 1;
        for(int i=0;i<=r;i++)
            cof[i][i] = 1;

        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=min(r,i); j++)
            {
                cof[i][j] = cof[i-1][j] + cof[i-1][j-1];
            }
        }

        return cof[n][r];
    }
};

//{ Driver Code Starts.
int main(){
    int n, r;
    cin>>n>>r;
    
    Solution ob;
    cout<<ob.nCr(n, r)<<endl;

    return 0;
}
// } Driver Code Ends