/*
AGGTAB
GXTXAYB
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
private:
    string LCS(string X, string Y, vector<vector<int>> dp)
    {
        /*
        The process involves iterating backward and comparing certain strings. 
        If the strings are equal, move to the diagonal-up position; otherwise, move to the maximum value position. 
        This follows the path that led to the endpoint. 
        Continue this process until one of the strings becomes empty, reaching a solution. 
        To finalize, reverse the string as the iteration was done in reverse.
        */

        int i = X.length();
        int j = Y.length();
        string s = "";
        while(i>0 && j>0)
        {
            if(X[i-1] == Y[j-1])
            {
                s.push_back(X[i-1]);
                i--;
                j--;

            }
            else
            {
                if(dp[i-1][j] < dp[i][j-1])
                    j--;
                else
                    i--;
            }
        }

        reverse(s.begin(), s.end());
        return s;
    }


    int LCS_Helper(string p, string q, int n, int m, vector<vector<int>>& dp)
    {
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(p[n-1] == q[m-1]) 
            return dp[n][m] = 1 + LCS_Helper(p, q, n-1, m-1, dp);
        else
            return dp[n][m] = 0 + max(LCS_Helper(p, q, n-1, m, dp), LCS_Helper(p, q, n, m-1, dp)); 
    }

public:
    void LCS_Memoization(string text1, string text2) 
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        int len = LCS_Helper(text1, text2, n, m, memo);

        cout << "LCS : " << LCS(text1, text2, memo) << endl;
        cout << "LCS_Memoization : " << len << endl;
    }


    void LCS_Tabulation(string X, string Y) 
    {
        int n  = X.size();
        int m = Y.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; j++)
                if(i == 0 || j == 0) dp[i][j] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

	    cout << "LCS : " << LCS(X, Y, dp) << endl;
        cout << "LCS_Memoization : " << dp[n][m] << endl;
    }

};


//{ Driver Code Starts.
int main()
{
    string a, b;
    cin >> a >> b;
    
    Solution ob;
    ob.LCS_Memoization(a, b);
    ob.LCS_Tabulation(a, b);
    return 0;
}
// } Driver Code Ends