/*
8 9
0 4
0 1
1 5
2 5
5 6
2 6
2 3
3 7
6 7

ANS : 0 4 1 5 2 6 3 7
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
  
    void bfsOfGraph(int node, int V, vector<int> adj[], vector<bool>& vis, vector<int>& ans) 
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto i : adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    void dfsOfGraph(int node, int V, vector<int> adj[], vector<bool>& vis, vector<int>& ans) 
    {
        stack<int> st;
        st.push(node);
        vis[node] = 1;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            ans.push_back(node);
            
            for(auto i : adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    st.push(i);
                }
            }
        }
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
        adj[v].push_back(u);
    }
    
    Solution obj;

    vector<int> bfs;
    vector<bool> vis(V,0);
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
            obj.bfsOfGraph(i, V, adj, vis, bfs);
    }
    cout << "BFS: ";
    for(int i = 0; i < bfs.size(); i++)
        cout << bfs[i] << " ";
    cout << endl;

    vector<int> dfs;
    for(int i=0; i<V; i++) vis[i] = 0;
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
            obj.dfsOfGraph(i, V, adj, vis, dfs);
    }
    cout << "DFS: ";
    for(int i = 0; i < dfs.size(); i++)
        cout << dfs[i] << " ";
    cout << endl;

    return 0;
}
// } Driver Code Ends