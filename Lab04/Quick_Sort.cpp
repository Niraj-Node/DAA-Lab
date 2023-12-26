//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// } Driver Code Ends

class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int pIndex = partition(arr,low,high);
            quickSort(arr,low,pIndex-1);
            quickSort(arr,pIndex+1,high);
        }
    }
    
    public:
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low;
        int j = low;
       
        while(j<=high)
        {   
            if(arr[j]<=pivot)
            {
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
        return i-1;
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
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}
// } Driver Code Ends