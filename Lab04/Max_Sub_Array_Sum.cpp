//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// } Driver Code Ends

class Solution
{
public:
    int maxSubArray(int nums[], int size)
    {
        int maxSum = INT_MIN;
        int currentSlideSum = 0;

        for (int i = 0; i < size; i++)
        {
            currentSlideSum += nums[i];

            if (currentSlideSum > maxSum)
                maxSum = currentSlideSum;

            if (currentSlideSum < 0)
                currentSlideSum = 0;
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int n, i;

    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Solution ob;
    ob.maxSubArray(arr, n);
    printArray(arr, n);

    return 0;
}
// } Driver Code Ends