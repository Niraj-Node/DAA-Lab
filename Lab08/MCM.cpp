//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
private:

    string solve(int start, int end, vector<vector<int>> split)
    {
        if(start == end) return string(1, char('A'+start-1));
        
        int k = split[start][end];
        return "(" + solve(start, k, split) + solve(k+1, end, split) + ")";
    }

    int matrixMultiplication(int arr[], int start, int end, vector<vector<int>>& dp, vector<vector<int>>& split)
    {
        if(start == end) return 0;
        
        if(dp[start][end] != INT_MAX) return dp[start][end];
        
        for(int k = start; k < end; k++)  // cut is after k, so k<end
        {
            int cost = matrixMultiplication(arr, start, k, dp, split)
            + matrixMultiplication(arr, k+1, end, dp, split)
            + arr[start-1]*arr[k]*arr[end] ;

            if(dp[start][end] > cost) 
            {
                dp[start][end] = cost;
                split[start][end] = k;
            }
        }

        return dp[start][end];
    }
    
public:
    void MCM_Memoization(int N, int arr[])
    {
        int n = --N;
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        vector<vector<int>> split(n+1, vector<int>(n+1, 0));
        
        int ans = matrixMultiplication(arr, 1, n, dp, split);
        
        cout << "MCM_Memoization : " << ans << endl; ;
        cout << "Solution : " << solve(1, n, split) << endl;
    }

    void MCM_Tabulation(int N, int arr[])
    {
        int n = --N;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<vector<int>> split(n+1, vector<int>(n+1, 0));

        for(int l=2; l<=n ;l++)
        {
            for(int i=1; i<=n-l+1; i++) // j<=n ==> i+l-1 <= n
            {
                int j=i+l-1;
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++) // cut is after k, so k<j
                {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if(dp[i][j] > cost)
                    {
                        split[i][j] = k;
                        dp[i][j] = cost;
                    }
                }
            }
        }

        cout << "MCM_Tabulation : " << dp[1][n] << endl; ;
        cout << "Solution : " << solve(1, n, split) << endl;
    }
};


//{ Driver Code Starts.
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0;i < N;i++)
        cin>>arr[i];
    
    Solution ob;
    ob.MCM_Memoization(N, arr);
    ob.MCM_Tabulation(N, arr);
    return 0;
}
// } Driver Code Ends