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
    private:
    void merge(int arr[], int l, int m, int r)
    {
        int i=l,j=m+1,k=0;
        int temp[r-l+1] = {0};
        
        while(i<=m && j<=r)
        {
            if(arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while(i<=m)
            temp[k++] = arr[i++];
        while(j<=r)
            temp[k++] = arr[j++];
            
        for(i=l,j=0; i<=r && j<=r-l; i++,j++)
            arr[i] = temp[j];
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        
        int mid = (r-l)/2 + l;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
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
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    
    return 0;
}
// } Driver Code Ends