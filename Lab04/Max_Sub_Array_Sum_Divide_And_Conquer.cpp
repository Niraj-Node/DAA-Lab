/*

Test 0: 
9
-2 1 -3 4 -1 2 1 -5 4
Answer = 6

Test 1:
4
-2 -5 -1 -3
Answer = 0 (Minimum Subset Size is 0)
Answer = -1 (Minimum Subset Size is 1)

*/

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    int maxCrossingSum(int arr[], int l, int mid, int h) 
    {
        int sum = 0;
        int maxL = 0; // Minimum Subset Size is 0 (Empty)
        /*  
            maxL = INT_MIN for
            Minimum Subset Size ~ 1
        */
        for(int i = mid; i >= l; i--) 
        { 
            sum = sum + arr[i]; 
            if (sum > maxL) 
                maxL = sum; 
        } 
    
        sum = 0; 
        int maxR = 0; // Minimum Subset Size is 0 (Empty)
        /*  
            maxR = INT_MIN for
            Minimum Subset Size ~ 1
        */
        for(int i = mid+1; i <= h; i++) 
        { 
            sum = sum + arr[i]; 
            if(sum > maxR) 
                maxR = sum; 
        } 

        return maxL+maxR; 
    } 

    public:
    int maxSubArraySum(int arr[], int l, int h) 
    { 
        if(l == h) 
            return arr[l]; 

        int mid = (h-l)/2 + l; 
        int maxL = maxSubArraySum(arr, l, mid);
        int maxR = maxSubArraySum(arr, mid + 1, h);
        int CrossSum = maxCrossingSum(arr, l, mid, h);
        
        return max(max(maxL,maxR),CrossSum);
    } 
};


//{ Driver Code Starts.
int main()
{
    int n,i;

    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    int ans = ob.maxSubArraySum(arr, 0, n-1);
    printf("%d\n", ans);
    
    return 0;
}
// } Driver Code Ends
