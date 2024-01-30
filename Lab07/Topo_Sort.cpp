/*
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    void dfsTopoSort(int node, int V, vector<int> adj[], vector<bool>& vis, vector<int>& ans) 
    {
        vis[node] = 1;

        for(auto i : adj[node])
        {
            if(!vis[i])
                dfsTopoSort(i, V, adj, vis, ans);   
        }

        ans.push_back(node);
    }
};

//{ Driver Code Starts.
int main() 
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    Solution obj;
    vector<int> topo;
    vector<bool> vis(V,false);
    for(int i=0; i<V; i++)
        if(!vis[i])
            obj.dfsTopoSort(i, V, adj, vis, topo);

    for(int i=topo.size()-1; i>=0; i--)
        cout << topo[i] << " ";
    cout << endl;

    return 0;
}
// } Driver Code Ends
