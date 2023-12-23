//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 
// } Driver Code Ends

class DisjointSet 
{
    vector<int> parent, size;

    public:
    DisjointSet(int n) 
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) 
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) 
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) 
    {
        parent[v] = u;
    }
};

class Solution 
{
    private:
    static bool cmp(Job a, Job b) 
    {
        return (a.profit > b.profit);
    }
    
    int findMaxDeadline(struct Job arr[], int n)
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, arr[i].dead);
        return ans;
    }

    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        
        int maxDeadline = findMaxDeadline(arr, n);
        DisjointSet ds(maxDeadline);
        
        int profit=0, jobs=0;
        for(int i = 0; i < n; i++)
        {
            int availableSlot = ds.findUPar(arr[i].dead);
            if(availableSlot > 0)
            {
                ds.unionBySize(ds.findUPar(availableSlot - 1), availableSlot);
                profit += arr[i].profit;
                jobs++;
            } 
        }
        
        return {jobs, profit};
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
// } Driver Code Ends