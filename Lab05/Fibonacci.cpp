//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int nthFibonacciRec(int n)
    {
        if(n <= 1) return n;

        return nthFibonacciRec(n-1) + nthFibonacciRec(n-2);
    }

    int nthFibonacciMemo(int n)
    {
        int fib[n+1];
        fib[0] = 0;
        fib[1] = 1;

        for(int i=2;i<=n;i++)
            fib[i] = fib[i-1] + fib[i-2];
        
        return fib[n];
    }

    int nthFibonacciTab(int n)
    {
        int prevPrev = 0;
        int prev = 1;

        int curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;

        for(int i=3;i<=n;i++)
        {
            curr = prev + prevPrev;
            prevPrev = prev;
            prev = curr;
        }
        
        return curr;
    }

};

//{ Driver Code Starts.
int main() {
    int n;
    cin >> n;
    Solution ob;
    cout << ob.nthFibonacciRec(n) << endl;
    cout << ob.nthFibonacciMemo(n) << endl;
    cout << ob.nthFibonacciTab(n) << endl;
    
    return 0;
}
// } Driver Code Ends