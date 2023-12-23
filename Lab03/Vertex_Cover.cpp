/* Input :
9
12
1 2
1 3
2 3
2 4
4 5
4 7
4 6
6 7
7 8
7 9
8 9
6 8
*/

#include<bits/stdc++.h>
using namespace std;

//User function Template for C++
class Solution
{
    private:
        int findMaxDegreeNode(vector<int> adj[], int n) 
        {
            int maxDegree = 0;
            int maxNode = -1;

            for(int i = 1; i < n+1; i++) 
            {
                int currentDegree = adj[i].size();
                cout << currentDegree << " ";
                if(currentDegree > maxDegree) 
                {
                    maxDegree = currentDegree;
                    maxNode = i;
                }
            }
            cout << endl;
            return maxNode;
        }

        void removeNode(vector<int> adj[], int node) 
        {
            for(auto& neighbor : adj[node]) 
            {
                auto it = find(adj[neighbor].begin(), adj[neighbor].end(), node);
                if(it != adj[neighbor].end())
                    adj[neighbor].erase(it);
            }
            adj[node].clear();
        }

    public:
        void vertexCover(int n, vector<pair<int, int>> &edges) 
        {
            vector<int> adj[n+1];
            for(auto i : edges)
            {
                adj[i.first].emplace_back(i.second);
                adj[i.second].emplace_back(i.first);
            }

            vector<int> vCover;
            while(true)
            {   
                int node = findMaxDegreeNode(adj, n);
                if(node == -1) break;
                vCover.emplace_back(node);
                removeNode(adj, node);
            }

            for(auto i : vCover)
                cout << i << " ";
        }
};

//{ Driver Code Starts.
int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    Solution s;
    s.vertexCover(n,edges);
    return 0;
}
// } Driver Code Ends