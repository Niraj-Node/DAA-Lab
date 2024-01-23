/*
4 7
1 2 3
2 1 8
1 4 7
2 3 2
3 4 1
3 1 5
4 1 2

ANS:
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function template for C++
class Solution {
  public:
	void shortest_distance(int V, vector<vector<int>>& dis)
    {
        for(int via=1; via<=V; via++)
        {
            for(int u=1; u<=V; u++)
            {
                for(int v=1; v<=V; v++)
                {
                    if(u==v)
                    {
                        dis[u][v] = 0;
                        dis[v][u] = 0;
                    }
                    else if(u!=via && v!=via)
                        dis[u][v] = min( dis[u][v], (dis[u][via] == INT_MAX || dis[via][v] == INT_MAX) ? INT_MAX : dis[u][via]+dis[via][v] );
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
    vector<vector<int>> matrix(V+1, vector<int>(V+1, INT_MAX));
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }

    Solution obj;
    obj.shortest_distance(V, matrix);
    cout << "ALL PAIR SHORTEST PATH:" << endl;
    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
// } Driver Code Ends